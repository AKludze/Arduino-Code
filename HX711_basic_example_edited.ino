#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;
float ADC_val_avg; 
float Pressure; 

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    ADC_val_avg = scale.read_average(20);
    Serial.println(ADC_val_avg);    // print the average of 20 readings from the ADC
    // equation from calibration curve: y = x*1*10^{-4}-13.825 where x is the ADC value
    Pressure  =  ADC_val_avg *1* pow(10, -4) - 13.825;    // units: mmHg
    Serial.print("Pressure reading (mmHg): ");
    Serial.println(Pressure);
    //Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  // voltage = ADC * 5 / 16777213
  
}
