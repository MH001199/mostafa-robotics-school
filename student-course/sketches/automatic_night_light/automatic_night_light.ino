const int ldrPin = A0;
const int ledPin = 6;
const int lightThreshold = 500; // Calibrate first
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.print("Light ADC: ");
  Serial.println(lightValue);
  if (lightValue < lightThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(200);
}
