#include <Servo.h>

///////////////
// Constants //
///////////////
int const servoOutputPin = 9;
int const serialBaudRate = 9600;

//////////////////
// Ugly Globals //
//////////////////
Servo servo;
int servoAngle = 0;
//int delayCounter = 0;

/////////////////////////
// Function prototypes //
/////////////////////////
int SanitizeServoAngle (int servoAngle);
int UpdateServoAngle (int command, int servoAngle);

////////////////////////////
// Main Arduino Functions //
////////////////////////////
void setup()
{
  servo.attach(servoOutputPin);
  Serial.begin(serialBaudRate);
  
  // Set the angle to 0.
  servo.write(0);
}

void loop()
{
  int command = -1;
  
  if (Serial.available() > 0) {
    command = Serial.read();
  }

  const int previousServoAngle = servoAngle;
  servoAngle = UpdateServoAngle(command, servoAngle);

//  if (delayCounter > 1500)
//  {
//    delayCounter = 0;
//    Serial.print("Angle: ");
//    Serial.println(servoAngle);
//  }

  if (previousServoAngle != servoAngle) {
    servo.write(servoAngle);
  }
  
//  delayCounter += 15;
  delay(20);
}

//////////////////////////////
// Function Implementations //
//////////////////////////////
int SanitizeServoAngle (int servoAngle)
{
  if (servoAngle < 0) {
    return 0;
  }

  else if (servoAngle > 179) {
    return 179;
  }

  return servoAngle;
}

int UpdateServoAngle (int command, int servoAngle)
{
  switch (command)
  {
    case 'L' :
      servoAngle -= 10;
      break;
    case 'R' :
      servoAngle += 10;
      break;
  }

  return SanitizeServoAngle(servoAngle);  
}

