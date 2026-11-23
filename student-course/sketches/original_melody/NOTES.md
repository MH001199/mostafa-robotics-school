# Create an original melody with AI notes

[Project lesson](../../02-leds-and-sound.md#original_melody) · [Open Arduino sketch](original_melody.ino) · [Image credits](../../../IMAGE-SOURCES.md)

## What does this program do?

Eight-note phrase with 60 ms gaps and a 1.5 s pause

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

![Wiring diagram for Create an original melody with AI](../../../lesson-visuals/original_melody.svg)

Connection map for Create an original melody with AI on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node. [Open diagram](../../../lesson-visuals/original_melody.svg).

## Complete code walkthrough

notes and durations are parallel arrays. sizeof computes the element count from the note array. The loop plays notes at the matching index, waits the paired duration, stops the tone, then inserts a short gap. Both arrays must contain the same number of items.

## Program execution sequence

Reset → setup runs once → loop runs the logic described above → repeat from the top of loop.

## Variables and functions

- `buzzerPin` (`int`) starts at `8`. Check the pin map and move the wire only with power off if you change a pin.
- `notes` (`int`) starts at `{262, 330, 392, 523, 392, 330, 294, 262}`. Predict what changes in the walkthrough before editing this value.
- `durations` (`int`) starts at `{200, 200, 200, 400, 200, 200, 200, 500}`. Predict what changes in the walkthrough before editing this value.
- `noteCount` (`int`) starts at `sizeof(notes) / sizeof(notes[0])`. Predict what changes in the walkthrough before editing this value.

- `delay(milliseconds)` · Pauses the sketch in milliseconds. A value of 500 is half a second.
- `tone(pin, frequency, duration)` · Starts a square wave. The frequency is in hertz. With no duration, use noTone to stop it.
- `noTone(pin)` · Stops the waveform on the buzzer pin.
- `sizeof(array) / sizeof(array[0])` · Divides total bytes by the size of one element to calculate the array length.

## Expected output

Eight-note phrase with 60 ms gaps and a 1.5 s pause

## Common errors and troubleshooting

- Check that the part is a passive 5 V-compatible piezo. A buzzer with an oscillator will not reproduce the requested pitches.

## Real-world applications

This pattern can help explain custom audible device cues. A classroom prototype is useful for learning how the signal is produced and tested.

[Arduino buzzer melody project](https://projecthub.arduino.cc/hibit/play-christmas-melody-with-arduino-and-a-buzzer-ef33dc) — See original project page. License: Not independently verified for republication; link only.

Use this photograph to see a related build. Wire your project from the map above.

## Student challenges

1. **Beginner** · Change one duration while keeping both arrays the same length.
2. **Intermediate** · Ask AI for eight original frequency and duration pairs. Verify the proposed values and replace only the arrays.
3. **Optional advanced** · Store note and duration together in a struct to prevent mismatched lengths.

## Think Like an Engineer

Why can the active module beep with a steady HIGH, whereas the passive piezo needs a repeating waveform? Predict what you would hear if you changed only frequency or only duration.

Write down one prediction, the single variable you changed, and the result. If they differ, propose a measurement that would distinguish two possible causes.
