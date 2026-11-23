# Passive piezo buzzer

[School roadmap](../../README.md) · [Class 1](../README.md)

[Open the sketch](piezo_beep/piezo_beep.ino)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Choose a small, high-impedance passive piezo transducer rated for a 5 V drive signal, a 330 Ω resistor, and jumpers. Some kits use the same buzzer label for active modules, magnetic sounders, and passive piezos. Check the part documentation before wiring. Use this circuit only with a passive piezo. Speakers and magnetic buzzers require a suitable driver.

```text
D7 ── 330 Ω ── piezo (+)      piezo (−) ── GND
```

Upload. Expect a short 880 Hz beep once per second. `tone(pin, frequency, duration)` starts a square wave and returns while the wave plays. Frequency in hertz controls pitch. The third argument sets how long the wave plays, in milliseconds. The resistor also limits the transient current as the piezo charges.

**Try it.** Change 880 Hz to 440 Hz and listen. Change the duration to 400 ms and describe what changed in the pitch and in the rhythm.

**If it fails.** Check D7, GND, and the part type. If the sound is very faint, confirm the rated resonant frequency and try a tone near it while keeping the same wiring.

[Arduino tone reference](https://docs.arduino.cc/language-reference/en/functions/advanced-io/tone/)

Previous · [Traffic light model](../../class-1/03-traffic-lights/README.md)

Next · [Compose a melody with AI](../../class-1/05-ai-melody/README.md)
