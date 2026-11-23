# DHT22 temperature and humidity alarm

[School roadmap](../../README.md) · [Class 2](../README.md)

[Open the sketch](dht_alarm/dht_alarm.ino)

Disconnect USB and any external supply before changing wires. Reconnect power after checking the circuit.

Use a bare four-pin DHT22, a 10 kΩ pull-up resistor, and the [Class 1 piezo circuit](../../class-1/04-piezo-buzzer/README.md) on D7. For a bare DHT22 with the grille facing you and its pins pointing down, read left to right. For a breakout, follow its printed pin labels and check whether it includes a pull-up.

| DHT22 pin | Connection |
| --- | --- |
| 1 · VCC | Uno 5V |
| 2 · DATA | Uno D4 and one end of the 10 kΩ resistor |
| 3 · NC | Leave open |
| 4 · GND | Uno GND |

Connect the other end of the 10 kΩ resistor to 5V. In Arduino IDE Library Manager install **DHT sensor library** by Adafruit and **Adafruit Unified Sensor**. Select **Arduino Uno**, then verify and upload.

Open Serial Monitor at **9600 baud**. A new sample prints about every 2.5 s. Temperature is in °C and humidity is in percent relative humidity (%RH). The piezo beeps if either reading meets its threshold. A failed reading prints an error and silences the piezo. A DHT22 needs at least two seconds between samples.

**Try it.** Use the current readings to temporarily lower one threshold below ambient, verify a beep, then raise it above ambient and verify silence. Keep the sensor dry.

**If it fails.** A missing `DHT.h` means the sensor library is missing. If readings fail, check the pins, 5V, shared ground, pull-up, and that the installed part is a DHT22.

[Adafruit DHT wiring guide](https://learn.adafruit.com/dht/connecting-to-a-dhtxx-sensor)

Previous · [LDR voltage divider and night light](../../class-2/03-ldr-night-light/README.md)

Next · [Ultrasonic distance and proximity buzzer](../../class-2/05-ultrasonic-proximity/README.md)
