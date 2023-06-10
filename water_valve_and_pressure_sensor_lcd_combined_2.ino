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
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const float  OffSet = 0.508 ;
float V;
int P;
int led = 13;
int Po = 64.8; //Initial Pressure Value 
unsigned int lcd_r = 0, lcd_g = 0, lcd_b = 0;
unsigned long delaytime = 0, lighttime = 0;
int solenoidPin = 3;

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  
  delay(5000);
  Serial.begin(9600);
  Serial.println("hello start");
  lighttime = millis();
  lcd.setCursor(0, 0);
  
  lcd.print("Water Pressure:");
  pinMode(led, OUTPUT);
  pinMode(solenoidPin, OUTPUT); //Sets the pin as an output
  
}
void loop() {
  V = analogRead(0)* 5.00 / 1024;                     //Sensor output voltage
  Serial.print("Voltage:");
  Serial.print(V, 3);
  Serial.println("V");
  P = (V - OffSet) * 250*10*7.501;                          //Calculate water pressure * 7.501
  lcd.setCursor(3, 1);
  delay(500);
  
  lcd.print(  P/ 10000% 10);                         //LCD display
  lcd.print(  P/ 1000% 10);
  lcd.print(   P/ 100 % 10);
  lcd.print(   P/ 10 % 10);
  lcd.print('.');
  lcd.print(  P  % 10);
  lcd.print(' ');
  lcd.print("mmHG");
  
  delay(500);
  digitalWrite(led,HIGH);
  digitalWrite(solenoidPin, HIGH); //Switch Solenoid ON
  delay(3000); //Wait 1 Second
  
  //digitalWrite(led,LOW);
  //digitalWrite(solenoidPin, LOW); //Switch Solenoid OFF
  //delay(3000); //Wait 1 Second

}
