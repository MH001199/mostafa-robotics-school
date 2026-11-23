#include <DHT.h>

const uint8_t DHT_PIN = 4;
const uint8_t PIEZO_PIN = 7;
const float TEMP_LIMIT_C = 30.0;
const float HUMIDITY_LIMIT = 75.0;

DHT dht(DHT_PIN, DHT22);

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2500);  // Also allows the sensor to settle on the first read.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    noTone(PIEZO_PIN);
    Serial.println(F("DHT read failed"));
    return;
  }

  Serial.print(temperature);
  Serial.print(F(" C, "));
  Serial.print(humidity);
  Serial.println(F(" %RH"));

  if (temperature >= TEMP_LIMIT_C || humidity >= HUMIDITY_LIMIT) {
    tone(PIEZO_PIN, 880, 180);
  }
}
