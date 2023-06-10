/************************************************************
   Water Pressure Sensor, Water/Solenoid Valve, and 
   LCD Display System 
   - Ave Kludze, Biofoundry.
**************************************************************/

//Load Librariesd
#include "HX711.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//Load Variables
int led = 13;
int num_samples = 5; 
unsigned int lcd_r = 0, lcd_g = 0, lcd_b = 0;
unsigned long delaytime = 0, lighttime = 0;
float H_limit = 5.0; //high water pressure limit
float L_limit =  2.0;//low water pressure limit

//Load Timer Variables/Plotting Variables
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;
float ADC_val_avg; 
float Pressure; 
volatile float f;

//Relay Board
const int RELAY_ENABLE = 1;

// System Delays
int valve_delay = 1000;
int LCD_delay = 500; 

HX711 scale;

void setup() {
  // put your setup code here, to run once:
  
  startMillis = millis();  //initial start time

  //SetUp for Pressure Sensor
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); // initialize the pressure sensor 

  //SetUp for LCD 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  
  Serial.begin(115200);
  Serial.println("hello start");
  lighttime = millis();
  lcd.setCursor(0, 0);

  //SetUp for Water Valve
  lcd.print("Water Pressure:");
  pinMode(led, OUTPUT);
  pinMode(RELAY_ENABLE,OUTPUT);
  digitalWrite(RELAY_ENABLE,LOW);
  Serial.begin(115200);
  
  
}

void loop() {
  
  // put your main code here, to run repeatedly:

  // Order: 1) Calculate Water Pressure 2) Display Water Pressure on LCD 
  //        3) Open or Close Water Valve based on Water Pressure 4) Repeat Process 

  // 1) Water Pressure Sensor Main Code
   
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  
  if (scale.is_ready()) {
    long reading = scale.read();

    //TEST:
    //f = scale.get_units(5);
    //Serial.println(f);


    //INSTANT:
    //Serial.print("HX711 reading: ");
    //Serial.println(reading);
    //Pressure  =  reading *0.00009-10; //- 10; // // units: mmHg
    //Serial.print("Pressure Reading (mmHg): ");
    //Serial.println(Pressure);

    //AVERAGE:
    Serial.print("HX711 reading (average): ");
    ADC_val_avg = scale.read_average(num_samples);
    Serial.println(ADC_val_avg);    // print the average of 20 readings from the ADC
    Pressure  =  ADC_val_avg *0.00009-10; //- 10; // // units: mmHg
    Serial.print("Average Pressure Reading (mmHg): ");
    Serial.println(Pressure);
    Serial.print("Time (seconds): ");
    Serial.println(currentMillis/1000);
    //delay(500);
    // NOTE: 
    // equation from calibration curve: y = x*1*10^{-4}-13.825 where x is the ADC value
    // 9E-05x
    
  } else {
    Serial.println("HX711 not found.");
  }
  
  //delay(valve_delay);

  // 2) Load LCD Display with Water Pressure Valve 
  lcd.setCursor(3, 1);
  //delay(LCD_delay);
  lcd.print(Pressure);

  // 3) Open or Close Water/Solenoid Valve
  //delay(valve_delay); //Wait 1 Second
  
  if (Pressure > H_limit){ // Pressure Too HIGH. Open Valve.
    Serial.println("Pressure Too HIGH. Open Valve");  //CHANGE TO LCD 
    Serial.println("Relay On");
    digitalWrite(RELAY_ENABLE, HIGH);
    //delay(valve_delay); //Wait 1 Second

  }
  else if (Pressure < L_limit){ // Pressure Too LOW. Close Valve. 
    Serial.println("Pressure Too LOW. Close Valve");
    Serial.println("Relay OFF");
    digitalWrite(RELAY_ENABLE,LOW);
    //Serial.println(digitalRead(RELAY_ENABLE));
    //delay(valve_delay); //Wait 1 Second
  }
  //delay(valve_delay); //Wait 1 Second

//float H_limit = 50.0; //high water pressure limit
//float L_limit =  20 //low water pressure limit
//LCD Prints: Pressure & Valve/Open/Cloze
}
