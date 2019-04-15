#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);
int potPin = 2;
int val = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(200);
}

void loop()
{
  val = analogRead(potPin);
  stepper.setSpeed(val/10);
  Serial.println("Forward");
  stepper.
}