#include <DHT.h>

const uint8_t LDR_PIN = A0;
const uint8_t LAMP_PIN = 5;
const uint8_t DHT_PIN = 4;
const uint8_t PIEZO_PIN = 7;
const uint8_t TRIG_PIN = 10;
const uint8_t ECHO_PIN = 11;
const uint8_t MOTOR_PWM = 6;
const uint8_t MOTOR_IN1 = 8;
const uint8_t MOTOR_IN2 = 9;
const uint8_t MOTOR_STBY = 12;

const int DARK_ON = 350;
const int BRIGHT_OFF = 450;
const float FAN_ON_C = 30.0;
const float FAN_OFF_C = 28.0;
const float MAX_HUMIDITY = 75.0;
const float NEAR_CM = 20.0;
const unsigned long DHT_INTERVAL_MS = 2500;
const unsigned long ROOM_INTERVAL_MS = 150;

DHT dht(DHT_PIN, DHT22);
bool lampOn = false;
bool fanOn = false;
bool humidityAlarm = false;
unsigned long lastDhtMs;
unsigned long lastRoomMs;

void setFan(bool enabled) {
  if (enabled) {
    analogWrite(MOTOR_PWM, 255);
    digitalWrite(MOTOR_STBY, HIGH);
  } else {
    digitalWrite(MOTOR_STBY, LOW);
    analogWrite(MOTOR_PWM, 0);
  }
}

void updateClimate() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    fanOn = false;
    humidityAlarm = false;
    Serial.println(F("DHT read failed; fan disabled"));
  } else {
    if (temperature >= FAN_ON_C) {
      fanOn = true;
    } else if (temperature <= FAN_OFF_C) {
      fanOn = false;
    }
    humidityAlarm = humidity >= MAX_HUMIDITY;
    Serial.print(F("Temperature C="));
    Serial.print(temperature);
    Serial.print(F(" RH="));
    Serial.print(humidity);
    Serial.print(F(" fan="));
    Serial.println(fanOn);
  }
  setFan(fanOn);
}

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long echoUs = pulseIn(ECHO_PIN, HIGH, 30000UL);
  return echoUs * 0.0343f / 2.0f;
}

void updateRoom() {
  int light = analogRead(LDR_PIN);
  if (light <= DARK_ON) {
    lampOn = true;
  } else if (light >= BRIGHT_OFF) {
    lampOn = false;
  }
  digitalWrite(LAMP_PIN, lampOn ? HIGH : LOW);

  float distance = readDistanceCm();
  // A zero return indicates a timeout. Distances below 2 cm are invalid.
  bool objectNear = distance >= 2.0 && distance <= NEAR_CM;
  if (objectNear) {
    tone(PIEZO_PIN, 1200, 50);
  } else if (humidityAlarm) {
    tone(PIEZO_PIN, 600, 50);
  } else {
    noTone(PIEZO_PIN);
  }

  Serial.print(F("Light="));
  Serial.print(light);
  Serial.print(F(" distance cm="));
  if (distance < 2.0 || distance > 400.0) {
    Serial.println(F("invalid"));
  } else {
    Serial.println(distance);
  }
}

void setup() {
  pinMode(MOTOR_STBY, OUTPUT);
  digitalWrite(MOTOR_STBY, LOW);
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  setFan(false);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  dht.begin();
  lastDhtMs = millis();
  lastRoomMs = lastDhtMs;
}

void loop() {
  unsigned long now = millis();
  // Unsigned subtraction still works when millis() rolls over.
  if (now - lastDhtMs >= DHT_INTERVAL_MS) {
    lastDhtMs = now;
    updateClimate();
  }
  if (now - lastRoomMs >= ROOM_INTERVAL_MS) {
    lastRoomMs = now;
    updateRoom();
  }
}
