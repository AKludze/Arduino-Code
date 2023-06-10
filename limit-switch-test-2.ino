const byte xLimitPin = 9;
const byte yLimitPin = 10;
const byte zLimitPin = 11;
//correct!

void setup()
{
   Serial.begin(9600);
   pinMode(xLimitPin, INPUT_PULLUP);
   pinMode(yLimitPin, INPUT_PULLUP);
   pinMode(zLimitPin, INPUT_PULLUP);
}

void loop()
{

  if (digitalRead(xLimitPin) ==  HIGH){
    Serial.print("its pressed x-lim");
  }

  if (digitalRead(yLimitPin) ==  HIGH){
    Serial.print("its pressed y-lim");
  }


}
