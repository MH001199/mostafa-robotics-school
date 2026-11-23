# LDR voltage divider and night light

[School roadmap](../../README.md) · [Class 2](../README.md)

### See the components and circuit

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Component-Red-LED.jpg"><img src="../../lesson-visuals/Electronic-Component-Red-LED.jpg" width="260" alt="Two-lead through-hole red LED"></a>

*Two-lead through-hole red LED · Evan-Amos · Public domain.*

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Axial-Lead-Resistors-Array.jpg"><img src="../../lesson-visuals/Electronic-Axial-Lead-Resistors-Array.jpg" width="260" alt="Axial resistors with colored bands"></a>

*Axial resistors with colored bands · Evan-Amos · Public domain.*

Use the resistance specified in the wiring table. Verify unfamiliar color bands with a multimeter before wiring.

![Wiring diagram for LDR night light](../../lesson-visuals/alternate-ldr_night_light.svg)

Connection map for LDR night light on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node.

[Wiring diagram](../../lesson-visuals/alternate-ldr_night_light.svg) · [Arduino sketch](ldr_night_light/ldr_night_light.ino) · [Detailed notes and engineering questions](ldr_night_light/NOTES.md)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Use a loose two-lead photoresistor (LDR), a 10 kΩ resistor, an LED, and a 330 Ω resistor. Remove the potentiometer from A0.

```text
5V ─── LDR ───●─── 10 kΩ ─── GND
              └─── A0

D8 ── 330 Ω ── LED anode → cathode ── GND
```

The LDR resistance drops with more light. With the LDR at the top of this divider, the junction voltage rises as it gets brighter. The junction voltage is approximately `5 V × 10 kΩ / (LDR resistance + 10 kΩ)`. The ADC turns that voltage into a number.

At **9600 baud**, record the dark and bright values with the light in its intended position. Adjust `DARK_ON` and `BRIGHT_OFF` to sit between those readings with `DARK_ON < BRIGHT_OFF`. The `if` switches on the LED in darkness and the `else if` switches it off in brightness. Between thresholds the sketch retains the old state. This dead band is hysteresis.

**Try it.** Collect six readings in each lighting condition. Choose thresholds and demonstrate that brief variations inside the band leave the LED unchanged.

**If it fails.** If covering the sensor raises the reading, check the order of the LDR and fixed resistor. If numbers stay fixed, make sure A0 shares only the divider's midpoint and that both rails reach the Uno. Move the lamp LED away from the LDR if it causes feedback.

Previous · [PWM LED dimmer](../../class-2/02-pwm-dimmer/README.md)

Next · [DHT22 temperature and humidity alarm](../../class-2/04-dht-alarm/README.md)
