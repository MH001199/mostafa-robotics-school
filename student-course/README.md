# Start the Robotics School

[School home](../README.md) · [Photo references](photo-credits.md)

This course starts with an empty breadboard and ends with a small system that senses light, temperature, humidity and distance. Each project states what to build, shows the wiring and sketch, tells you what to observe, and gives you a challenge. Follow **Next** at the end of each project.

The core path uses one kit: **Arduino Uno R3, DHT11, L298N, LDR and HC-SR04**. Use the pin map and sketch from the same lesson.

## Follow the course in order

| Stage | Start here | Checkpoint before you continue |
| --- | --- | --- |
| Section 00 · Foundations | [Start Section 00](../Class-01-Arduino-Fundamentals/00-Introduction/README.md) | Identify the Uno pins and breadboard groups, then upload the serial connection test |
| Class 1 · First project | [Built-in Blink](02-leds-and-sound.md#builtin_blink) | Predict, upload and time the onboard LED |
| Class 1 · Build outputs | [Build with LEDs and buzzers](02-leds-and-sound.md) | Build a traffic light, change a timing pattern and play an original piezo melody |
| Class 2 · Read sensors | [Read inputs and make decisions](03-inputs-light-and-climate.md) | Measure light and room conditions, choose thresholds and combine two sensors |
| Class 2 · Distance and motion | [Measure distance and drive a motor](04-distance-and-motors.md) | Test ranging and motor power separately before adding automation |
| Class 2 · Capstone | [Build the smart-home capstone](05-smart-home.md) | Demonstrate lamp, proximity alarm and fan behavior, including a climate sensor fault |
| Class 3 · Planned | [Choose a project after Class 3](06-project-paths.md) | Use the foundations to choose a robotics or embedded systems project |

## Gather parts as you go

| When | What you need |
| --- | --- |
| First upload | Arduino Uno R3, USB data cable, computer with Arduino IDE 2 and the Arduino AVR Boards package |
| LEDs and sound | Breadboard, jumpers, red/yellow/green indicator LEDs, 220 Ω or 330 Ω LED resistors, a 5 V active-high buzzer module with an onboard driver, high-impedance passive piezo rated for 5 V and a 330 Ω series resistor |
| Sensors | Bare LDR, 10 kΩ divider resistor, DHT11 and a 10 kΩ pull-up for the bare sensor, HC-SR04 5 V module, ruler and flat target |
| Motor and capstone | Documented L298N breakout with flyback diodes and heatsink, small brushed motor, separate current-limited motor supply, and a safe way to secure the motor with its shaft bare |

## Build and check one change at a time

1. Read the goal and identify each part. With USB and external power disconnected, wire the circuit and check the connections.
2. Download the repository from **Code → Download ZIP** on GitHub to keep each sketch in its matching folder. Open the linked `.ino` in Arduino IDE, select **Arduino Uno** and the correct port, then Verify and Upload.
3. Compare the result with the lesson. Record your measurements or observations before changing the code. If the result differs, return to the last circuit that worked and check one connection at a time.
4. Complete the challenge. Save your pin map, a photo of your own build and what you changed, then follow **Next**.

Use a series resistor for every indicator LED and keep the Uno's signal pins within its 5 V logic range. With two supplies, share the ground reference and route motor power through its driver. Match the motor supply to the rated motor and the specific driver module. Keep the shaft bare and use these circuits only as low-voltage classroom prototypes.

## Your completion checklist

- [ ] Complete the Section 00 pin and breadboard checks and record two serial ticks.
- [ ] Complete the Class 1 projects and explain the timing in one of your builds.
- [ ] Complete the Class 2 projects and record all four Smart Home outcomes.
- [ ] Publish a short build record and choose a planned Class 3 path.

Try an [optional Wokwi template](../simulations/README.md) if you are still waiting for hardware. Read the [spoiler-marked solution hints](../resources/solutions.md) after you have tried the selected exercises.

**Start here** · [Section 00](../Class-01-Arduino-Fundamentals/00-Introduction/README.md).

## Optional Hardware Variations

[Use the DHT22/TB6612FNG variation](../resources/hardware-variations.md) when your kit differs. Keep each variation’s wiring and code together.
