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

void L9110::L9110()
{
  // Pin assignment (Hard encoding these for now)
  // motor A
  int dirPinA7 = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
  int speedPinA9 = 9; // Hook to A-IB - Controls speed for motor A (PWM)
  // motor B
  int dirPinB8 = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
  int speedPinB10 = 10; // Hook to B-IB - Controls speed for motor B (PWM)

  // Setup variables
  int speedA; // 0 (stop) to 255 (full)
  int speedB;
  int dirA; // 0 (backward) or 1 (forward)
  int dirB;

  // Setup the pins
  pinMode(dirPinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  pinMode(dirPinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  
  speedA = 0; // Set speedA to zero
  speedB = 0; // Set speedB to zero
  dirA = 0; //Set variable "dirA" to 1 (forward)
  dirB = 0; //Set variable "dirB" to 1 (forward)
}

// Nothing to see past here until I finish setting up the above
//
//
//
//set motor speed
  analogWrite(speedPinA, speedA); //set speed{A|B} to "0" to come to full stop for that motor
  analogWrite(speedPinB, speedB);
//set direction
  if (1 == dirA) { // Direction for motor A
    digitalWrite(dirPinA, HIGH); // Go forward
  } else {
    digitalWrite(dirPinA, LOW); // Go backward
  }
  if (1 == dirB) { // Direction for motor B
    digitalWrite(dirPinB, HIGH); // Go forward
  } else {
    digitalWrite(dirPinB, LOW); // Go backward
  }


