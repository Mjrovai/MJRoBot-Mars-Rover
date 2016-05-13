
void motorStop()
{
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);
  delay(200);
}

//--------------------------------------------- 
void motorForward()
{
  leftServo.writeMicroseconds(1500 - power);
  rightServo.writeMicroseconds(1500 + power*adj);
}

//---------------------------------------------
void motorBackward()
{
  leftServo.writeMicroseconds(1500 + power);
  rightServo.writeMicroseconds(1500 - power);
}

//---------------------------------------------
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
}

//---------------------------------------------
void motorBwTime (unsigned int time)
{
  motorBackward();
  delay (time);
  motorStop();
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
void searchCmd(int value)
{
  searchServoPosition = map (value, 0, 100, 25, 180);
  searchServo.write(searchServoPosition);
  delay (15);
}
