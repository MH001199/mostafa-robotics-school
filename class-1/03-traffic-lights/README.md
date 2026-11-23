# Traffic light model

[School roadmap](../../README.md) · [Class 1](../README.md)

[Open the sketch](traffic_lights/traffic_lights.ino)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Use red, yellow, and green LEDs, three 330 Ω resistors, and a common ground rail. Give each LED its own series resistor. All cathodes connect to the rail, and the rail connects to Uno GND.

```text
D8  ── 330 Ω ── red LED    ──┐
D9  ── 330 Ω ── yellow LED ──┼── Uno GND
D10 ── 330 Ω ── green LED  ──┘
          Current enters each LED's anode.
```

Upload and time the phases. Red lasts 3 s, green lasts 3 s, and yellow lasts 1 s before the cycle repeats. The helper `showLight()` turns every output off before it enables the requested color. Its two inputs select the pin and the phase length.

**Try it.** Write the phases in a table with pin and duration, then add two brief yellow flashes before returning to red. Verify that only one color is ever lit.

**If it fails.** If a color is wrong, trace its wire back to the pin labels. If two LEDs light together, look for an accidental shared anode row or a missing LOW write.

Previous · [Breadboard LED](../../class-1/02-breadboard-led/README.md)

Next · [Passive piezo buzzer](../../class-1/04-piezo-buzzer/README.md)
