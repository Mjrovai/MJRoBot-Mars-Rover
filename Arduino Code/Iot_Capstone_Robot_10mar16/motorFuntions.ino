

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

