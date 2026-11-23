const int buzzerPin = 8;
const int notes[] = {262, 330, 392, 523, 392, 330, 294, 262};
const int durations[] = {200, 200, 200, 400, 200, 200, 200, 500};
const int noteCount = sizeof(notes) / sizeof(notes[0]);
void setup() {}
void loop() {
  for (int i = 0; i < noteCount; i++) {
    tone(buzzerPin, notes[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(60);
  }
  delay(1500);
}
