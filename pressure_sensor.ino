/*
  on Sep 21, 2020
  by MohammedDamirchi
  Home
*/

#include <Q2HX711.h>
#include <Average.h>

const byte MPS_OUT_pin = 2; // OUT data pin
const byte MPS_SCK_pin = 3; // clock data pin
int avg_size = 10; // #pts to average over

Q2HX711 MPS20N0040D(MPS_OUT_pin, MPS_SCK_pin); // start comm with the HX710B
Average<long> ave(avg_size);

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  ave.push(MPS20N0040D.read());
  Serial.println(ave.mean());
}
