#include <Servo.h>

Servo leftServo;
Servo rightServo;

void setup() 
{
  leftServo.attach(6);
  rightServo.attach(5);
  
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);

}

void loop() 
{
  
}
