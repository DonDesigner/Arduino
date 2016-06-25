//http://blog.filipeflop.com/motores-e-servos/potenciometro-controlando-servo-motor.html

#include "Servo.h"


Servo servo1;

boolean inicio = true;
int reto = 90;

void setup() {
 servo1.attach(5); //Pin 5

 
 
 Serial.begin(9600);

 
}



void loop() {
  //Lê o valor do potenciometro
  int angle = analogRead(0);

  //Mapeia o valor de 0 a 180 graus
  angle = map(angle, 0, 1023, 67, 104);


    servo1.write(angle);

  //repassa o angulo ao ServoWrite
  
  Serial.print("Angulo: ");
  Serial.println(angle);
  
  //Delay para que o servo alcance a posição
  delay(15);

  
}
