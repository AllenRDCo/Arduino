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

   Example to use library, set L9110.motorA(1,255) to have motor A go forward at full speed
   Setting L9110.motorA(0,255) will run motor A backwards at full speed
   Setting L9110.motorA(0,0) will put motor at full stop
   Use integer from 0 to 255 to control speed of motor 
     
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
    void forward();
    void reverse();
    void forwardSlow();
    void reverseSlow();
    void left();
    void right();
    void fullStop();
  private:
    // motor A
    int dirPinA = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
    int speedPinA = 5; // Hook to A-IB - Controls speed for motor A (PWM)
    // motor B
    int dirPinB = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
    int speedPinB = 6; // Hook to B-IB - Controls speed for motor B (PWM)
};

#endif
