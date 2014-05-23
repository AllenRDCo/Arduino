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
    L9110.forward();
    delay(3000);
    L9110.fullStop();
    delay(500);
    L9110.reverse();
    delay(3000);
    L9110.fullStop();
    delay(500);
    L9110.forwardSlow();
    delay(3000);
    L9110.fullStop();
    delay(500);
    L9110.reverseSlow();
    delay(3000);
    L9110.fullStop();
    delay(500);
    L9110.left();
    delay(1500);
    L9110.fullStop();
    delay(500);
    L9110.right();
    delay(1500);
    L9110.fullStop();
    delay(3000);
  }
}
