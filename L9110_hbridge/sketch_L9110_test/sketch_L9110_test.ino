// Test sketch for L9110 H-Bridge controller
//
// Voltage: 2.5V-12V
// Max Continuous Current: 800 mA
//
// Logic diagram:
// ______________
// |IA|IB||OA|OB|
// |--|--||--|--|
// |H |L || H| L|
// |--|--||--|--|
// |L |H || L| H|
// |--|--||--|--|
// |L |L || L| L|
// |--|--||--|--|
// |H |H || L| L|
// |------------|

// Pin assignment
// motor A
int dirPinA = 7; // Hook to A-IA - Controls direction for motor A, high = forward, low = reverse
int speedPinA = 9; // Hook to A-IB - Controls speed for motor A (PWM)
// motor B
int dirPinB = 8; // Hook to B-IA - Controls direction for motor B, high = forward, low = reverse
int speedPinB = 10; // Hook to B-IB - Controls speed for motor B (PWM)

// Setup variables
unsigned long time;

int speed;
int dir;

// Setup the pins
void setup() {
  pinMode(dirPinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  
  pinMode(dirPinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  
  time = millis(); // Set variable "time" to current # of milliseconds since program started
  speed = 0; // Set speed to zero
  dir = 1; //Set variable "dir" to 1 (forward)
}

// Loop for testing motors/controller
void loop () {
  
  //set speed
  analogWrite(speedPinA, speed);
  analogWrite(speedPinB, speed);
  //set direction
  if (1 == dir) {
    digitalWrite(dirPinA, HIGH); // Go forward
    digitalWrite(dirPinB, HIGH);
  } else {
    digitalWrite(dirPinA, LOW); // Go backward
    digitalWrite(dirPinB, LOW);
  }

  // Change speed and direction every 5 seconds
  if (millis() - time > 5000) {
    time = millis(); // Set "time" to current millis() value
    speed += 20; // Increment speed by 20
    if (speed > 255) {
      speed = 0; // If speed has gone over 255, set back to zero, otherwise continue
    }
    
    // Cycle direction
    if (1 == dir) {
      dir = 0;
    } else {
      dir = 1;
    }
  }
}
