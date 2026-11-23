# Serial Connection Test Notes

[Section 00](../README.md#connection) · [Arduino sketch](serial_connection.ino)

**Objective.** Upload to the correct Uno, open the matching serial port, and trace the output to the line of code that produced it.

## Predict

Read the sketch first. Record what you expect the startup line to say, the first tick value, and the interval between ticks.

## Components and wiring

Use an Arduino Uno R3, a USB data cable, and a computer. Connect the Uno’s USB-B port to the computer and leave all headers empty. The USB connection carries power, upload data, and serial traffic.

## Run

Select Arduino Uno and the port that appears after plugging in. Verify, Upload, and open Serial Monitor at 9600 baud. Press RESET to replay the startup line.

```text
Uno ready
Tick 0
Tick 1
Tick 2
```

## Investigate

`unsigned long tick = 0` stores a nonnegative counter initialized at startup. `Serial.begin(9600)` sets the communication rate. `setup()` prints the startup message once per reset. In `loop()`, `Serial.print("Tick ")` leaves the cursor on the same line. `Serial.println(tick)` appends the current number and ends the line. `++tick` increments after the print, so the first number is 0. `delay(1000)` waits one second before the next pass.

## Modify

Change only the delay to 500 ms. Predict how many new tick lines appear over four seconds, then compare your observation.

## Make

Create a short device startup log with your own device name and a numbered status line. Keep the headers empty.

## Troubleshoot

- No port: try a known USB data cable and another computer port.
- Upload fails: confirm the board and port. Close another serial app that may have the port open.
- Unreadable text: use 9600 baud for the supplied sketch.
- No startup line: press RESET with Serial Monitor open.

## Knowledge check and checkpoint

1. Which function prints the startup text? `setup()`.
2. Why does the counter begin at zero? Its global initializer runs at startup before the first print.
3. Which statement ends the line? `Serial.println(tick)`.

Show two consecutive ticks and point to the statements that set the baud rate, print a tick, and control the interval.

## Think Like an Engineer

If nothing appears, how would you distinguish a failed upload from a wrong baud rate? Choose one observation or experiment for each explanation. A serial log helps diagnose a running device even when the product has no display.

**Next** · [Beginner Assessment](../README.md#assessment).
