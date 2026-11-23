# Components Encyclopedia

[Start Learning](../student-course/README.md) · [Troubleshooting](troubleshooting.md) · [Glossary](glossary.md)

Identify the part before buying or wiring it. Each lesson’s pin map gives the exact connection for that sketch.

| Component | What to identify | Electrical role and application | Visual and lesson |
| --- | --- | --- | --- |
| Arduino Uno R3 | USB-B, digital and analog headers, 5V and GND | 5 V controller with ADC plus digital I/O for prototyping | [Arduino official photo and pinout](https://docs.arduino.cc/hardware/uno-rev3/) · [Board anatomy](../Class-01-Arduino-Fundamentals/00-Introduction/README.md#anatomy) |
| Solderless breadboard and jumpers | Five-hole groups, center gap, split rails, male and female ends | Joins low-current prototype nodes without soldering | [Photos and layouts](../Class-01-Arduino-Fundamentals/00-Introduction/breadboards.md) |
| LED and resistor | Anode, cathode, resistor bands and value | Polarity-sensitive light indicator with a series current limit | [D13 wiring and photos](../student-course/02-leds-and-sound.md#external_led) |
| Active buzzer module | Model-specific IN, GND and 5V labels | Logic input starts an internal oscillator for a fixed tone | [Active module and circuit](../student-course/02-leds-and-sound.md#active_buzzer) |
| Passive piezo | Two terminals and the voltage rating | Follows an external square wave for an audible pitch | [Piezo and series resistor](../student-course/02-leds-and-sound.md#passive_tones) |
| LDR | Two leads with no required polarity | Resistance falls in brighter light. A divider turns that into voltage for A0 | [Photo reference and divider](../student-course/03-inputs-light-and-climate.md#ldr_reading) |
| DHT11 | VCC, DATA, GND and NC on the bare part | Digital temperature and humidity readings. The bare part uses a DATA pull-up | [Package reference and wiring](../student-course/03-inputs-light-and-climate.md#dht11_reading) |
| HC-SR04 | VCC, TRIG, ECHO and GND | 5 V ultrasonic ranger. Time the ECHO pulse and reject timeouts | [Module and pin map](../student-course/04-distance-and-motors.md#ultrasonic_reading) |
| L298N and brushed DC motor | Driver logic and motor supplies, ENA, IN1/2, OUT1/2, and motor rating | 5 V control signals command a separate motor supply. An H-bridge controls direction and PWM adjusts drive | [Driver and safe wiring](../student-course/04-distance-and-motors.md#l298n_motor_control) |
| DHT22 and TB6612FNG | Exact model and module pin labels | Optional variants with their own pin map and power needs | [Optional Hardware Variations](hardware-variations.md) |
