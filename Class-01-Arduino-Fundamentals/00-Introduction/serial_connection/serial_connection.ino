unsigned long tick = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Uno ready");
}

void loop() {
  Serial.print("Tick ");
  Serial.println(tick);
  ++tick;
  delay(1000);
}
