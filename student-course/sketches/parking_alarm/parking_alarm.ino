const int trigPin = 7;
const int echoPin = 8;
const int buzzerPin = 3;
float readDistanceCM() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);
  float distance = duration * 0.0343f / 2.0f;
  return (distance >= 2.0f && distance <= 400.0f) ? distance : -1.0f;
}
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(trigPin, LOW);
}
void loop() {
  float distance = readDistanceCM();
  Serial.print("Distance: "); Serial.println(distance);
  if (distance < 0) {
    noTone(buzzerPin); delay(100);
  } else if (distance <= 10) {
    tone(buzzerPin, 1500); delay(100);
  } else if (distance <= 25) {
    tone(buzzerPin, 1500); delay(100);
    noTone(buzzerPin); delay(100);
  } else if (distance <= 60) {
    tone(buzzerPin, 1500); delay(150);
    noTone(buzzerPin); delay(450);
  } else {
    noTone(buzzerPin); delay(100);
  }
}
