int IRSensor = 3;
int LED = 13;

void setup() {
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead(IRSensor);
  if(statusSensor == 1){
    digitalWrite(LED,LOW);
    delay(100);
  }
  else{
    digitalWrite(LED,HIGH);
  }
}
