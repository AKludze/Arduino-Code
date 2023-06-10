int solenoidPin = 5; //This is the output pin on the Arduino we are using

void setup() {
  // put your setup code here, to run once:
  pinMode(solenoidPin, OUTPUT); //Sets the pin as an output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(solenoidPin, HIGH); //Switch Solenoid ON; //Wait 1 Second
  delay(1000);
  digitalWrite(solenoidPin, LOW); //Switch Solenoid OFF
  delay(1000);
}
