#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  dht.begin();
   
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h))
  {
    Serial.println("Falha na leitura do Sensor DHT11");
  }
  else
  {
    Serial.print("{");
    Serial.print("\"");
    Serial.print("h");
    Serial.print("\"");
    Serial.print(":");
    Serial.print(h);
    Serial.print(",\"");
    Serial.print("t");
    Serial.print("\"");
    Serial.print(":");
    Serial.print(t);
    Serial.println("}");
    
    
  }
  delay(500);
}
