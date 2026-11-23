const uint8_t TRIG_PIN = 10;
const uint8_t ECHO_PIN = 11;
const uint8_t PIEZO_PIN = 7;
const float ALERT_CM = 20.0;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long echoUs = pulseIn(ECHO_PIN, HIGH, 30000UL);
  // Sound travels about 0.0343 cm per microsecond at room temperature.
  return echoUs * 0.0343f / 2.0f;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = readDistanceCm();
  if (distance < 2.0 || distance > 400.0) {
    noTone(PIEZO_PIN);
    Serial.println(F("No valid echo"));
  } else {
    Serial.print(distance);
    Serial.println(F(" cm"));
    if (distance <= ALERT_CM) {
      tone(PIEZO_PIN, 1000, 60);
    } else {
      noTone(PIEZO_PIN);
    }
  }
  delay(150);
}
