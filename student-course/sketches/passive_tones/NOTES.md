# Passive piezo musical notes notes

[Project lesson](../../02-leds-and-sound.md#passive_tones) · [Open Arduino sketch](passive_tones.ino) · [Image credits](../../../IMAGE-SOURCES.md)

## What does this program do?

Four rising tones of 400 ms, then a 1 s pause

## Components and their functions

Arduino Uno R3 runs the sketch. A USB data cable supplies logic power and transfers the sketch. Use a breadboard and jumpers for external low-current connections.

### Passive piezo and resistor

A high-impedance passive piezo rated for 5 V turns the square wave into sound. The 330 Ω series resistor limits transient current.

[Passive piezo transducer product photos](https://www.adafruit.com/product/160) · Use the source to identify the part and then follow the wiring map below.

## Wiring explanation

Disconnect USB and any external motor supply before changing a wire. Inspect wiring against the labeled module before applying power.

| Start | End | What this connection does |
| --- | --- | --- |
| D8 | 330 Ω → passive piezo (+) | The tone or note signal |
| Piezo (−) | Uno GND | Completes the return path |

![Wiring diagram for Passive piezo musical notes](../../../lesson-visuals/passive_tones.svg)

Connection map for Passive piezo musical notes on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node. [Open diagram](../../../lesson-visuals/passive_tones.svg).

## Complete code walkthrough

The Arduino starts each tone from its frequency in hertz. A 400 ms delay leaves time to hear it before the next tone replaces it. noTone stops the waveform, and the final delay gives silence before repeating.

## Program execution sequence

Reset → setup runs once → loop runs the logic described above → repeat from the top of loop.

## Variables and functions

- `buzzerPin` (`int`) starts at `8`. Check the pin map and move the wire only with power off if you change a pin.

- `delay(milliseconds)` · Pauses the sketch in milliseconds. A value of 500 is half a second.
- `tone(pin, frequency, duration)` · Starts a square wave. The frequency is in hertz. With no duration, use noTone to stop it.
- `noTone(pin)` · Stops the waveform on the buzzer pin.

## Expected output

Four rising tones of 400 ms, then a 1 s pause

## Common errors and troubleshooting

- Check that the part is a passive 5 V-compatible piezo. A buzzer with an oscillator will not reproduce the requested pitches.

## Real-world applications

This pattern can help explain distinct device alerts. A classroom prototype is useful for learning how the signal is produced and tested.

[Arduino circuit with speaker, LEDs, protoboard and jumpers](https://commons.wikimedia.org/wiki/File:Arduino_circuit_with_speaker%2C_LEDs%2C_protoboard_and_jumpers.jpg) — GlauberSantiagoUFSCar. License: CC BY-SA 4.0.

Use this photograph to see a related build. Wire your project from the map above.

## Student challenges

1. **Beginner** · Change 262 Hz to 330 Hz and predict the pitch difference.
2. **Intermediate** · Insert a timed rest using noTone and delay.
3. **Optional advanced** · Build a note-and-duration table and loop over it.

## Think Like an Engineer

Why can the active module beep with a steady HIGH, whereas the passive piezo needs a repeating waveform? Predict what you would hear if you changed only frequency or only duration.

Write down one prediction, the single variable you changed, and the result. If they differ, propose a measurement that would distinguish two possible causes.
