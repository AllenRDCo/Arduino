// Test L9110 library

#include <L9110.h>

L9110 L9110;

void setup()
{
}

void loop()
{
  L9110.motorA(1,255);
  L9110.motorB(1,255);
}

