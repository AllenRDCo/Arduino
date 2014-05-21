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
  int dirPinA7 = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
  int speedPinA9 = 9; // Hook to A-IB - Controls speed for motor A (PWM)
  // motor B
  int dirPinB8 = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
  int speedPinB10 = 10; // Hook to B-IB - Controls speed for motor B (PWM)

  // Set pin modes
  pinMode(dirPinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);

  pinMode(dirPinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  
}


void L9110::motorA(int dirA, int speedA) // Accept input for direction and speed for motor A
{
  
  analogWrite(speedPinA, speedA); //set speed{A|B} to "0" to come to full stop for that motor

  //set direction
  if (1 == dirA) { // Direction for motor A
    digitalWrite(dirPinA, HIGH); // Go forward
  } else {
    digitalWrite(dirPinA, LOW); // Go backward (or stop if speed is set to "0")
  }
}

void L9110::motorB(int dirB, int speedB) // Accept input for direction and speed for motor B
{
  
  analogWrite(speedPinB, speedB); //set speed{A|B} to "0" to come to full stop for that motor

  //set direction
  if (1 == dirB) { // Direction for motor A
    digitalWrite(dirPinB, HIGH); // Go forward
  } else {
    digitalWrite(dirPinB, LOW); // Go backward (or stop if speed is set to "0")
  }
}
