# Traffic light model notes

[Project lesson](../README.md) · [Open Arduino sketch](traffic_lights.ino) · [Image credits](../../../IMAGE-SOURCES.md)

## What does this program do?

Red 3 s, green 3 s, yellow 1 s

## Components and their functions

Arduino Uno R3 runs the sketch. A USB data cable supplies logic power and transfers the sketch. Use a breadboard and jumpers for external low-current connections.

### Three LEDs and three resistors

Each red, yellow and green LED has its own 330 Ω series resistor. Each cathode returns to the same ground.

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Component-Red-LED.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/9/90/Electronic-Component-Red-LED.jpg" width="260" alt="Two-lead through-hole red LED"></a>

*Two-lead through-hole red LED · Evan-Amos · Public domain.*

<a href="https://commons.wikimedia.org/wiki/File:Electronic-Axial-Lead-Resistors-Array.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/7/75/Electronic-Axial-Lead-Resistors-Array.jpg" width="260" alt="Axial resistors with colored bands"></a>

*Axial resistors with colored bands · Evan-Amos · Public domain.*

Use the resistance specified in the wiring table. Verify unfamiliar color bands with a multimeter before wiring.

## Wiring explanation

Disconnect USB and any external motor supply before changing a wire. Inspect wiring against the labeled module before applying power.

| Start | End | What this connection does |
| --- | --- | --- |
| D8 | 330 Ω → red LED anode | Red phase |
| D9 | 330 Ω → yellow LED anode | Yellow phase |
| D10 | 330 Ω → green LED anode | Green phase |
| All three cathodes | Uno GND | One shared return, no shared resistor |

![Wiring diagram for Traffic light model](../../../lesson-visuals/alternate-traffic_lights.svg)

Connection map for Traffic light model on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node. [Open diagram](../../../lesson-visuals/alternate-traffic_lights.svg).

## Complete code walkthrough

setup selects output mode for three pins. showLight clears all three first to avoid overlapping phases, lights activePin, and delays for durationMs. loop calls it in red, green, yellow order.

## Program execution sequence

Reset → setup runs once → loop runs the logic described above → repeat from the top of loop.

## Variables and functions

- `RED_LED` (`uint8_t`) starts at `8`. Check the pin map and move the wire only with power off if you change a pin.
- `YELLOW_LED` (`uint8_t`) starts at `9`. Check the pin map and move the wire only with power off if you change a pin.
- `GREEN_LED` (`uint8_t`) starts at `10`. Check the pin map and move the wire only with power off if you change a pin.

- `pinMode(pin, mode)` · Configures a GPIO as output, input or input with an internal pull-up. It does not turn an LED on.
- `digitalWrite(pin, value)` · On an output, HIGH drives near 5 V and LOW near ground. The value is held until changed.
- `delay(milliseconds)` · Pauses the sketch in milliseconds. A value of 500 is half a second.

## Expected output

Red 3 s, green 3 s, yellow 1 s

## Common errors and troubleshooting

- Check one LED and resistor at a time. If the order is wrong, compare D8/D9/D10 with the sketch and each LED color.

## Real-world applications

This pattern can help explain sequenced signalling. A classroom prototype is useful for learning how the signal is produced and tested.

[See an Arduino wired to a breadboard](https://commons.wikimedia.org/wiki/File:Arduino_Uno_with_breadboard.jpg) for a comparable bench setup.

## Student challenges

1. **Beginner** · Change the yellow time and compute the new cycle.
2. **Intermediate** · Add a short dark gap and record what happens when showLight clears the outputs.
3. **Optional advanced** · Replace the wait-based cycle with a three-phase state machine.

## Think Like an Engineer

The pin drives a series current path. What would happen if the resistor were omitted, the wire moved to a different pin without changing the code, or the LED reversed? Explain each outcome from current, pin selection and polarity. Draw the unsafe case on paper and never power an LED without its resistor.

Write down one prediction, the single variable you changed, and the result. If they differ, propose a measurement that would distinguish two possible causes.
