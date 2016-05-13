
 void checkBTcmd()  
 { 
   while (BT1.available())   //Check if there is an available byte to read
   {
     delay(10); //Delay added to make thing stable 
     char c = BT1.read(); //Conduct a serial read
     device += c; //build the string.
   }  
   if (device.length() > 0) 
   {
     Serial.print("Command received from BT ==> ");
     Serial.println(device); 
     command = device;
     device ="";  //Reset the variable
     BT1.flush();
    } 
}


//------------------------------------------------------------------------
void manualCmd()
{
  switch (command[0])
  {
    case 'f': 
      motorStop(); //turn off both motors
      break;

    case 'w':  
      motorForward();  
      break;

    case 'd':     
      motorTurn(RIGHT, 300);
      motorStop();
      
      break;

   case 'a': 
      motorTurn(LEFT, 300);
      motorStop();
      break;
    
    case 's':  
      motorBackward();
      break;
      
    case 'b':
      searchCmd(command[2]);
      break;
  }
}

//------------------------------------------------------------------------
int distMeter () // read the ultrasonic sensor distance
{ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 
  distance = duration/58.2; //Calculate the distance (in cm) based on the speed of sound.
 
  if (distance >= maximumRange || distance <= minimumRange)
   {
   Serial.println("-1"); // Send a negative number to computer and Turn LED ON to indicate "out of range" 
   // FAZER ALGO?????
   }
   else    // Send the distance to the computer using Serial protocol, and turn LED OFF to indicate successful reading. 
   {
    Serial.print("                       Distance: ");
    Serial.println(distance);
    Serial.println("");

    return distance;
   }
   delay(50);  //Delay 50ms before next reading.
}


//------------------------------------------------------------------------
void checkObstacle () // check for front obstacles

{
   if (distMeter() < COLL_DIST)     // if forward is blocked change direction
    {                                    
      motorStop();  
      motorBwTime (200);
      digitalWrite (ledPin, HIGH);
      BT1.print("WARNING OBSTACLE AT ");
      BT1.print(distance);
      BT1.print(" cm");
      BT1.println('\n');
      digitalWrite (ledPin, LOW);
    }
}
