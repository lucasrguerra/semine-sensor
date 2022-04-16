#include <Wire.h>
#include <HTU21D.h>
#define groundHumiditySensorPin A0

HTU21D sensor;

void setup()
{
  Serial.begin(9600);
  
  pinMode(groundHumiditySensorPin, INPUT);
  sensor.begin();
}

void loop()
{
  if(sensor.measure()) {
    float temperature = sensor.getTemperature();
    float humidity = sensor.getHumidity();
    
    Serial.print("Temperatura (Ar): ");
    Serial.print(temperature);
    Serial.print("_");
    Serial.print("Umidade (Ar): ");
    Serial.print(humidity);
    Serial.print("_");
  }
  float groundHumidity = 100 - ((analogRead(groundHumiditySensorPin) * 100.0) / 1024.0);
  Serial.print("Umidade (Solo): ");
  Serial.print(groundHumidity);
  Serial.println();
  
  delay(2000);
}
