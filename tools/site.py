"""Verify and stage the one repository curriculum for Material for MkDocs."""
from collections import Counter
from pathlib import Path
from tempfile import TemporaryDirectory
from urllib.parse import unquote, urlsplit
import os
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
TREES = (
    "student-course", "Class-01-Arduino-Fundamentals", "class-1", "class-2",
    "class-3", "resources", "lesson-visuals", "simulations",
)
ROOT_FILES = ("README.md", "IMAGE-SOURCES.md", "VALIDATION.md", "CONTRIBUTING.md",
              "CODE_OF_CONDUCT.md", "LICENSE", "LICENSE.md")
SOURCE_EXTENSIONS = {".md", ".ino", ".svg", ".jpg", ".jpeg", ".png", ".json"}
MARKDOWN_LINK = re.compile(r"(!?)\[([^\]\n]*)\]\(([^)\n]+)\)")
HTML_IMAGE = re.compile(r"<img\b[^>]*>", re.I)
HTML_ID = re.compile(r'<a id="([^"]+)"')
HEADING = re.compile(r"^#{1,6}\s+(.+?)\s*$", re.M)
FENCE = re.compile(r"^([\x60~]{3,})[^\n]*\n.*?^\1\s*$", re.M | re.S)
PROJECT_ID = re.compile(r'^<a id="([a-z0-9_]+)"></a>$', re.M)
CORE_PAGES = ("02-leds-and-sound", "03-inputs-light-and-climate",
              "04-distance-and-motors", "05-smart-home")
PRIMM = ("Predict", "Run", "Investigate", "Modify", "Make")


def source_files():
    for name in ROOT_FILES:
        yield ROOT / name
    for tree in TREES:
        yield from (p for p in (ROOT / tree).rglob("*")
                    if p.is_file() and p.suffix.lower() in SOURCE_EXTENSIONS)


def links(content):
    content = FENCE.sub("", content)
    for image, label, target in MARKDOWN_LINK.findall(content):
        yield bool(image), label, target.strip("<>")
    for tag in HTML_IMAGE.findall(content):
        attrs = dict(re.findall(r'([-\w]+)="([^"]*)"', tag))
        yield True, attrs.get("alt", ""), attrs.get("src", "")


def heading_ids(content):
    ids = set(HTML_ID.findall(content))
    counts = Counter()
    for heading in HEADING.findall(FENCE.sub("", content)):
        base = re.sub(r"[^\w -]", "", heading.lower()).replace(" ", "-")
        count = counts[base]
        ids.add(base if count == 0 else f"{base}-{count}")
        counts[base] += 1
    return ids


def check(paths):
    errors = []
    documents = {p: p.read_text(encoding="utf-8-sig") for p in paths if p.suffix == ".md"}
    sections = {p: heading_ids(text) for p, text in documents.items()}
    for page, content in documents.items():
        duplicates = [key for key, count in Counter(HTML_ID.findall(content)).items() if count > 1]
        if duplicates:
            errors.append(f"{page.relative_to(ROOT)}: duplicate explicit anchors {duplicates}")
        for image, label, href in links(content):
            if image and not label.strip():
                errors.append(f"{page.relative_to(ROOT)}: missing image alt text ({href})")
            url = urlsplit(href)
            if url.scheme or url.netloc:
                continue
            target = ((page.parent / unquote(url.path)).resolve() if url.path else page)
            if not target.is_relative_to(ROOT) or not target.exists():
                errors.append(f"{page.relative_to(ROOT)}: missing target {href}")
            elif url.fragment and target in sections and unquote(url.fragment) not in sections[target]:
                errors.append(f"{page.relative_to(ROOT)}: missing section {href}")
    sketches = [p for p in paths if p.suffix == ".ino"]
    for sketch in sketches:
        note = sketch.with_name("NOTES.md")
        if sketch.stem != sketch.parent.name:
            errors.append(f"{sketch.relative_to(ROOT)}: folder must match sketch name")
        if note not in documents or "## Think Like an Engineer" not in documents[note]:
            errors.append(f"{sketch.relative_to(ROOT)}: missing NOTES.md or engineering exercise")
    projects = {}
    for name in CORE_PAGES:
        page = ROOT / "student-course" / (name + ".md")
        segments = PROJECT_ID.split(documents[page])
        for key, segment in zip(segments[1::2], segments[2::2]):
            if not key or key in projects:
                errors.append(f"Duplicate core project anchor: {key}")
            projects[key] = segment
    variations = {str(page.relative_to(ROOT)): content for page, content in documents.items()
                  if page.parts[-3] in ("class-1", "class-2") and page.name == "README.md"}
    for name, segment in (projects | variations).items():
        offsets = [segment.find("### " + step + "\n") for step in PRIMM]
        if any(i < 0 for i in offsets) or offsets != sorted(offsets):
            errors.append(f"{name}: missing or misordered PRIMM steps")
        if "### Continue Learning" not in segment or "NOTES.md" not in segment:
            errors.append(f"{name}: missing project navigation or sketch notes link")
    start = documents[ROOT / "student-course/README.md"]
    if start.find("00-Introduction/README.md") > start.find("#builtin_blink"):
        errors.append("Section 00 must precede the first Blink link")
    if errors:
        raise SystemExit("\n".join(errors))
    print(f"Checked {len(documents)} Markdown pages, {len(sketches)} sketch notes, "
          f"{len(projects)} core projects, and {len(variations)} optional lessons.")


