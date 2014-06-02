//Roborover Core

//add libraries
#include <NewPing.h>
#include <Servo.h>
#include <L9110.h>

L9110 L9110;

// setup pin for LiPo Monitor
int LiPoMonitor = 2;
// setup servo and sonar module
NewPing sonar(4,3);
Servo sonarServo;

void setup()
{
  pinMode(LiPoMonitor, INPUT);
  sonarServo.attach(9);
  Serial.begin(115200);
}

void loop()
{
  while(getFrontDistance() < 30)
  {
    L9110.fullStop();
    if (getRightDistance() >= getLeftDistance())
    {
      L9110.right();
      //delay(250);
    }else{
      L9110.left();
      //delay(250);
    }
  }
  L9110.forward();
  delay(100);
  
} 

// Get distance to the front of the robot
float getFrontDistance() 
{
  sonarServo.write(90);
  delay(1500);
  int frontDistance = sonar.ping_cm();
  Serial.print("Ping front ");
  Serial.print(frontDistance);
  Serial.println(" cm");
  return frontDistance;
}

// get distance to the left
float getLeftDistance()
{
  sonarServo.write(180);
  delay(1500);
  int leftDistance = sonar.ping_cm();
  Serial.print("Ping left ");
  Serial.print(leftDistance);
  Serial.println(" cm");
  sonarServo.write(90);
  return leftDistance;
}

// get distance to the right
float getRightDistance()
{
  sonarServo.write(0);
  delay(1500);
  int rightDistance = sonar.ping_cm();
  Serial.print("Ping right ");
  Serial.print(rightDistance);
  Serial.println(" cm");
  sonarServo.write(90);
  return rightDistance;
}
