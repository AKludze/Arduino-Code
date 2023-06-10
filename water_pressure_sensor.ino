/************************************************************
   Water pressure sensor demo(Computer serial port)
   - Obtain the water pressure through the output voltage
     of the sensor.
**************************************************************/
//https://wiki.dfrobot.com/Gravity__Water_Pressure_Sensor_SKU__SEN0257
/************************************************************
  Water Sensor Key Parameter
  - Parts No.:KY-3-5
  - Sensing range: 0 - 1 MPa
  - Input Voltage: 5VDC
  - Output Voltage: 0.5 - 4.5 VDC
    (Linearly corresponding to 0 - 1 MPa)
  - Accuary: 0.5% - 1% FS
**************************************************************/

/************************************************************
  Water Sensor Calibration

  The output voltage offset of the sensor is 0.5V (norminal).
  However, due to the zero-drifting of the internal circuit, the
  no-load output voltage is not exactly 0.5V. Calibration needs to
  be carried out as follow.

  Calibration: connect the 3 pin wire to the Arduio UNO (VCC, GND and Signal)
  without connecting the sensor to the water pipe and run the program
  for once. Mark down the LOWEST voltage value through the serial
  monitor and revise the "OffSet" value to complete the calibration.

  After the calibration the sensor is ready for measuring!
**************************************************************/

const float  OffSet = .476;
float sensorRating = 300; // 300 mmHg 
int analog_offset = 112;  // Raw Analog Output
int full_scale = 922 ; //Arduino Reads between 0 to 1023 analog (922 is realistic max)
float pressure;

float V, P;

void setup()
{
  Serial.begin(9600);        // open serial port, set the baud rate to 9600 bps
  Serial.println("/** Water pressure sensor demo **/");
}
void loop()
{
  Serial.println(analogRead(0)); 
  //Connect sensor to Analog 0
  //V = analogRead(0) * 5.00 / 1024.0;     //Sensor output voltage
  
  //P = (V - OffSet) * 250;             //Calculate water pressure

  //Serial.print("Voltage:");
  //Serial.print(V, 3);
  //Serial.println("V");

  pressure = (analogRead(0) -  analog_offset)*sensorRating / (full_scale -  analog_offset); 
  Serial.print(" Pressure:");
  Serial.print(pressure, 1);
  Serial.println("  mmHg");
  Serial.println();

  delay(500);
}
