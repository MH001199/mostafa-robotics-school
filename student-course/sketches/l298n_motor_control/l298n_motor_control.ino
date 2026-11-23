const int enA = 5;
const int in1 = 9;
const int in2 = 10;
void motorForward(int speedValue) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speedValue);
}
void motorBackward(int speedValue) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speedValue);
}
void motorStop() {
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  motorStop();
}
void loop() {
  motorForward(180); delay(3000);
  motorStop(); delay(2000);
  motorBackward(180); delay(3000);
  motorStop(); delay(2000);
}
