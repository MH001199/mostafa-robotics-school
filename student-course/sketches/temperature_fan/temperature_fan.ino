#include <DHT.h>
#define DHTTYPE DHT11
const int dhtPin = 2;
DHT dht(dhtPin, DHTTYPE);
const int enA = 5;
const int in1 = 9;
const int in2 = 10;
const float fanOnTemperature = 30.0;
const float fanOffTemperature = 28.0;
bool fanIsOn = false;
void setFan(bool turnOn) {
  fanIsOn = turnOn;
  if (fanIsOn) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 200);
  } else {
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  setFan(false);
  dht.begin();
}
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 error; fan OFF");
    setFan(false);
    delay(2000);
    return;
  }
  if (!fanIsOn && temperature >= fanOnTemperature) {
    setFan(true);
  } else if (fanIsOn && temperature <= fanOffTemperature) {
    setFan(false);
  }
  Serial.print("T: "); Serial.print(temperature);
  Serial.print(" C  RH: "); Serial.print(humidity);
  Serial.print(" %  Fan: ");
  Serial.println(fanIsOn ? "ON" : "OFF");
  delay(2000);
}
