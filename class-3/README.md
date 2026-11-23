# Class 3 · Advanced robotics foundations

[School roadmap](../README.md) · [Full course capstone](../student-course/05-smart-home.md) · [DHT22 and TB6612FNG Class 2](../class-2/README.md)

**Planned curriculum.** Start after you can explain how the smart home reads a sensor, times two tasks, and powers the motor safely.

| Topic | What you will learn |
| --- | --- |
| Timing and state | Use `millis()`, finite-state machines, and sampling intervals to keep independent tasks responsive |
| Communication | Pick UART, I²C, or SPI based on wiring, addressing, timing, and device requirements |
| Motors and feedback | Compare brushed DC motors, servos and steppers. Read encoders and match drivers and supplies to loads |
| Control | Distinguish open- and closed-loop control. Understand calibration, noise and feedback before tuning a controller |
| Debugging | Use serial logs, a multimeter and basic timing measurements to test one subsystem at a time |

## Choose a track

| Planned track | Prerequisites to demonstrate | First project direction |
| --- | --- | --- |
| Bluetooth RC Cars and Mobile Robotics | H-bridge power, PWM, safe stop, and UART communication | Begin with a rover on a stand, then add command timeouts and encoders |
| Robotic Arms | Servo control, current budgeting, joint limits, and coordinate frames | Control one joint, then measure reachable positions before adding joints |
| Self-Balancing Robots | IMU calibration, fixed-rate sampling, basic feedback, and motor safety | Record angle and wheel-speed data on a restrained bench setup before any free balancing |
| Autonomous Robotics | Sensor validity, state machines, motor stop behavior, and basic position estimates | Build a rover that stops on invalid readings, then add a simple navigation state machine |
| Embedded Systems and IoT | UART and I²C, timed sampling, fault handling, and basic network and data privacy concepts | Start with a local sensor logger, then add a read-only dashboard |

Use the same build record from Class 2 in each track so others can reproduce the project. See the [expanded project paths](../student-course/06-project-paths.md) for starter project examples and additional topics.
