#include <LiquidCrystal.h>

#include "DHT.h"

#define DHTPIN A1
#define DHTTYPE DHT11

const int LM35 = A3;
float tmppc01;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12,11,5,4,3,2);



void setup() 
{
  
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Medidor de temp");
  lcd.setCursor(0,1);
  lcd.print("configurando...");
  dht.begin();

}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h))
  {
    Serial.println("Falha ao ler o DTH11");
  }
  else
  {
    tmppc01 = (float(analogRead(LM35))*5/(1023))/0.01;

    escrever(h, t, tmppc01);
    /*
    
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(" %t");
    Serial.print("PC : ");
    Serial.print(temperatura);
    Serial.println(" *C");
    */
  }
  delay(1000);
}

void escrever(float hu, float tmp01, float tmp02)
{
  lcd.setCursor(0,0);
  lcd.print("Hum  T01  PC  *C");
  lcd.setCursor(1,1);
  lcd.print(hu);

  lcd.setCursor(6,1);
  lcd.print(tmp01);

  lcd.setCursor(11,1);
  lcd.print(tmp02);
}

