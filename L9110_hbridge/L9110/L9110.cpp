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

#include "Arduino.h"
#include "L9110.h"

void L9110::L9110() // setup constructor for the library
{
  // Pin assignment (Hard encoding these for now)
  // motor A
  int dirPinA = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
  int speedPinA = 9; // Hook to A-IB - Controls speed for motor A (PWM)
  // motor B
  int dirPinB = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
  int speedPinB = 10; // Hook to B-IB - Controls speed for motor B (PWM)

  // Set pin modes
  pinMode(dirPinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  pinMode(dirPinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
}


void L9110::motorA(int dirA, int speedA) // Accept input for direction and speed for motor A
{
  //set direction
  if (1 == dirA) { // Direction for motor A
    speedA -= 255 // Must invert speed # to retain sanity for forward
    digitalWrite(dirPinA, HIGH); // Go forward
    analogWrite(speedPinA, speedA); // 255 = full stop, 0 = full power
  } else {
    digitalWrite(dirPinA, LOW); // Go backward
    analogWrite(speedPinA, speedA); // 0 = full stop, 255 = full power
  }
}

void L9110::motorB(int dirB, int speedB) // Accept input for direction and speed for motor B
{
  //set direction
  if (1 == dirB) { // Direction for motor B
    speedB -= 255 // Must invert speed # to retain sanity for forward
    analogWrite(speedPinB, speedB); // 255 = full stop, 0 = full power
    digitalWrite(dirPinB, HIGH); // Go forward
  } else {
    analogWrite(speedPinB, speedB); // 0 = full stop, 255 = full power
    digitalWrite(dirPinB, LOW); // Go backward
  }
}
