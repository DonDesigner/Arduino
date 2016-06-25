//http://www.arduinoecia.com.br/2014/01/controlando-um-servo-motor-utilizando.html

#include <Servo.h>

Servo myservo;

int val;

void setup() {
  myservo.attach(7);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() >= 2 )
  {
    int key = Serial.read();
    int val = Serial.read();
    myservo.write(val);
  }

}
