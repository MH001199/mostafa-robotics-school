# PWM LED dimmer

[School roadmap](../../README.md) · [Class 2](../README.md)

> **Optional hardware variation.** Follow this page with its own sketch and pin map. [Section 00](../../Class-01-Arduino-Fundamentals/00-Introduction/README.md) applies to both kits.

### Learning Objectives

Prerequisite: complete Section 00 and the previous linked lesson. In this lesson, explain and demonstrate knob-controlled lighting.

### Predict

Predict duty at both ends and around halfway. Before uploading, record the expected outcome and the reason or line of code for your prediction.

| Condition or input | Prediction | Evidence in code | Observation after Run |
| --- | --- | --- | --- |
| First test | | | |
| Second test | | | |

### See the components and circuit

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Component-Red-LED.jpg"><img src="../../lesson-visuals/Electronic-Component-Red-LED.jpg" width="260" alt="Two-lead through-hole red LED"></a>

*Two-lead through-hole red LED · Evan-Amos · Public domain.*

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Axial-Lead-Resistors-Array.jpg"><img src="../../lesson-visuals/Electronic-Axial-Lead-Resistors-Array.jpg" width="260" alt="Axial resistors with colored bands"></a>

*Axial resistors with colored bands · Evan-Amos · Public domain.*

Use the resistance specified in the wiring table. Verify unfamiliar color bands with a multimeter before wiring.

![Wiring diagram for PWM LED dimmer](../../lesson-visuals/alternate-pwm_dimmer.svg)

Connection map for PWM LED dimmer on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node.

[Wiring diagram](../../lesson-visuals/alternate-pwm_dimmer.svg) · [Arduino sketch](pwm_dimmer/pwm_dimmer.ino) · [Detailed notes and engineering questions](pwm_dimmer/NOTES.md)

### Run

Using the matching sketch above, select **Arduino Uno**, Verify, then Upload. Check for this behavior: Brightness follows the knob from dark to bright

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Keep the potentiometer wired as in [Digital and analog I/O](../01-digital-analog-io/README.md). Add one indicator LED with a 330 Ω series resistor.

```text
5V ── potentiometer outer legs ── GND
                     wiper ────── A0

D5 (~) ── 330 Ω ── LED anode → cathode ── GND
```

Upload and sweep the knob. `map()` converts the analog input range of 0–1023 to a duty command of 0–255. The output pulses between LOW and HIGH. Higher duty means it spends more time HIGH, making the LED appear brighter. Compare 0, about 128, and 255. PWM on the Uno R3 is available on pins 3, 5, 6, 9, 10, and 11, marked with a tilde on the board.

**Try it.** Temporarily replace the mapped duty with 64, then 192. Predict the approximate duty percentages and compare visually.

**If it fails.** Check D5 and LED polarity. A non-PWM digital output can switch abruptly instead of dimming. Unstable brightness can come from a loose wiper wire.

[Arduino analogWrite reference](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/)


### Investigate

Trace one input or timing value from the source to an output. Use the [matching code walkthrough](pwm_dimmer/NOTES.md) to check your explanation and the pin map. Write one thing your observation confirms and one thing you still need to measure.

### Modify

Try a fixed duty of 64 and then 192 and compare.

### Make

Change the mapping to make low-light adjustments easier. Define what success will look like and keep the circuit within its original ratings.

### Troubleshoot

Use the symptom-specific checks in the [sketch notes](pwm_dimmer/NOTES.md#common-errors-and-troubleshooting). If the kit differs, check the parts and sketch together before moving any wires. Change one variable at a time.

### Knowledge Check

1. What does the wiper feed?
2. What range does the ADC report?
3. How would you isolate a loose ground?

You should be able to explain the signal or timing, identify the line that controls it, and justify a troubleshooting measurement.

### Practical Checkpoint

Demonstrate the expected behavior above. Capture one timed, measured, or serial observation, and explain which line or connection caused it.

### Continue Learning

Previous · [Digital and analog I/O](../../class-2/01-digital-analog-io/README.md)

Next · [LDR voltage divider and night light](../../class-2/03-ldr-night-light/README.md)
