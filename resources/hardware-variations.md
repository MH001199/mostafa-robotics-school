# Optional Hardware Variations

[Start Learning](../student-course/README.md) · [Section 00](../Class-01-Arduino-Fundamentals/00-Introduction/README.md)

Use the [core course](../student-course/README.md) for the Arduino Uno R3 with DHT11 and L298N. If your kit has a DHT22 and TB6612FNG, use the [optional Class 1 sequence](../class-1/README.md) and [optional Class 2 sequence](../class-2/README.md). Both use Section 00 and lead to the [Class 3 foundations](../class-3/README.md).

| Capstone connection | Core DHT11/L298N | Optional DHT22/TB6612FNG |
| --- | --- | --- |
| Sensor data | DHT11 on D2 | DHT22 on D4 |
| Driver enable and direction | L298N ENA D5, IN1 D9, IN2 D10 | TB6612FNG PWMA D6, AIN1 D8, AIN2 D9, STBY D12 |
| Wiring and program | [Core capstone](../student-course/05-smart-home.md#smart_home) | [Optional capstone](../class-2/07-smart-home/README.md) |

The drivers have different power inputs and control signals. Use the diagram, sketch, and notes from the same page. Switch off USB and the external motor supply before rewiring.
