#include <DHT.h>
#define DHTTYPE DHT11
const int dhtPin = 2;
const int buzzerPin = 3;
DHT dht(dhtPin, DHTTYPE);
const float maxTemperature = 30.0;
const float maxHumidity = 75.0;
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();
}
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    noTone(buzzerPin);
    Serial.println("DHT11 error");
    delay(2000);
    return;
  }
  Serial.print("T="); Serial.print(temperature);
  Serial.print(" C, RH="); Serial.println(humidity);
  if (temperature >= maxTemperature || humidity >= maxHumidity) {
    tone(buzzerPin, 1500);
    Serial.println("Threshold warning");
  } else {
    noTone(buzzerPin);
  }
  delay(2000);
}
