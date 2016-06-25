//http://blog.filipeflop.com/motores-e-servos/micro-servo-motor-9g-sg90-com-arduino-uno.html

#include <Servo.h>

#define SERVO 6

Servo s;
int pos;

void setup() {
s.attach(SERVO);
Serial.begin(9600);
s.write(0);

}

void loop() {
  for(pos = 0; pos < 90; pos++)
  {
    s.write(pos);
    delay(15);
  }

  delay(1000);
  for(pos = 90; pos>=0; pos--)
  {
    s.write(pos);
    delay(15);
  }
  

}
