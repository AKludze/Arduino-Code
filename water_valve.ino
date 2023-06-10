int solenoidPin = 5; //This is the output pin on the Arduino we are using
int led = 13; 
int a;
void setup() {
// put your setup code here, to run once:
//  pinMode(led, OUTPUT);
  pinMode(solenoidPin, OUTPUT); //Sets the pin as an output
  Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
  //digitalWrite(led,LOW);
  digitalWrite(solenoidPin, HIGH);
  a = random(6);
  if (a > 3){
    digitalWrite(solenoidPin, HIGH); //Switch Solenoid ON; //Wait 1 Second
    Serial.println("relay on");
  }
  else if (a < 3){
    digitalWrite(solenoidPin, LOW); //Switch Solenoid OFF
    Serial.println("relay off");
  }
  delay(5000);
  //digitalWrite(led,HIGH);


}
