#include <Servo.h>

Servo myservo;

int potPin = 2;    // select the input pin for the potentiometer
int servoPin = 9;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  myservo.write(val/10);
}