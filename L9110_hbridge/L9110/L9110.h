/* L9110.h -  Library for controlling the L9110 H-Bridge board
   Created by Paul Allen, May 20, 2014
   MIT License

   Voltage: 2.5V-12V
   Max Continuous Current: 800 mA

   Logic diagram:
   ______________
   |IA|IB||OA|OB|
   |--|--||--|--|
   |H |L || H| L|
   |--|--||--|--|
   |L |H || L| H|
   |--|--||--|--|
   |L |L || L| L|
   |--|--||--|--|
   |H |H || L| L|
   |------------|

*/

#ifndef L9110_h
#define L9110_h

#include "Arduino.h"

class L9110
{
  public:
    L9110();
    void motorA(int dirA, int speedA);
    void motorB(int dirB, int speedB);
  private:
    // motor A
    int dirPinA7 = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
    int speedPinA9 = 9; // Hook to A-IB - Controls speed for motor A (PWM)
    // motor B
    int dirPinB8 = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
    int speedPinB10 = 10; // Hook to B-IB - Controls speed for motor B (PWM)
};

#endif
