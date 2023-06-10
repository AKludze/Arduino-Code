//Load Timer Variables
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;

void setup() {
  // put your setup code here, to run once:
  startMillis = millis();  //initial start time
}

void loop() {
  // put your main code here, to run repeatedly:
    currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  


    
    Serial.print("Sensor_Value:"); Serial.print(Pressure); Serial.print(", ");
    Serial.print("Valve_Open/Close:"); Serial.print(valve_value); Serial.print(", ");
    Serial.println();

}
