# Read inputs and make decisions

[Course map](README.md)

You can now control outputs. Start by varying LED brightness with PWM. Then measure light and climate independently before combining them into a controller. Start with raw readings so you can tell a wiring problem from a threshold problem.

- [Project 07 · PWM LED Fade](03-inputs-light-and-climate.md#pwm_fade)
- [Project 08 · LDR Analog Measurements](03-inputs-light-and-climate.md#ldr_reading)
- [Project 09 · LDR Automatic Night Lamp](03-inputs-light-and-climate.md#automatic_night_light)
- [Project 10 · DHT11 Temperature and Humidity](03-inputs-light-and-climate.md#dht11_reading)
- [Project 11 · Temperature / Humidity Buzzer Alarm](03-inputs-light-and-climate.md#dht11_alarm)
- [Project 12 · Combined Light and Climate System](03-inputs-light-and-climate.md#light_and_climate)

## Core conceptual lesson — Inputs, outputs, analog, digital and PWM

- Input: information read by the controller. Examples: LDR divider voltage, DHT11 temperature/humidity data, ultrasonic echo time, push-button state.

- Output: a controller action. Examples: LED brightness, buzzer tone, motor driver direction and speed.

- Digital: discrete states like HIGH/LOW. Sensors can still deliver digital measurements richer than one bit (DHT11 uses protocol-encoded data).

- Analog: variable electrical voltage read through an ADC, such as the voltage divider made from an LDR and a 10 kΩ resistor.

- PWM: a digital output switched HIGH and LOW rapidly, where duty cycle = ON time / period × 100%. With 50% duty cycle, it spends half of each period high. The average voltage is approximately D × 5V for an ideal Uno output, but this is not a true continuously variable analog voltage. On a Uno, analogWrite(pin, 0..255) generates PWM on D3,D5,D6,D9,D10,D11.

Question to ask students: "We have digital output pins and analog input pins. Where is the analog output?" Answer: The Uno R3 does not have a real built-in DAC. PWM is an analog-like control technique, not an analog DAC. A DAC or filtered PWM is needed when an actual analog voltage is required.

## Mathematical foundations used during the course

### LDR voltage divider

Wire the divider as 5V → LDR → A0 junction → 10 kΩ → GND.

`V(A0) = 5 V × 10 kΩ / (R_LDR + 10 kΩ)`

Bright light decreases R_LDR, causing higher voltage/ADC reading. The inverse orientation of the divider reverses the reading trend.

### Ultrasonic distance

Distance_cm = (Echo_duration_microseconds × 0.0343 cm/μs) / 2. Divide by 2 because the sound travels to the target and back. Example: 2000μs ≈ 34.3cm.

### Motor speed PWM

A PWM value of 180 on a scale of 0..255 is about 71% duty cycle, but not guaranteed 71% RPM: friction, motor load, supply voltage and driver losses matter. L298N also loses substantial voltage and heats under load.

### Non-blocking multi-task scheduling

Use unsigned times and if (millis() - previous >= interval), not long repeated delays, when independent sensors must remain responsive. This is cooperative scheduling; a blocking sensor read still consumes time.

Libraries required starting with DHT11: Adafruit DHT sensor library and Adafruit Unified Sensor. Do not skip the DHT error check (isnan) or the two-second sample spacing.

To practice both kinds of input before PWM, try the [Uno pushbutton and potentiometer lab](../class-2/01-digital-analog-io/README.md). This lab uses the Uno alone and works with either kit. Disconnect its wiring before continuing to Project 07.

[Arduino PWM reference](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/)

<a id="pwm_fade"></a>

## Project 07 · PWM LED Fade

### Goal

Understand digital versus analog behavior and vary an LED duty cycle with PWM.

### Components and module names

Arduino Uno; LED; 220 Ω resistor; breadboard; jumpers.

### Exact wiring (power OFF first)

D6 (PWM) → 220 Ω resistor → LED anode; LED cathode → GND.

### Concepts and module behavior

Input devices provide data, output devices act on instructions. Uno D0–D13 support digital I/O; A0–A5 are 10-bit ADC inputs and can be GPIO. True DAC: not built into Uno R3. PWM-capable Uno pins: D3,D5,D6,D9,D10,D11. analogWrite(pin,0..255) controls PWM duty cycle, not a true continuous DAC voltage. Duty cycle D = Ton/Tperiod ×100%; average ideal 5V PWM voltage is about D×5 V.

### Build and test — step by step

1. Connect the LED to D6 with a current-limiting resistor.
2. Upload the code.
3. Observe brightness rise and fall.
4. Compare analogWrite(6,0), 64, 128, 192, 255.
5. Explain why perceived brightness is not strictly linear with duty cycle.

### Complete Arduino sketch

[Open pwm_fade.ino](sketches/pwm_fade/pwm_fade.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

Each analogWrite() value changes ON-time proportion of a fast HIGH/LOW waveform. The LED and human visual integration produce a smooth-looking fade.

### Expected result

Continuous fade up and fade down.

### Hands-on challenge

Build five distinct brightness steps of 2 seconds each; calculate approximate PWM duty cycles.

### Where this technology is used

LED dimmers; display backlights; PWM inputs on compatible motor drivers.

### Real build / practical application photo

[Arduino pot och transistor](https://commons.wikimedia.org/wiki/File:Arduino_pot_och_transistor.JPG) — Elderstig. License: CC BY-SA 4.0. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 06 · AI-Assisted Original Buzzer Melody](02-leds-and-sound.md#original_melody)

**Next** · [Project 08 · LDR Analog Measurements](03-inputs-light-and-climate.md#ldr_reading). You controlled an output with a number. Now measure a changing voltage as a number.

<a id="ldr_reading"></a>

## Project 08 · LDR Analog Measurements

### Goal

Measure light-dependent voltage with a 10 kΩ resistor divider and record readings.

### Components and module names

Arduino Uno; bare LDR/photoresistor; 10 kΩ fixed resistor; breadboard and jumpers.

### Exact wiring (power OFF first)

5V → LDR → A0 junction; A0 junction → 10 kΩ → GND. The LDR is not polarized.

### Concepts and module behavior

An LDR typically decreases resistance when light rises. With the LDR on the high side and fixed resistor to ground, A0 voltage increases in bright light. Divider: Vout=Vcc·Rfixed/(RLDR+Rfixed). The Uno ADC reads approximately 0..1023 for the default 0..5 V analog input range. Raw ADC counts are not calibrated lux.

### Build and test — step by step

1. Disconnect power, assemble the divider in two breadboard rows.
2. Check the A0 junction and resistor path carefully.
3. Upload code and open Serial Monitor at 9600 baud.
4. Record readings in room light, covered, and under a phone flashlight.
5. Make a table: condition, ADC value, observation.
6. Compare values and estimate a threshold for next project.

### Complete Arduino sketch

[Open ldr_reading.ino](sketches/ldr_reading/ldr_reading.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

analogRead(A0) samples the divider junction; Serial.println() sends counts to the USB Serial Monitor.

### Expected result

ADC value decreases when covered and increases when illuminated with this wiring arrangement.

### Hands-on challenge

Calculate a candidate light threshold from bright and dark readings. Explain how reversing the voltage divider reverses the direction of readings.

### Where this technology is used

Automatic lighting; environmental data logging; light-seeking robots.

### Real build / practical application photo

[Sensore crepuscolare con arduino](https://commons.wikimedia.org/wiki/File:Sensore_crepuscolare_con_arduino.jpg) — Magi2774. License: CC BY-SA 4.0. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 07 · PWM LED Fade](03-inputs-light-and-climate.md#pwm_fade)

**Next** · [Project 09 · LDR Automatic Night Lamp](03-inputs-light-and-climate.md#automatic_night_light). Use your measured bright and dark readings to make a decision.

<a id="automatic_night_light"></a>

## Project 09 · LDR Automatic Night Lamp

### Goal

Use if/else to turn on an LED automatically when surroundings are dark.

### Components and module names

Arduino Uno; bare LDR; 10 kΩ resistor; LED; 220 Ω resistor; breadboard; jumpers.

### Exact wiring (power OFF first)

LDR divider: 5V → LDR → A0 → 10 kΩ → GND. LED: D6 → 220 Ω → LED anode; cathode → GND.

### Concepts and module behavior

Compare sensor readings against a threshold chosen from the previous project. if(condition) runs one block when true, else runs the alternative. A value of 500 is an example and must be calibrated for the physical LDR and room.

### Build and test — step by step

1. Keep the LDR divider from Project 08.
2. Add an LED on D6 with its own resistor.
3. Record covered and illuminated ADC values.
4. Set lightThreshold between the measured values.
5. Upload, cover LDR, inspect LED response.
6. Uncover and confirm LED turns off.

### Complete Arduino sketch

[Open automatic_night_light.ino](sketches/automatic_night_light/automatic_night_light.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

Lower reading = darker environment with this divider; the program makes a basic threshold decision. Advanced systems add hysteresis so the lamp does not flicker near the switching point.

### Expected result

Lamp ON in the dark, OFF in bright light.

### Hands-on challenge

Add a second LED for bright conditions, or implement two thresholds for stable switching.

### Where this technology is used

Automatic night lights; automatic streetlight control models; energy-saving lighting.

### Real build / practical application photo

[Automatic night light using Arduino and LDR](https://robozx.com/blog/automatic-night-light-using-arduino-and-photoresistor-sensor-ldr) — See original project page. License: Not independently verified for republication; link only. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 08 · LDR Analog Measurements](03-inputs-light-and-climate.md#ldr_reading)

**Next** · [Project 10 · DHT11 Temperature and Humidity](03-inputs-light-and-climate.md#dht11_reading). Keep the threshold idea and learn to read a digital sensor that reports two values.

<a id="dht11_reading"></a>

## Project 10 · DHT11 Temperature and Humidity

### Goal

Learn sensor libraries and read digital temperature/humidity data.

### Components and module names

Arduino Uno; DHT11 3-pin module or 4-pin bare DHT11; 10 kΩ pull-up for bare sensor; breadboard; jumpers.

### Exact wiring (power OFF first)

For a bare four-pin DHT11 with the grille toward you and pins down, wire left to right as 5V, DATA (D2), unused, GND. Add 10 kΩ between DATA and 5V. For a breakout, use the printed pin labels and verify whether a pull-up is already fitted. Install **DHT sensor library** by Adafruit and **Adafruit Unified Sensor** from Library Manager. Keep the two-second sampling interval used here. [DHT wiring](https://learn.adafruit.com/dht/connecting-to-a-dhtxx-sensor) · [Arduino library setup](https://learn.adafruit.com/dht/using-a-dhtxx-sensor-with-arduino)

3-pin DHT11 module: VCC→5V, DATA→D2, GND→GND. Bare DHT11 front grille facing you: pin1 VCC, pin2 DATA, pin3 NC, pin4 GND; add 10 kΩ from DATA to VCC. Check actual package markings.

### Concepts and module behavior

DHT11 communicates using a sensor-specific timed digital protocol, not I2C. Use DHT sensor library by Adafruit plus Adafruit Unified Sensor. readTemperature() returns Celsius; readHumidity() returns percentage relative humidity; isnan() identifies failed measurements. DHT11 should generally be sampled no faster than once every 2 seconds.

### Build and test — step by step

1. Install DHT library and Unified Sensor dependency using Library Manager.
2. Power off and connect the correct pin order.
3. Upload sketch.
4. Open Serial Monitor at 9600 baud.
5. Record normal temperature/humidity.
6. Observe values after gentle breath near sensor (do not wet it) or by moving a hand near it.
7. Explain sensor errors and units.

### Complete Arduino sketch

[Open dht11_reading.ino](sketches/dht11_reading/dht11_reading.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

DHT dht(...) creates a sensor object; dht.begin() initializes; both readings are floating-point numbers, checked for valid data before being used.

### Expected result

Readable temperature in °C and relative humidity in %RH about every 2 seconds.

### Hands-on challenge

Document 5 sets of measurements and identify possible causes of inaccurate or missing readings.

### Where this technology is used

Indoor monitoring; greenhouse control; equipment enclosures; educational weather stations.

### Additional engineering note

The DHT11 is a low-cost educational sensor and is not a precision or safety-critical instrument.

### Real build / practical application photo

[Arduino uno dht11](https://commons.wikimedia.org/wiki/File:Arduino_uno_dht11.jpg) — Edwiyanto. License: CC BY-SA 4.0. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 09 · LDR Automatic Night Lamp](03-inputs-light-and-climate.md#automatic_night_light)

**Next** · [Project 11 · Temperature / Humidity Buzzer Alarm](03-inputs-light-and-climate.md#dht11_alarm). Use valid readings and thresholds to decide when the piezo should sound.

<a id="dht11_alarm"></a>

## Project 11 · Temperature / Humidity Buzzer Alarm

### Goal

Use OR logic and a passive buzzer to respond to environmental thresholds.

### Components and module names

Arduino Uno; DHT11; passive low-current piezo buzzer; breadboard and jumper wires.

### Exact wiring (power OFF first)

For a bare four-pin DHT11 with the grille toward you and pins down, wire left to right as 5V, DATA (D2), unused, GND. Add 10 kΩ between DATA and 5V. For a breakout, use the printed pin labels and verify whether a pull-up is already fitted. Install **DHT sensor library** by Adafruit and **Adafruit Unified Sensor** from Library Manager. Keep the two-second sampling interval used here. [DHT wiring](https://learn.adafruit.com/dht/connecting-to-a-dhtxx-sensor) · [Arduino library setup](https://learn.adafruit.com/dht/using-a-dhtxx-sensor-with-arduino)

Reuse the DHT11 on D2 from Project 10. Connect D3 → 330 Ω resistor → the positive lead of a 5 V-compatible high-impedance passive piezo. Connect its negative lead to GND.

### Concepts and module behavior

The conditional temperature>=30.0 || humidity>=75.0 becomes true if either threshold is exceeded. && would require both. This is only a classroom alert, not a safety-certified alarm.

### Build and test — step by step

1. Retain DHT11 wiring.
2. Add passive piezo buzzer on D3.
3. Install/check library.
4. Upload sketch.
5. Try both outcomes. With both thresholds above the measured values the buzzer stays quiet. Temporarily lower one threshold below its measured value to trigger the buzzer, then restore the thresholds.
6. Restore sensible demo thresholds.
7. Compare OR (||) with AND (&&).

### Complete Arduino sketch

[Open dht11_alarm.ino](sketches/dht11_alarm/dht11_alarm.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

|| is logical OR; noTone() silences the alarm on normal or invalid readings. Do not poll DHT11 more frequently simply because the alarm is needed.

### Expected result

Continuous beep when either demo threshold is reached, silent otherwise.

### Hands-on challenge

Create three states: normal / temperature warning / humidity warning, using different buzzer patterns.

### Where this technology is used

Environment alarms; demonstrator of conditional decision logic.

### Real build / practical application photo

[DHT11 temperature and humidity buzzer alert](https://projecthub.arduino.cc/arduino_buzz/temperature-and-humidity-monitor-using-dht11-oled-rgb-led-and-buzzer-589f14) — See original project page. License: Not independently verified for republication; link only. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 10 · DHT11 Temperature and Humidity](03-inputs-light-and-climate.md#dht11_reading)

**Next** · [Project 12 · Combined Light and Climate System](03-inputs-light-and-climate.md#light_and_climate). Combine the night light and climate alarm while keeping their readings visible.

<a id="light_and_climate"></a>

## Project 12 · Combined Light and Climate System

### Goal

Run an automatic lamp and an independent environmental warning using one sketch.

### Components and module names

Arduino Uno; LDR; 10 kΩ resistor; DHT11; LED; 220 Ω resistor; passive piezo buzzer; breadboard and jumpers.

### Exact wiring (power OFF first)

For a bare four-pin DHT11 with the grille toward you and pins down, wire left to right as 5V, DATA (D2), unused, GND. Add 10 kΩ between DATA and 5V. For a breakout, use the printed pin labels and verify whether a pull-up is already fitted. Install **DHT sensor library** by Adafruit and **Adafruit Unified Sensor** from Library Manager. Keep the two-second sampling interval used here. [DHT wiring](https://learn.adafruit.com/dht/connecting-to-a-dhtxx-sensor) · [Arduino library setup](https://learn.adafruit.com/dht/using-a-dhtxx-sensor-with-arduino)

LDR divider at A0 (5V → LDR → A0 junction → 10 kΩ → GND). DHT11 DATA goes to D2, VCC to 5V, and GND to GND. Reuse Project 11's passive piezo on D3 with 330 Ω in series. Wire D6 → 220 Ω → LED anode, then cathode → GND.

### Concepts and module behavior

Combining sensors means distinct variables and independent decisions. LDR is an analog voltage; DHT11 is digital protocol data. The two tasks share a controller but need not depend on each other.

### Build and test — step by step

1. Begin with each previously tested subcircuit.
2. Merge ground rails and confirm each 5V module is rated for 5V.
3. Upload merged code.
4. Cover LDR and watch lamp.
5. Temporarily lower the environmental threshold for a safe buzzer test.
6. Verify both outputs can be active at the same time.
7. Discuss how delay(2000) affects responsiveness.

### Complete Arduino sketch

[Open light_and_climate.ino](sketches/light_and_climate/light_and_climate.ino). Open the file in Arduino IDE from its matching folder and select **Arduino Uno**. Click **Verify** before uploading.

### Code explanation

The ternary condition ? HIGH : LOW is a short way to choose one of two digital states. !isnan ensures sensor data is valid.

### Expected result

Covering LDR controls LED; DHT threshold controls buzzer; both operate on one Arduino.

### Hands-on challenge

Add a status LED or refactor both operations into separate named functions.

### Where this technology is used

Combined home sensors; environmental and lighting integration; small control panels.

### Real build / practical application photo

[Light and temperature sensor integration example](https://docs.sunfounder.com/projects/breadvolt/en/latest/projects/r4_project.html) — See original project page. License: Not independently verified for republication; link only. The linked example may use different hardware. Follow the wiring in this lesson.

**Previous** · [Project 11 · Temperature / Humidity Buzzer Alarm](03-inputs-light-and-climate.md#dht11_alarm)

**Next** · [Project 13 · HC-SR04 Distance Measurements](04-distance-and-motors.md#ultrasonic_reading). You can now combine two sensors. Add an input that measures distance by timing an echo.
