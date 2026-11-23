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
for sketch in class-1/*/*/*.ino class-2/*/*/*.ino; do
  arduino-cli compile --fqbn arduino:avr:uno --warnings all "${sketch%/*}"
done
```

Alternatively, open any sketch in Arduino IDE, select **Arduino Uno**, and click **Verify**. Keep the `.ino` file in its matching folder.

## Bench checks

All 12 sketches compiled for the Uno R3 with the versions above. The Arduino AVR core emitted unused-parameter warnings in its own `new.cpp` on the first build. Physical bench testing remains to be done.

Each lesson includes an expected result and at least one exercise. The [smart home acceptance checks](class-2/07-smart-home/README.md#acceptance-checks) cover the integrated system. Compilation verifies the sketch and library combination. The bench checks require physical hardware.
