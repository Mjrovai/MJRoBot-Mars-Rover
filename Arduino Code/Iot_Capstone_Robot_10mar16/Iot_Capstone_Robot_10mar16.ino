#include <Servo.h>
#include "robotDefines.h"


//---------------------------------------------
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  leftServo.attach(6);
  rightServo.attach(5);
  
  while(digitalRead(buttonPin))
 {  
 }

 motorTurn (LEFT, 500);
 motorTurn (RIGHT, 500);

}



void loop() 
{
 
}
