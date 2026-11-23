const uint8_t PIEZO_PIN = 7;

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // tone() returns immediately while the Arduino generates the sound.
  tone(PIEZO_PIN, 880, 180);
  delay(1000);
}
