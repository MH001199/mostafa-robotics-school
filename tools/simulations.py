"""Generate Wokwi diagram files alongside the existing Uno R3 sketches."""
from pathlib import Path
import argparse
import json
import shutil

ROOT = Path(__file__).resolve().parents[1]
SKETCHES = ROOT / "student-course" / "sketches"
UNO = {"type": "wokwi-arduino-uno", "id": "uno", "top": 70, "left": -150, "attrs": {}}
PINS = {
    "wokwi-arduino-uno": {str(i) for i in range(14)} | {"A0", "5V", "GND.1"},
    "wokwi-led": {"A", "C"},
    "wokwi-resistor": {"1", "2"},
    "wokwi-photoresistor-sensor": {"VCC", "GND", "AO"},
    "wokwi-hc-sr04": {"VCC", "GND", "TRIG", "ECHO"},
}


def component(kind, name, x, y, **attrs):
    return {"type": kind, "id": name, "left": x, "top": y, "attrs": attrs}


def connection(start, end, color):
    return [start, end, color, []]


def indicators(pins):
    components, connections = [], []
    for i, (pin, color) in enumerate(pins):
        suffix = str(i + 1)
        led, resistor = "led" + suffix, "r" + suffix
        components.extend([
            component("wokwi-resistor", resistor, 260, 30 + i * 110, value="220"),
            component("wokwi-led", led, 500, 30 + i * 110, color=color),
        ])
        connections.extend([
            connection(f"uno:{pin}", f"{resistor}:1", color),
            connection(f"{resistor}:2", f"{led}:A", color),
            connection(f"{led}:C", "uno:GND.1", "black"),
        ])
    return components, connections


TEMPLATES = {
    "builtin_blink": ([], []),
    "external_led": indicators([(13, "red")]),
    "traffic_light": indicators([(8, "red"), (9, "yellow"), (10, "green")]),
    "pwm_fade": indicators([(6, "red")]),
    "ldr_reading": (
        [component("wokwi-photoresistor-sensor", "light", 320, 90, lux="500")],
        [connection("uno:5V", "light:VCC", "red"),
         connection("uno:GND.1", "light:GND", "black"),
         connection("light:AO", "uno:A0", "green")],
    ),
    "ultrasonic_reading": (
        [component("wokwi-hc-sr04", "ranger", 320, 90, distance="20")],
        [connection("uno:5V", "ranger:VCC", "red"),
         connection("uno:GND.1", "ranger:GND", "black"),
         connection("uno:7", "ranger:TRIG", "green"),
         connection("ranger:ECHO", "uno:8", "blue")],
    ),
}


def verify(name, parts, connections):
    model = {p["id"]: p["type"] for p in parts}
    if len(model) != len(parts):
        raise ValueError(f"{name}: duplicate component ID")
    for start, end, _, _ in connections:
        for endpoint in (start, end):
            part, pin = endpoint.split(":", 1)
            if part not in model or pin not in PINS[model[part]]:
                raise ValueError(f"{name}: unknown endpoint {endpoint}")
    if not (SKETCHES / name / f"{name}.ino").is_file():
        raise FileNotFoundError(f"Canonical sketch is missing: {name}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="validate without writing files")
    parser.add_argument("--output", type=Path, default=ROOT / "simulation-build")
    args = parser.parse_args()
    for name, (extras, connections) in TEMPLATES.items():
        parts = [UNO, *extras]
        verify(name, parts, connections)
        if args.check:
            continue
        destination = args.output / name
        destination.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(SKETCHES / name / f"{name}.ino", destination / "sketch.ino")
        diagram = {"version": 1, "author": "Mostafa's Robotics School", "editor": "wokwi",
                   "parts": parts, "connections": connections, "dependencies": {}}
        (destination / "diagram.json").write_text(json.dumps(diagram, indent=2) + "\n",
                                                 encoding="utf-8")
    print(f"Checked {len(TEMPLATES)} Wokwi templates. Simulator execution was not performed.")


if __name__ == "__main__":
    main()
