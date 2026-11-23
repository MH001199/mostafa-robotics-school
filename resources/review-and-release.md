# Review and Release

## Repository audit before this upgrade

| Requirement | Baseline status | Existing files or dependency |
| --- | --- | --- |
| Sketches and code notes | Implemented | 31 matching sketch folders across the main curriculum and variation |
| Course path | Partial | `student-course/README.md` listed both hardware routes and put breadboards after Blink |
| Section 00 | Partial | `Class-01-Arduino-Fundamentals/00-Introduction/README.md` focused on breadboards. Original numbered Uno and IDE images were unavailable |
| Critical thinking and PRIMM | Partial | Notes contained engineering questions and challenges. Most project pages lacked the complete five-step method and checks |
| Visuals and sources | Implemented with gaps | `lesson-visuals/` and `IMAGE-SOURCES.md` held original diagrams, credited photos and links. Some exact module photographs were link-only |
| Website and simulation | Missing | No MkDocs configuration, Pages workflow, or maintained simulation templates |
| Automated verification | Missing | `VALIDATION.md` documented build commands and manual checks |
| Community | Partial | Root guidance invited issues and PRs. Issue forms, conduct, license and category setup were missing |
| Class 3 specialization | Partial | `class-3/README.md` described planned foundations and general tracks |

## Structure and review order

PR [#1](https://github.com/MH001199/mostafa-robotics-school/pull/1) adds the curriculum to `main`. PR [#2](https://github.com/MH001199/mostafa-robotics-school/pull/2) adds the visual lessons over PR #1. This upgrade starts at PR #2 and should be reviewed as its own diff. Review and integrate #1, then #2, then this upgrade. If an intermediate feature branch will be deleted or squash-merged, retarget the next PR and refresh its comparison before merging.

The root README and `student-course/` remain the main learning path. `Class-01-Arduino-Fundamentals/00-Introduction/` holds the expanded introduction and preserves the breadboard material as its own chapter. The existing sketch and lesson paths stay in place. `class-1/` and `class-2/` remain accessible through Optional Hardware Variations. `resources/`, `simulations/` and the GitHub workflows add supporting material. The website reads these Markdown files at build time and stages a temporary copy. There is no separately maintained website curriculum.

## Deploy to GitHub Pages

1. After review and approved merges, open the repository’s **Settings → Pages**.
2. Under **Build and deployment**, set **Source** to **GitHub Actions**.
3. Open **Actions → Curriculum verification and Pages**. Run the workflow manually on `main` if no eligible push occurs after Pages is configured.
4. Wait for the Pages deployment job to succeed, open the URL it reports, then verify the landing page, search, Section 00, and a sketch download.

PRs build for review. Deployment is restricted to `main` after the checks pass. Treat the site as unpublished until GitHub reports a successful deployment and its URL opens. [GitHub Pages configuration](https://docs.github.com/en/pages/getting-started-with-github-pages/configuring-a-publishing-source-for-your-github-pages-site)

## Outstanding source assets

Section 00 preserves the requested numbering for the original Uno photo and IDE screenshot. Add the original files with attribution when they are available. The official Arduino resources are clearly labeled references. No unrelated numbered image was substituted.
