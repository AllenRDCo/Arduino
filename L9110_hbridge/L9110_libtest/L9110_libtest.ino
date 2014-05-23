// Test L9110 library

#include <L9110.h>

L9110 L9110;

// setup pin for LiPo monitor
int LiPoMonitor = 2;


void setup()
{
  pinMode(LiPoMonitor, INPUT);
}

void loop()
{
  if (digitalRead(LiPoMonitor) == LOW)
  {
    L9110.motorA(1,255); //run both motors forward at full speed
    L9110.motorB(1,255);
    delay(5000);
    L9110.motorA(0,255); //run both motors backward at full speed
    L9110.motorB(0,255);
    delay(5000);
    L9110.motorA(1,127); //run both motors forward at half speed
    L9110.motorB(1,127);
    delay(5000);
    L9110.motorA(1,255); //run motors at half speed in opposite directions
    L9110.motorB(0,255);
    delay(5000);
    L9110.motorA(0,0); //full stop on both motors
    L9110.motorB(0,0);
    delay(3000);
  }
}

