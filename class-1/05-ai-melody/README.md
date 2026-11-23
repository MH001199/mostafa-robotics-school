# Compose a melody with AI

[School roadmap](../../README.md) · [Class 1](../README.md)

### See the components and circuit

[Passive piezo transducer product photos](https://www.adafruit.com/product/160) · Use the source to identify the part and then follow the wiring map below.

![Wiring diagram for Compose a melody with AI](../../lesson-visuals/alternate-ai_melody.svg)

Connection map for Compose a melody with AI on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node.

[Wiring diagram](../../lesson-visuals/alternate-ai_melody.svg) · [Arduino sketch](ai_melody/ai_melody.ino) · [Detailed notes and engineering questions](ai_melody/NOTES.md)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Keep the previous lesson's passive piezo and 330 Ω resistor on D7. The provided sketch plays an original six-event phrase once when the board resets. Press **RESET** to replay. A `Note` groups frequency and duration. The loop in `setup()` walks through those notes, adds a 40 ms gap, and treats 0 Hz as a rest.

1. Verify and upload the supplied sketch before editing.
2. Use the prompt below or write the phrase yourself.
3. Replace only the `melody[]` initializer. Check every pair against the limits in the prompt. Sketches generated elsewhere may target different pins or hardware.
4. Verify and upload again. Compare the rhythm you hear with the durations in your table.

> Give me an original six-event melody for a passive piezo. Return only a C++ initializer like {{262, 200}, {0, 120}}. Each pair is frequency in Hz and duration in ms. Use 220–2000 Hz for notes, 0 Hz for exactly one rest, and 100–500 ms for each event. Use no existing song.

**Try it.** Hum the same melody after doubling the duration of the final note. Record the original and edited note tables and explain which change you prefer.

**If it fails.** Check braces, commas, and the closing semicolon. If it plays once then goes quiet, press RESET. If rests beep, use the supplied `if` block that calls `noTone()`.

Previous · [Passive piezo buzzer](../../class-1/04-piezo-buzzer/README.md)

Next · [Digital and analog I/O](../../class-2/01-digital-analog-io/README.md)
