#include <Arduino.h>          // generally optional in a standard .ino sketch
const int ledPin = 13;       // global pin constant
unsigned long count = 0;               // global variable

void setup() {                // runs once
  pinMode(ledPin, OUTPUT);   // configure hardware here
  Serial.begin(9600);
}
void loop() {                 // repeats
  digitalWrite(ledPin, HIGH);
  delay(500);                // 500 milliseconds = 0.5 s
  digitalWrite(ledPin, LOW);
  delay(500);
  count++;
}
