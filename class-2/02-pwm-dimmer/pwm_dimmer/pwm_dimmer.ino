const uint8_t POT_PIN = A0;
const uint8_t PWM_LED_PIN = 5;

void setup() {
  pinMode(PWM_LED_PIN, OUTPUT);
}

void loop() {
  int raw = analogRead(POT_PIN);
  // Scale the 10-bit reading to an 8-bit duty-cycle command.
  int duty = map(raw, 0, 1023, 0, 255);
  analogWrite(PWM_LED_PIN, duty);
  delay(20);
}