def stage(paths, destination):
    # Avoid a file/directory collision with the page generated from LICENSE.md.
    renamed = {destination / "README.md": "index.md",
               destination / "LICENSE": "LICENSE.txt"}
    for source in paths:
        relative = source.relative_to(ROOT)
        out = destination / relative
        if out in renamed:
            out = out.with_name(renamed[out])
        out.parent.mkdir(parents=True, exist_ok=True)
        if source.suffix != ".md":
            out.write_bytes(source.read_bytes())
            continue
        text = source.read_text(encoding="utf-8-sig")
        # Turn attributed HTML thumbnails into Markdown assets so MkDocs resolves
        # paths relative to generated pages. The next line keeps the attribution.
        text = re.sub(r'<a href="[^"]+"><img src="([^"]+)" width="\d+" alt="([^"]+)"></a>',
                      r"![\2](\1)", text)
        if source.name == "NOTES.md":
            sketch_link = re.search(r"\]\(([^)\n]+\.ino)\)", text)
            if sketch_link:
                sketch = (source.parent / sketch_link.group(1)).read_text(encoding="utf-8")
                text += "\n\n## Copy the Arduino Sketch\n\n" + chr(96) * 3 + "cpp\n" + sketch.strip()
                text += "\n" + chr(96) * 3 + "\n"
        if source.name == "IMAGE-SOURCES.md":
            text = text.replace("[lesson-visuals](lesson-visuals/)", "the lesson-visuals directory")
        out.write_text(text, encoding="utf-8")
    for markdown in destination.rglob("*.md"):
        text = markdown.read_text(encoding="utf-8")

        def root_links(match):
            href = match[3]
            url = urlsplit(href)
            if url.scheme or url.netloc or not url.path:
                return match[0]
            source_target = (markdown.parent / unquote(url.path)).resolve()
            if source_target not in renamed:
                return match[0]
            return match[0].replace(href, href.replace(source_target.name, renamed[source_target], 1))

        markdown.write_text(MARKDOWN_LINK.sub(root_links, text), encoding="utf-8")


def main():
    command = sys.argv[1] if len(sys.argv) == 2 else "check"
    if command not in ("check", "build", "serve"):
        raise SystemExit("Usage: python tools/site.py [check|build|serve]")
    paths = list(source_files())
    check(paths)
    if command == "check":
        return
    with TemporaryDirectory(prefix=".school-site-", dir=ROOT) as folder:
        stage(paths, Path(folder).resolve())
        env = os.environ | {"SCHOOL_DOCS_DIR": folder}
        args = [sys.executable, "-m", "mkdocs", command]
        if command == "build":
            args += ["--strict"]
        subprocess.run(args, cwd=ROOT, env=env, check=True)


if __name__ == "__main__":
    main()
