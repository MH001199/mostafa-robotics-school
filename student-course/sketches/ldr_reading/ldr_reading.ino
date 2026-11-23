const int ldrPin = A0;
void setup() { Serial.begin(9600); }
void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.print("LDR ADC: ");
  Serial.println(lightValue);
  delay(500);
}
