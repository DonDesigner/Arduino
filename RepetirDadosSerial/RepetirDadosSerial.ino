const int LED = 13;

void setup() 
{
  Serial.begin(9600);  //inicia comunicação serial com 9600
  pinMode(LED, OUTPUT);
}
 
void loop()
{
  if(Serial.available())        //se algum dado disponível
  {
    switch(Serial.read())
    {
      case 'A':
        digitalWrite(LED, !digitalRead(LED));
      break;
    }
  }
}
