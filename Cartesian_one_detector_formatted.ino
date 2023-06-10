#include <Tlv493d.h>

// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();

//Load Timer Variables/Plotting Variables
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;


void setup() {
  Serial.begin(9600);
  while(!Serial);
  Tlv493dMagnetic3DSensor.begin();
  startMillis = millis();  //initial start time
  Serial.println("X, Y, Z, Time");
}

void loop() {
  Tlv493dMagnetic3DSensor.updateData();
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)

  
  //Serial.print(Tlv493dMagnetic3DSensor.getX());
  //Serial.print(Tlv493dMagnetic3DSensor.getY());
  //Serial.print(Tlv493dMagnetic3DSensor.getZ());


  Serial.print(Tlv493dMagnetic3DSensor.getX()); Serial.print(", ");
  Serial.print(Tlv493dMagnetic3DSensor.getY()); Serial.print(", ");
  Serial.print(Tlv493dMagnetic3DSensor.getZ()); Serial.print(", ");
  Serial.print(currentMillis/1000); Serial.print(", ");
  Serial.println();
   
  delay(500);
}
