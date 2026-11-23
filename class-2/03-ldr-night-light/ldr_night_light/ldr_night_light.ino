const uint8_t LDR_PIN = A0;
const uint8_t LED_PIN = 8;
// Measure your own room and adjust both thresholds.
const int DARK_ON = 350;
const int BRIGHT_OFF = 450;

bool lampOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);
  if (light <= DARK_ON) {
    lampOn = true;
  } else if (light >= BRIGHT_OFF) {
    lampOn = false;
  }
  // Keep the previous state between the two thresholds.
  digitalWrite(LED_PIN, lampOn ? HIGH : LOW);
  Serial.println(light);
  delay(100);
}
