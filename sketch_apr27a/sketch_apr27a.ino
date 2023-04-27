void setup()
{
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(3)== LOW)
  {
    // delay(100);
    digitalWrite(13,HIGH);
    
  }
  else 
  {
    
    digitalWrite(13,LOW);
    delay(10);
    
  }
  
}