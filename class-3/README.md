# Class 3 · Advanced robotics foundations

[School roadmap](../README.md) · [Class 2](../class-2/README.md)

**Planned curriculum.** Start after you can explain how the smart home reads a sensor, times two tasks, and powers the motor safely.

| Topic | What you will learn |
| --- | --- |
| Timing and state | Use `millis()`, finite-state machines, and sampling intervals to keep independent tasks responsive |
| Communication | Pick UART, I²C, or SPI based on wiring, addressing, timing, and device requirements |
| Motors and feedback | Compare brushed DC motors, servos and steppers. Read encoders and match drivers and supplies to loads |
| Control | Distinguish open- and closed-loop control. Understand calibration, noise and feedback before tuning a controller |
| Debugging | Use serial logs, a multimeter and basic timing measurements to test one subsystem at a time |

## Choose a track

| Track | Project progression |
| --- | --- |
| Mobile robotics | Start with an RC rover, add wheel encoders, then practice regulating speed |
| Robot arms | Control one servo, add joints and limits, then plan simple motion within the workspace |
| Self-balancing robot | Begin with bench IMU readings and wheel speed, then study angle estimation and constrained feedback tests before free balancing |
| Embedded systems | Start with a serial sensor logger, add a bus peripheral and error handling, then explore interrupts, watchdogs and low-power operation |

Use the same build record from Class 2 in each track so others can reproduce the project.
