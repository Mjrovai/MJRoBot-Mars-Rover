#include <Servo.h>
#include "robotDefines.h"

String command;
String device;

// BT Module
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // El pin 10 es Rx y el pin 11 es Tx

//---------------------------------------------
void setup() 
{
  
  Serial.begin(9600);
  BT1.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
   // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  leftServo.attach(6);
  rightServo.attach(5);
  searchServo.attach(3);
  
  searchCmd(50);
  delay(1000);
  
  BT1.print("IoT Capstone Project");
  BT1.println('\n');
}

void loop() 
{
  checkObstacle();
  arduRPiComm(distance);
  checkBTcmd();  // verify if a comand is received from BT remote control
  manualCmd (); 
  command = "";
}


