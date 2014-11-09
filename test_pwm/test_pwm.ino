int ledPin = 3;    
 
void setup()
{
    pinMode(ledPin, OUTPUT);     
}
 
void loop()
{
  for (int i = 0; i<210; i+=10){  
    
    analogWrite(ledPin, i);
    delay(2000);
  }
}
