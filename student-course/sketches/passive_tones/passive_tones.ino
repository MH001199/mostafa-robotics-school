const int buzzerPin = 8;
void setup() {}
void loop() {
  tone(buzzerPin, 262); delay(400);
  tone(buzzerPin, 330); delay(400);
  tone(buzzerPin, 392); delay(400);
  tone(buzzerPin, 523); delay(400);
  noTone(buzzerPin);
  delay(1000);
}
