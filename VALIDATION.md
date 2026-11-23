# Sketch verification

## Compile for the Arduino Uno R3

Use Arduino CLI 1.3.1 with board ID `arduino:avr:uno`, Arduino AVR Boards 1.8.8, Adafruit DHT sensor library 1.4.6, and Adafruit Unified Sensor 1.1.15.

```sh
arduino-cli core update-index
arduino-cli core install arduino:avr@1.8.8
arduino-cli lib install "DHT sensor library@1.4.6" "Adafruit Unified Sensor@1.1.15"
```

From the repository root on macOS, Linux, or Git Bash:

```sh
set -e
for sketch in class-1/*/*/*.ino class-2/*/*/*.ino student-course/sketches/*/*.ino; do
  arduino-cli compile --fqbn arduino:avr:uno --warnings all "${sketch%/*}"
done
```

Alternatively, open any sketch in Arduino IDE, select **Arduino Uno**, and click **Verify**. Keep the `.ino` file in its matching folder.

## Bench checks

The 12 DHT22/TB6612FNG route sketches compiled for the Uno R3 with Arduino CLI. The 19 full-course sketches, including the annotated setup example, were compiled and linked for the ATmega328P with AVR GCC 7.3.0, AVR core 1.8.8, and the Adafruit library versions above. Physical bench testing remains to be done.

Each lesson includes an expected result and at least one exercise. Use the [DHT11/L298N capstone checks](student-course/05-smart-home.md#before-you-move-on) or the [DHT22/TB6612FNG capstone checks](class-2/07-smart-home/README.md#acceptance-checks) for the hardware route you built.
