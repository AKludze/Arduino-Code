#include <Tlv493d.h>



// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor1 = Tlv493d();
Tlv493d Tlv493dMagnetic3DSensor2 = Tlv493d();
//Tlv493d Tlv493dMagnetic3DSensor3 = Tlv493d();

//I2C device found at address 0x1F  !
//I2C device found at address 0x5E  !


void setup() {
  Serial.begin(9600);
  while(!Serial);
  Tlv493dMagnetic3DSensor1.begin();
  Tlv493dMagnetic3DSensor2.begin();
  //Tlv493dMagnetic3DSensor3.begin();
}

void loop() {
  Tlv493dMagnetic3DSensor1.updateData();
  //delay(1000);

  Serial.print("X1 = ");
  Serial.print(Tlv493dMagnetic3DSensor1.getX());
  Serial.print(" mT; Y1 = ");
  Serial.print(Tlv493dMagnetic3DSensor1.getY());
  Serial.print(" mT; Z1 = ");
  Serial.print(Tlv493dMagnetic3DSensor1.getZ());
  Serial.println(" mT");
   
  //delay(500);

  Tlv493dMagnetic3DSensor2.updateData();
  //delay(100);

  Serial.print("X2 = ");
  Serial.print(Tlv493dMagnetic3DSensor2.getX());
  Serial.print(" mT; Y2 = ");
  Serial.print(Tlv493dMagnetic3DSensor2.getY());
  Serial.print(" mT; Z2 = ");
  Serial.print(Tlv493dMagnetic3DSensor2.getZ());
  Serial.println(" mT");
   
  delay(500);

 // Tlv493dMagnetic3DSensor3.updateData();
  //delay(100);
//
//  Serial.print("X3 = ");
//  Serial.print(Tlv493dMagnetic3DSensor3.getX());
//  Serial.print(" mT; Y3 = ");
//  Serial.print(Tlv493dMagnetic3DSensor3.getY());
//  Serial.print(" mT; Z3 = ");
//  Serial.print(Tlv493dMagnetic3DSensor3.getZ());
//  Serial.println(" mT");
//   
//  delay(500);
}
