
//      ******************************************************************
//      *                                                                *
//      *   Example of finding the Home position using a limit switch    *
//      *                                                                *
//      *            S. Reifel & Co.                6/24/2018            *
//      *                                                                *
//      ******************************************************************


// Many stepper motor projects need to move to exact positions.  This usually 
// requires that the stepper motor library knows where the motor is before it 
// makes its first move.  To achieve this automatically, you will use a 
// Limit Switch that is pressed by the mechanism when the motor moves 
// all-the-way to one end of its travel.  This procedure called "Homing", is 
// executed when power is first applied.  A homing program moves the motor 
// toward the limit switch until the switch is pressed, then resets the  
// library so that the motor is now at position 0.
//
// Home automatically is easily done using one of these functions:
//    moveToHomeInSteps()
//    moveToHomeInRevolutions()
//    moveToHomeInMillimeters()
//
// This example shows how to home your device.  The mechanism in my example has 
// a stepper motor with a lead-screw.  On its left side is a limit switch that 
// the mechanism bumps into when the motor has reached its left most limit of 
// travel.  Note: The switch must be configured to go LOW when pressed at the
// home position. 
//
// Documentation at:
//    https://github.com/Stan-Reifel/SpeedyStepper
//
//
// The motor must be connected to the Arduino with a driver board having a 
// "Step and Direction" interface.  It's VERY important that you set the 
// motor current first!  Read the driver board's documentation to learn how.

// ***********************************************************************


#include <SpeedyStepper.h>


//
// pin assignments
//
const int LED_PIN = 13;
const int MOTOR_X_STEP_PIN = 2;
const int MOTOR_Y_STEP_PIN = 3;
const int MOTOR_Z_STEP_PIN = 4;
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int MOTOR_Z_DIR_PIN = 7;
const int STEPPERS_ENABLE_PIN = 8;
const int LIMIT_SWITCH_X_PIN = 9;
const int LIMIT_SWITCH_Y_PIN = 10;
const int LIMIT_SWITCH_Z_PIN = 11;
const int SPINDLE_ENABLE_PIN = 12;
const int SPINDLE_DIRECTION_PIN = 13;


//
// create the stepper motor objects
//
SpeedyStepper stepperX;
SpeedyStepper stepperY;


void setup() 
{
  // setup the LED pin and enable print statements
  //
  pinMode(LED_PIN, OUTPUT);   
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  Serial.begin(9600);


  //
  // connect and configure the stepper motor to there IO pins
  //
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  stepperY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);


  //
  // enable the stepper motors
  //
  digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this
}



void loop() 
{

}
