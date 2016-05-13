#include <Servo.h>

#define RIGHT 1
#define LEFT -1

Servo leftServo;
Servo rightServo;

const byte ledPin = 13;
const byte buttonPin = 9;

const byte power = 500;

int adj = 1;

//---------------------------------------------
void motorStop(int time =200)
{
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);
  delay(time);
}

//---------------------------------------------
void motorForward()
{
  leftServo.writeMicroseconds(1500 - power);
  rightServo.writeMicroseconds(1500 + power*adj);
}

//---------------------------------------------
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
}

//---------------------------------------------
void motorBackward()
{
  leftServo.writeMicroseconds(1500 + power);
  rightServo.writeMicroseconds(1500 - power);
}

//---------------------------------------------
void motorTurn(int direction, int time)
{
  leftServo.writeMicroseconds(1500 - power*direction);
  rightServo.writeMicroseconds(1500 - power*direction);
  delay (time);
  motorStop();
}

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
