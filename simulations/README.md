# Optional Wokwi Simulations

[Start Learning](../student-course/README.md)

The following templates are an optional way to study the program without parts. Their diagram endpoints and source paths are checked. **Simulator execution is pending.** The physical lesson remains the wiring reference.

| Template name | Physical lesson | What to look for |
| --- | --- | --- |
| `builtin_blink` | [Built-in LED](../student-course/02-leds-and-sound.md#builtin_blink) | L LED on and off for 500 ms each |
| `external_led` | [External LED](../student-course/02-leds-and-sound.md#external_led) | D13 drives the external LED through 220 Ω |
| `traffic_light` | [Traffic light](../student-course/02-leds-and-sound.md#traffic_light) | D8, D10, then D9 light in sequence |
| `pwm_fade` | [PWM fade](../student-course/03-inputs-light-and-climate.md#pwm_fade) | D6 brightness ramps up and down |
| `ldr_reading` | [Light sensing](../student-course/03-inputs-light-and-climate.md#ldr_reading) | Change virtual lux and watch the A0 reading at 9600 baud |
| `ultrasonic_reading` | [Ultrasonic measurement](../student-course/04-distance-and-motors.md#ultrasonic_reading) | Change the virtual target distance and compare it with Serial Monitor |

Download the repository and run `python tools/simulations.py` from its root. Open an [Arduino Uno project in Wokwi](https://wokwi.com/projects/new/arduino-uno). In the corresponding folder under `simulation-build/`, copy `sketch.ino` and `diagram.json` into the matching editor tabs. Run and record the result in the lesson’s prediction worksheet. The generator copies the original sketches, so changes to a lesson are reflected when regenerated.

The simulated [photoresistor module](https://docs.wokwi.com/parts/wokwi-photoresistor-sensor) has an integrated divider and its AO output falls as light increases. The lesson’s bare LDR divider is wired in the opposite orientation. Use this template for the raw ADC sketch only. The HC-SR04 simulation controls an idealized distance. It does not reproduce weak or angled echoes, wiring faults, or supply limits. Motor and complete capstone simulations are unavailable for this release.

[Wokwi diagram format](https://docs.wokwi.com/diagram-format) · [Wokwi Arduino Uno pin names](https://docs.wokwi.com/parts/wokwi-arduino-uno)
