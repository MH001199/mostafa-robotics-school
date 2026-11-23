const uint8_t MOTOR_PWM = 6;
const uint8_t MOTOR_IN1 = 8;
const uint8_t MOTOR_IN2 = 9;
const uint8_t MOTOR_STBY = 12;
const uint8_t POT_PIN = A0;

void setup() {
  pinMode(MOTOR_STBY, OUTPUT);
  digitalWrite(MOTOR_STBY, LOW);
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_PWM, 0);
}

void loop() {
  int duty = map(analogRead(POT_PIN), 0, 1023, 0, 255);
  if (duty < 20) {
    digitalWrite(MOTOR_STBY, LOW);  // Disable the bridge and coast.
    analogWrite(MOTOR_PWM, 0);
  } else {
    analogWrite(MOTOR_PWM, duty);
    digitalWrite(MOTOR_STBY, HIGH);
  }
  delay(30);
}
