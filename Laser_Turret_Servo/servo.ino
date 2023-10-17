#include <Servo.h> // Included to write to the servos

// Global variables
Servo xServo;
Servo yServo;
int xServoAngle;
int yServoAngle;

// Executes once, at the start
void setup() {
  // Initializes the servo pins and writes 0 to them
  xServo.attach(8);
  yServo.attach(9);
  xServo.write(90);
  yServo.write(90);

  // Begins serial communication
  Serial.begin(9600);
}

// Loops infinitely
void loop() {
  // Gets the values from the processing serial
  if (Serial.available()){
    xServoAngle = Serial.parseInt();
    yServoAngle = Serial.parseInt();
  }

  // Wrtes the angles to the corresponding servos
  xServo.write(xServoAngle);
  yServo.write(yServoAngle);
}