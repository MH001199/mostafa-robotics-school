# Troubleshooting Guide

[Start Learning](../student-course/README.md) · [Components](components.md)

Start with the last build that worked. Write down what you expected, what happened, and one change to test. Disconnect USB and external power before moving a wire or using continuity mode.

| Symptom | First check | Evidence to record |
| --- | --- | --- |
| Board powers up but no port | Try a data cable and reconnect. Observe which port appears. | Board model and port before and after reconnecting |
| Verify fails | Read the first error. Check the board platform and required libraries. | First compiler error and selected board |
| Upload fails | Match the board and port, then close any other serial monitor. | Upload error and USB cable tested |
| Serial output is unreadable | Match the sketch’s baud rate. Reset to replay its startup output. | A short copy of the output |
| LED never lights | Trace the series resistor, polarity, separate breadboard nodes, and GND. | Sketch pin and physical pin label |
| Analog value sticks or trends backward | Check the two ends and the midpoint of the divider. Measure at two light levels. | Two readings with the conditions |
| Sensor always reports an error | Confirm its exact model, pin order, supply, ground, and timing. | Two valid or error lines with units |
| Motor buzzes, stops or resets the Uno | Turn off motor power. Check the driver variant, common ground, shaft clearance and rated supply. | Driver, supply and motor ratings, and behavior with the shaft bare |

Use the matching sketch’s notes for pin-level checks. The [capstone test procedures](../VALIDATION.md) show how to isolate one subsystem.
