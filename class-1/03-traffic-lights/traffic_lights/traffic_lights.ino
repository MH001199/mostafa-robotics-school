const uint8_t RED_LED = 8;
const uint8_t YELLOW_LED = 9;
const uint8_t GREEN_LED = 10;

void showLight(uint8_t activePin, unsigned long durationMs) {
  // Turn off the previous phase before lighting the next one.
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(activePin, HIGH);
  delay(durationMs);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  showLight(RED_LED, 3000);
  showLight(GREEN_LED, 3000);
  showLight(YELLOW_LED, 1000);
}
