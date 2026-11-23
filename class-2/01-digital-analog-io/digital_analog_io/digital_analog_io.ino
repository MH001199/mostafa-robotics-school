const uint8_t BUTTON_PIN = 2;
const uint8_t POT_PIN = A0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // The switch connects the input to ground when pressed.
  bool pressed = digitalRead(BUTTON_PIN) == LOW;
  digitalWrite(LED_BUILTIN, pressed ? HIGH : LOW);

  int raw = analogRead(POT_PIN);
  Serial.print(F("button_pressed="));
  Serial.print(pressed);
  Serial.print(F(" pot="));
  Serial.println(raw);
  delay(50);
}
