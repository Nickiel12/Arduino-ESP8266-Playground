#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMStop = Adafruit_MotorShield(); //Initialize the motor shield

// Connect two steppers with 200 steps per revolution (1.8 degree)
// to the shield
Adafruit_StepperMotor *myStepperTurn = AFMStop.getStepper(200, 1); //Attach a stepper motor to motor mount 1, M1 & M2
Adafruit_StepperMotor *myStepperTilt = AFMStop.getStepper(200, 2); //Attach a second stepper motor to motor mount 2, M3 & M4


// you can change these to SINGLE or DOUBLE or INTERLEAVE or MICROSTEP!
//MICROSTEP sets the motor to move in 1/16 steps
//INTERLEAVE sets the motor to move in 1/2 steps
//SINGLE sets the motors to move in 1 steps
//DOUBLE sets the motors to move in 2 steps

// wrappers for the first motor!
void forwardstepTurn() {  
    myStepperTurn->onestep(FORWARD, MICROSTEP);
}
void backwardStepTurn() {  
    myStepperTurn->onestep(BACKWARD, MICROSTEP);
}
// wrappers for the second motor!
void forwardStepTilt() {  
    myStepperTilt->onestep(FORWARD, DOUBLE);
}
void backwardStepTilt() {  
    myStepperTilt->onestep(BACKWARD, DOUBLE);
}

int MaxSpeedMulitplierTilt = 10; //The base multiplier for the steppers speed
int MaxSpeedMulitplierTurn = 10; //change these number to adjust how fast the motors turn

// Now we'll wrap both steppers in an AccelStepper object
AccelStepper stepperTurn(forwardstepTurn, backwardStepTurn);
AccelStepper stepperTilt(forwardStepTilt, backwardStepTilt);

void setup()
{  
	AFMStop.begin(); // Start the top shield

	Serial.begin(19200);  //Begin serial input
  
	//stepperTurn.setMaxSpeed(0); //Begin motors
	//stepperTurn.setAcceleration(2000.0);
    
    stepperTilt.setMaxSpeed(200); //Begin motors
    stepperTilt.setAcceleration(200.0);

}

void loop()
{
    stepperTilt.moveTo(50);
    stepperTilt.run();
    delay(1000);
    stepperTilt.moveTo(150);
    stepperTilt.run();
    delay(1000);
    //stepperTurn.run();
}
