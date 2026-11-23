# Ultrasonic distance and proximity buzzer

[School roadmap](../../README.md) · [Class 2](../README.md)

### See the components and circuit

[Ultrasonic module photos](https://learn.adafruit.com/ultrasonic-sonar-distance-sensors) · Use the source to identify the part and then follow the wiring map below.

![Wiring diagram for Ultrasonic proximity buzzer](../../lesson-visuals/alternate-proximity_buzzer.svg)

Connection map for Ultrasonic proximity buzzer on the Uno R3. Follow connector labels. A repeated junction label is one shared electrical node.

[Wiring diagram](../../lesson-visuals/alternate-proximity_buzzer.svg) · [Arduino sketch](proximity_buzzer/proximity_buzzer.ino) · [Detailed notes and engineering questions](proximity_buzzer/NOTES.md)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Use a 5 V HC-SR04, a passive piezo with 330 Ω series resistor, and a flat target. Follow the HC-SR04 labels rather than inferring the order from its orientation.

| Module pin | Uno connection |
| --- | --- |
| VCC | 5V |
| TRIG | D10 |
| ECHO | D11 |
| GND | GND |
| Piezo (+) | D7 through 330 Ω |
| Piezo (−) | GND |

The module's ECHO signal is 5 V logic. This connection is for the 5 V Uno R3. A 3.3 V board needs appropriate level shifting or a correctly calculated divider on ECHO.

The Arduino sends a 10 μs trigger. It times the return pulse using `pulseIn()` with a 30 ms timeout, then divides the sound's round-trip distance by two. At **9600 baud**, move a flat target from 40 cm to 15 cm. Expect short 1 kHz beeps at 20 cm or closer within the module's valid range of about 2–400 cm. A timeout or out-of-range reading prints **No valid echo** and stays silent. The sketch pauses 150 ms between readings.

**Try it.** Compare the printed distance at 10, 20, and 40 cm with a ruler. Test an angled surface and explain why echoes may miss the receiver.

**If it fails.** Confirm TRIG and ECHO are on separate, correct pins. Use a broad flat target perpendicular to the sensor. A target inside the blind zone may yield an invalid reading.

[HC-SR04 datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)

Previous · [DHT22 temperature and humidity alarm](../../class-2/04-dht-alarm/README.md)

Next · [Brushed DC motor and TB6612FNG driver](../../class-2/06-dc-motor-driver/README.md)
