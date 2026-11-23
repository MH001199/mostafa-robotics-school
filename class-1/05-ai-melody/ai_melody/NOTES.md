# Compose a melody with AI notes

[Project lesson](../README.md) · [Open Arduino sketch](ai_melody.ino) · [Image credits](../../../IMAGE-SOURCES.md)

## What does this program do?

One six-event phrase on reset, then silence

## Components and their functions

Arduino Uno R3 runs the sketch. A USB data cable supplies logic power and transfers the sketch. Use a breadboard and jumpers for external low-current connections.

### Passive piezo and resistor

A high-impedance passive piezo rated for 5 V turns the square wave into sound. The 330 Ω series resistor limits transient current.

[Passive piezo transducer product photos](https://www.adafruit.com/product/160) · Use the source to identify the part and then follow the wiring map below.

## Wiring explanation

Disconnect USB and any external motor supply before changing a wire. Inspect wiring against the labeled module before applying power.

| Start | End | What this connection does |
| --- | --- | --- |
| D7 | 330 Ω → passive piezo (+) | The tone or note signal |
| Piezo (−) | Uno GND | Completes the return path |

![Wiring diagram for Compose a melody with AI](../../../lesson-visuals/alternate-ai_melody.svg)

Connection map for Compose a melody with AI on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node. [Open diagram](../../../lesson-visuals/alternate-ai_melody.svg).

## Complete code walkthrough

A Note pairs hz and ms. The range-based for in setup visits each pair exactly once. A nonzero frequency calls tone; zero calls noTone for a rest. delay waits for the event and adds 40 ms. loop stays empty, so reset replays the phrase.

## Program execution sequence

Reset → setup configures the output and plays every event once → empty loop.

## Variables and functions

- `PIEZO_PIN` (`uint8_t`) starts at `7`. Check the pin map and move the wire only with power off if you change a pin.

- `pinMode(pin, mode)` · Configures a GPIO as output, input or input with an internal pull-up. It does not turn an LED on.
- `delay(milliseconds)` · Pauses the sketch in milliseconds. A value of 500 is half a second.
- `tone(pin, frequency, duration)` · Starts a square wave. The frequency is in hertz. With no duration, use noTone to stop it.
- `noTone(pin)` · Stops the waveform on the buzzer pin.

## Expected output

One six-event phrase on reset, then silence

## Common errors and troubleshooting

- Check that the part is a passive 5 V-compatible piezo. A buzzer with an oscillator will not reproduce the requested pitches.

## Real-world applications

This pattern can help explain audible status sequences. A classroom prototype is useful for learning how the signal is produced and tested.

[See an Arduino wired to a breadboard](https://commons.wikimedia.org/wiki/File:Arduino_Uno_with_breadboard.jpg) for a comparable bench setup.

## Student challenges

1. **Beginner** · Turn one note into a rest and predict the rhythm.
2. **Intermediate** · Ask AI for an original frequency-duration table and validate every value before editing the array.
3. **Optional advanced** · Create two phrases and select one with a small function.

## Think Like an Engineer

Why can the active module beep with a steady HIGH, whereas the passive piezo needs a repeating waveform? Predict what you would hear if you changed only frequency or only duration.

Write down one prediction, the single variable you changed, and the result. If they differ, propose a measurement that would distinguish two possible causes.
