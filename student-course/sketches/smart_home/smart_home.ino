#include <DHT.h>
#define DHTTYPE DHT11

// INPUTS AND OUTPUTS — Arduino Uno R3
const int LDR_PIN = A0;
const int DHT_PIN = 2;
const int BUZZER_PIN = 3;
const int MOTOR_EN = 5;
const int LED_PIN = 6;
const int TRIG_PIN = 7;
const int ECHO_PIN = 8;
const int MOTOR_IN1 = 9;
const int MOTOR_IN2 = 10;
DHT dht(DHT_PIN, DHTTYPE);

// CHANGE THESE VALUES AFTER CALIBRATION
const int DARK_THRESHOLD = 400;
const int BRIGHT_THRESHOLD = 550;
const float FAN_ON_TEMP = 30.0;
const float FAN_OFF_TEMP = 28.0;
const int MOTOR_SPEED = 200;

// CURRENT SYSTEM STATE
bool lightIsOn = false;
bool fanIsOn = false;
bool buzzerIsOn = false;
int currentLightValue = 0;
float currentTemperature = NAN;
float currentHumidity = NAN;
float currentDistance = -1;

unsigned long lastLightRead = 0;
unsigned long lastDhtRead = 0;
unsigned long lastDistanceRead = 0;
unsigned long lastSerialUpdate = 0;

void setFan(bool turnOn) {
  fanIsOn = turnOn;
  if (fanIsOn) {
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    analogWrite(MOTOR_EN, MOTOR_SPEED);
  } else {
    analogWrite(MOTOR_EN, 0);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
  }
}

void updateLighting() {
  currentLightValue = analogRead(LDR_PIN);
  // Two thresholds prevent flickering near one threshold
  if (!lightIsOn && currentLightValue <= DARK_THRESHOLD) {
    lightIsOn = true;
  } else if (lightIsOn && currentLightValue >= BRIGHT_THRESHOLD) {
    lightIsOn = false;
  }
  digitalWrite(LED_PIN, lightIsOn ? HIGH : LOW);
}

void updateEnvironment() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 reading failed");
    setFan(false);
    currentTemperature = NAN;
    currentHumidity = NAN;
    return;
  }
  currentTemperature = temperature;
  currentHumidity = humidity;
  if (!fanIsOn && currentTemperature >= FAN_ON_TEMP) {
    setFan(true);
  } else if (fanIsOn && currentTemperature <= FAN_OFF_TEMP) {
    setFan(false);
  }
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // At most 25 ms of blocking time while waiting for an echo
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 25000UL);
  float distance = duration * 0.0343f / 2.0f;
  return (distance >= 2.0f && distance <= 400.0f) ? distance : -1.0f;
}

void updateProximityAlarm(unsigned long now) {
  bool shouldSound = false;
  if (currentDistance > 0 && currentDistance <= 10) {
    shouldSound = true;
  } else if (currentDistance > 10 && currentDistance <= 25) {
    shouldSound = (now % 220UL) < 110UL;
  } else if (currentDistance > 25 && currentDistance <= 60) {
    shouldSound = (now % 700UL) < 120UL;
  }
  if (shouldSound != buzzerIsOn) {
    buzzerIsOn = shouldSound;
    if (buzzerIsOn) tone(BUZZER_PIN, 1500);
    else noTone(BUZZER_PIN);
  }
}

void printSystemStatus() {
  Serial.println("===== SMART HOME =====");
  Serial.print("Light ADC: "); Serial.println(currentLightValue);
  Serial.print("Lamp: "); Serial.println(lightIsOn ? "ON" : "OFF");
  Serial.print("Temperature C: ");
  if (isnan(currentTemperature)) Serial.println("N/A");
  else Serial.println(currentTemperature);
  Serial.print("Humidity %RH: ");
  if (isnan(currentHumidity)) Serial.println("N/A");
  else Serial.println(currentHumidity);
  Serial.print("Fan: "); Serial.println(fanIsOn ? "ON" : "OFF");
  Serial.print("Distance cm: ");
  if (currentDistance < 0) Serial.println("No valid echo");
  else Serial.println(currentDistance);
  Serial.println("======================");
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_EN, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
  setFan(false);
  dht.begin();
  Serial.println("Smart Home Started");
}

void loop() {
  unsigned long now = millis();
  if (now - lastLightRead >= 100UL) {
    lastLightRead = now;
    updateLighting();
  }
  // DHT11 requires about two seconds between reads
  if (now - lastDhtRead >= 2000UL) {
    lastDhtRead = now;
    updateEnvironment();
  }
  if (now - lastDistanceRead >= 80UL) {
    lastDistanceRead = now;
    currentDistance = measureDistance();
  }
  updateProximityAlarm(millis());
  if (now - lastSerialUpdate >= 2000UL) {
    lastSerialUpdate = now;
    printSystemStatus();
  }
}
