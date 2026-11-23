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
for sketch in class-1/*/*/*.ino class-2/*/*/*.ino student-course/sketches/*/*.ino Class-01-Arduino-Fundamentals/00-Introduction/*/*.ino; do
  arduino-cli compile --fqbn arduino:avr:uno --warnings all "${sketch%/*}"
done
```

Alternatively, open any sketch in Arduino IDE, select **Arduino Uno**, and click **Verify**. Keep the `.ino` file in its matching folder.

## Bench checks

The 12 DHT22/TB6612FNG route sketches compiled for the Uno R3 with Arduino CLI. The 19 full-course sketches, including the annotated setup example, were compiled and linked for the ATmega328P with AVR GCC 7.3.0, AVR core 1.8.8, and the Adafruit library versions above. Physical bench testing remains to be done.

Each lesson includes an expected result and at least one exercise. Use the [DHT11/L298N capstone checks](student-course/05-smart-home.md#before-you-move-on) or the [DHT22/TB6612FNG capstone checks](class-2/07-smart-home/README.md#acceptance-checks) for the hardware route you built.

## Record verification by method

| Method | Command or evidence | What it verifies |
| --- | --- | --- |
| Documentation | `python tools/site.py check` | Local targets, anchors, image alt text, PRIMM order and matching notes |
| Site rendering | `python -m pip install -r requirements-docs.txt`, then `python tools/site.py build` | Strict Material for MkDocs build of the repository source |
| Simulation | `python tools/simulations.py --check` | Template wiring endpoints and sketch paths. Simulator execution requires a separate run and result |
| Bench | Build log with kit, wiring, stimulus, observed output and date | Actual hardware behavior. No bench result is recorded for either capstone yet |

## Reproduce the two capstone bench checks

1. Pick the core or optional capstone link above. Record the Uno, DHT, driver, motor ratings, and source voltage. Follow only that capstone’s wiring. With USB and motor power disconnected, inspect resistor placement and common ground.
2. Leave the motor supply off, upload to Uno R3, and open Serial Monitor at 9600 baud. Record one valid climate sample and three readings from a flat target 10, 20, and 40 cm away.
3. Cover and uncover the LDR to force both lamp states. Record the ADC values. Move the target through the alarm distances specified in the matching capstone.
4. Secure the motor with its shaft bare and enable the correctly rated motor supply only after logic starts. Change temperature thresholds near ambient to demonstrate both fan states. Record the thresholds and observed behavior.
5. Disconnect both supplies before removing DHT DATA. Restore logic power and then motor power. Confirm the fault log and fan-off state. Verify the lamp and distance input still respond. On the optional kit, also test the humidity tone and proximity priority.
6. Disconnect both supplies, restore the sensor connection, and record each test as pass, fail, or skipped with observations.
