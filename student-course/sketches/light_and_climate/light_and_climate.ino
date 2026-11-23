#include <DHT.h>
#define DHTTYPE DHT11
const int ldrPin = A0;
const int ledPin = 6;
const int dhtPin = 2;
const int buzzerPin = 3;
DHT dht(dhtPin, DHTTYPE);
const int lightThreshold = 500;
const float maxTemperature = 30.0;
const float maxHumidity = 75.0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();
}
void loop() {
  int lightValue = analogRead(ldrPin);
  digitalWrite(ledPin, lightValue < lightThreshold ? HIGH : LOW);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (!isnan(temperature) && !isnan(humidity)) {
    if (temperature >= maxTemperature || humidity >= maxHumidity) {
      tone(buzzerPin, 1500);
    } else {
      noTone(buzzerPin);
    }
    Serial.print("Light="); Serial.print(lightValue);
    Serial.print(" T="); Serial.print(temperature);
    Serial.print(" C RH="); Serial.print(humidity);
    Serial.println("%");
  } else {
    noTone(buzzerPin);
    Serial.println("DHT11 reading failed");
  }
  delay(2000);
}
