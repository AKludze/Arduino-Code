#include <AccelStepper.h>
//Link: https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html
//Motor: https://www.amazon.com/STEPPERONLINE-Stepper-Bipolar-Connector-compatible/dp/B00PNEQKC0
//https://www.youtube.com/watch?v=YJSmrbeZUp4
//https://www.youtube.com/watch?v=hL2NtjQiJ5w

AccelStepper Xaxis(1, 2, 5); // pin 2 = stepper pin, pin 5 = direction pin, 
const byte enablePin = 8; //enable pin on the DRV8825
//const float maxspd;  //Set Maximum Speed;  steps per second
const float spd = 70;
int counter = 0;

const byte xLimitPin = 9;
const byte yLimitPin = 10;
const byte zLimitPin = 11;

int distanceToMove = 150; //(mm)
int numberOfSteps = distanceToMove*84.2;

void setup()
{
   Serial.begin(9600);
   pinMode(enablePin, OUTPUT); //Must enable pins on DRV8825
   pinMode(xLimitPin, INPUT_PULLUP);
   digitalWrite(enablePin, LOW); //Must enable pins on DRV8825
   //Xaxis.setMaxSpeed(1500); //Max speed
   Xaxis.setSpeed(-500);
   //Xaxis.setAcceleration(200);
   Xaxis.moveTo(3000);
   
}

//void flipcheck()
//{
//  
//  if (digitalRead(xLimitPin) == LOW){
//    Serial.print("its pressed");
//    Xaxis.moveTo(-Xaxis.currentPosition());
//  }
//}

void loop()
{

  if (Xaxis.distanceToGo() == 0 ){
    Xaxis.moveTo(-Xaxis.currentPosition());
    //flipcheck();
  }
  Xaxis.run();
  
  




}

//https://www.forward.com.au/pfod/Robots/SpeedStepper/index.html

//limit switch
