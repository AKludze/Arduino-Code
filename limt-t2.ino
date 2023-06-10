#define EN        8  
#define X_DIR     5 
#define X_STP     2

int delayTime=15; //Delay between each pause (uS)
long int stps=12800;// microsteps per revolution with 1/32 microstepping
const int limitPin = 9; //enable limitPin 

void step(boolean dir, byte dirPin, byte stepperPin, long int steps)

{
  Serial.begin(9600);
  digitalWrite(dirPin, dir);

  delay(100);

  for (long int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime); 

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime); 

  }
}

void setup() {
pinMode(X_DIR, OUTPUT); 
pinMode(X_STP, OUTPUT);
pinMode(EN, OUTPUT);
digitalWrite(EN, LOW);
INPUT_PULLUP.(limitPin, INPUT);
}

void loop() {
 while( digitalRead(limitPin) == HIGH){
    step(false, X_DIR, X_STP, stps);
    if( digitalRead(limitPin) == LOW
    {
       Serial.println("The limit switch: UNTOUCHED -> TOUCHED");
    }
}
