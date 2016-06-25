//http://www.ajudino.com/2013/04/3-utilizando-potenciometro-no-arduino.html
// 12/03/2016

int potenciometro = 0;
int valor = 0;
int led = 6;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
}

void loop() {
  valor = analogRead(potenciometro);
  if(valor >0){
    analogWrite(led, (valor/4));
    Serial.println(valor);  
  }
}
