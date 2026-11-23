# Mostafa's Robotics School

A beginner path into robotics and embedded systems. Start with a single LED, build a controller that can sense and act, then use those skills to choose a project track.

**Start here → [Full student course](student-course/README.md).** Follow the Class 1 and 2 projects in order, from getting the Uno ready to the smart-home capstone. This route uses the DHT11 and L298N from the course handbook.

## If you have the DHT22 and TB6612FNG kit

Use the lessons below as a continuous route with their own wiring and sketches. Both kits use the 5 V Arduino Uno R3 and lead to the same Class 3 roadmap.

| Step | What you will build | Milestone |
| --- | --- | --- |
| [Class 1 · Arduino fundamentals](class-1/README.md) | Blink, breadboard LED, traffic lights, piezo and an original melody | Wire and program several outputs independently |
| [Class 2 · Sensors and smart systems](class-2/README.md) | PWM dimmer, night light, climate alarm, proximity buzzer, motor control, and smart home | Integrate sensing and actuation, and verify each subsystem |
| [Class 3 · Advanced foundations (planned)](class-3/README.md) | Timing, communication buses, motor selection, and control | Choose a robotics or embedded systems track |

**Start the DHT22 and TB6612FNG route** → [Arduino, IDE and Blink](class-1/01-arduino-and-blink/README.md)

## Hardware and setup

The lessons target the **5 V Arduino Uno R3 (ATmega328P)**. Use the specified board to keep logic levels and pin mappings consistent. Open the sketch from its named folder in Arduino IDE, select **Arduino Uno**, then Verify before uploading. Every lesson lists its own wiring and checks.

| When | Parts |
| --- | --- |
| Class 1 | Uno R3 and USB data cable, solderless breadboard, jumpers, red/yellow/green indicator LEDs, at least three 330 Ω resistors, 5 V-compatible high-impedance passive piezo |
| Class 2 additions | Normally open pushbutton, 10 kΩ linear potentiometer, bare LDR, at least three 10 kΩ resistors, DHT22, 5 V HC-SR04, TB6612FNG breakout with bypass capacitors, 6 V brushed motor specified at ≤500 mA stall current at 6 V, regulated current-limited 6 V supply |

Unplug USB and turn off external power before changing any circuit. Use a series resistor for every external LED, keep signal voltages within the Uno's GND–5 V range, and connect grounds where a circuit uses two supplies. Power the motor from the dedicated supply through the driver. The projects use low-voltage bench circuits only.

## Share a build

For a wiring fix, open a GitHub issue with your lesson, board, wiring, and the observed result. For a curriculum improvement or a reproducible student project, submit a pull request with a purpose, parts list, pin map, sketch, expected behavior, test results, and any hardware limits. Include a clear photo or diagram when it helps somebody repeat the build.

See [sketch verification](VALIDATION.md) for build commands and the scope of testing.
