# Breadboard LED

[School roadmap](../../README.md) · [Class 1](../README.md)

[Open the sketch](breadboard_led/breadboard_led.ino)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Use a breadboard, one standard indicator LED, one 330 Ω resistor, and jumpers. In a typical solderless breadboard, each strip of five holes is connected within one side of the center gap. Power rails can break in the middle. Check with continuity mode while power is disconnected.

```text
D8 ── 330 Ω ── LED anode (+) → LED cathode (−) ── GND
```

Put the LED legs in separate electrical rows. Run D8 to one resistor lead. Join the other resistor lead to the anode row, then connect the cathode row to Arduino GND. The longer leg is usually the anode and the flat rim usually marks the cathode. Verify against the part if its legs have been trimmed. The resistor can go on either side of the LED in series. For a red LED with about 2 V forward drop, current is roughly (5 − 2) / 330 ≈ 9 mA.

Upload and check for 750 ms on and 250 ms off. Trace the complete current path while the pin is HIGH.

**Try it.** Predict the brightness change with 1 kΩ in place of 330 Ω. Power down before swapping the resistor, then compare.

**If it fails.** Power off and check polarity, rail continuity, separate LED rows, and the D8 jumper. An LED directly across D8 and GND needs its series resistor before power is restored.

Previous · [Arduino, IDE and Blink](../../class-1/01-arduino-and-blink/README.md)

Next · [Traffic light model](../../class-1/03-traffic-lights/README.md)
