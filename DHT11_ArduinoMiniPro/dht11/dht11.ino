#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = 3;
int led2 = 4;


void setup()
{
  Serial.begin(9600);
  Serial.println("DHT 11 Testando Programa");

  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  Serial.println("\n");
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
  digitalWrite (led2, HIGH);
  digitalWrite (led, HIGH);
}

