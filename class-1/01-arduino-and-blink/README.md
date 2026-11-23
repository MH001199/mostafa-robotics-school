# Arduino, IDE and Blink

[School roadmap](../../README.md) · [Class 1](../README.md)

[Open the sketch](blink/blink.ino)

Use an Arduino Uno R3, a USB **data** cable, and a computer. Leave every header empty.

- Find the USB connector, reset button, onboard **L** LED, digital header (D0–D13), analog header (A0–A5), and power header (5V and GND). The ATmega328P runs the sketch. The USB connection powers the board and lets the IDE upload code.
- Install [Arduino IDE 2](https://www.arduino.cc/en/software). In Boards Manager install **Arduino AVR Boards**. Connect the board, select **Arduino Uno** and its detected port, then open `blink.ino`. Keep the sketch folder name intact.
- Click **Verify** to compile, then **Upload** to transfer the sketch. Watch the **L** LED for a half-second on and half-second off.

`setup()` runs once after reset. `loop()` repeats. `pinMode()` sets the pin's role, `digitalWrite()` drives HIGH or LOW, and `delay()` pauses in milliseconds. The named constant `LED_BUILTIN` selects the onboard LED. A semicolon ends a statement, braces group statements, and `//` starts a comment.

**Try it.** Make a short 100 ms flash followed by 900 ms off. Predict the period before upload. Reset the board and confirm that the pattern restarts.

**If it fails.** If the port is missing, try a data cable and a direct USB port. If Verify succeeds but Upload fails, recheck the board and port, close any other serial monitor, and reconnect. If the board has several status LEDs, observe the one labeled **L**.

[Arduino Uno R3 pinout and documentation](https://docs.arduino.cc/hardware/uno-rev3/)

Next · [Breadboard LED](../../class-1/02-breadboard-led/README.md)
