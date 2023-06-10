#include <Tlv493d.h>
//serial.Serial('COM9', 6800, timeout=1)
//https://pythonforundergradengineers.com/python-arduino-potentiometer.html
//https://github.com/archie-swif/serial-plotter-3d/blob/master/plotter/plotter_serial_scatter.py

// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Tlv493dMagnetic3DSensor.begin();
}

void loop() {
  Tlv493dMagnetic3DSensor.updateData();
  delay(100);

  //Serial.print("X, Y, Z");
  //Serial.print(Tlv493dMagnetic3DSensor.getX());
  //Serial.print(Tlv493dMagnetic3DSensor.getY());
  //Serial.print(Tlv493dMagnetic3DSensor.getZ());
  //Serial.print(Tlv493dMagnetic3DSensor.getX(), Tlv493dMagnetic3DSensor.getY(), Tlv493dMagnetic3DSensor.getZ())

  Serial.print(Tlv493dMagnetic3DSensor.getX()); Serial.print(", ");
  Serial.print(Tlv493dMagnetic3DSensor.getY()); Serial.print(", ");
  Serial.print(Tlv493dMagnetic3DSensor.getZ()); Serial.print(" ");
  Serial.println();
   
  delay(500);
}
