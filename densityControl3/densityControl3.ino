int R1=A0; //road 1
int Y1=A1;
int G1=A2;
int R2=A3; // road 2
int Y2=A4; 
int G2=A5;
int R3=2; // road 3
int Y3=3;
int G3=4;
int R4=5; // road 4
int Y4=6;
int G4=7;
int gap=0;
int sensor1=8; // sensor 1
int sensorState1=1;
int lastsensorState1=1;
int CarCounter1=0;
int sensorState2=1;
int sensor2=9; // sensor 2
int lastsensorState2=1;
int CarCounter2=0;
int sensorState3=1;
int sensor3=10; // sensor 3
int lastsensorState3=1;
int CarCounter3=0;
int sensor4=11; // sensor 4
int sensorState4=1;
int lastsensorState4=1;
int CarCounter4=0;
unsigned long previousMillis = 0000;
long interval =8000;
int target=0;
int Yel=0;


void setup() {
  // put your setup code here, to run once:
pinMode(G1, OUTPUT);
pinMode(G2, OUTPUT);
pinMode(G3, OUTPUT);
pinMode(G4, OUTPUT);
pinMode(R1, OUTPUT);
pinMode(R2, OUTPUT);
pinMode(R3, OUTPUT);
pinMode(R4, OUTPUT);
pinMode(Y1, OUTPUT);
pinMode(Y2, OUTPUT);
pinMode(Y3, OUTPUT);
pinMode(Y4, OUTPUT);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
digitalWrite(G1, HIGH);
digitalWrite(Y2, HIGH);
digitalWrite(R3, HIGH);
digitalWrite(R4, HIGH);
digitalWrite(Y4, HIGH);
Serial.begin(9600); // for serial monitor
}

void loop() // Part that is executed again and again
{
//Counting mechanism for sensor1
Serial.println("car counting starts!");
sensorState1 = digitalRead(sensor1);
if (sensorState1 != lastsensorState1)
{ if (sensorState1 == LOW)
{ ++CarCounter1;
} }
//Serial.println("car counting 2 starts!");
lastsensorState1 = sensorState1;
//Serial.println("car counting 2 starts!");
//Counting mechanism for sensor2
sensorState2 = digitalRead(sensor2);
if (sensorState2 != lastsensorState2)
{
if (sensorState2 == LOW)
++CarCounter2;
}
lastsensorState2 = sensorState2;
//Counting mechanism for sensor3
//Serial.println("car counting 3 starts!");
sensorState3 = digitalRead(sensor3);
if (sensorState3 != lastsensorState3)
{
if (sensorState3 == LOW)
++CarCounter3;
}
lastsensorState3 = sensorState3;
//Counting mechanism for sensor4
//Serial.println("car counting 4 starts!");
sensorState4 = digitalRead(sensor4);
if (sensorState4 != lastsensorState4)
{
if (sensorState4 == LOW)
++CarCounter4;
}
lastsensorState4 = sensorState4;
delay(500);
unsigned long currentMillis = millis();
//Serial.print("time:");
//Serial.println(currentMillis-previousMillis);
if ((currentMillis-previousMillis)>=interval)
{
  //Serial.print("time:");
  //Serial.println(previousMillis);
  Serial.println("car counting ends!");
  previousMillis=currentMillis;
Serial.print ("number of car passed in 1: ");
Serial.println(CarCounter1);
Serial.print ("number of car passed in 2: ");
Serial.println(CarCounter2);
Serial.print ("number of car passed in 3: ");
Serial.println(CarCounter3);
Serial.print ("number of car passed in 4: ");
Serial.println(CarCounter4);

  if((CarCounter1==CarCounter2)&& (CarCounter2==CarCounter3) && (CarCounter3==CarCounter4))
{
    if(digitalRead(G1)==HIGH)
{
digitalWrite (G1, LOW);
digitalWrite (R1, LOW);
digitalWrite (Y1, HIGH);
digitalWrite (G2, HIGH);
digitalWrite (Y2,LOW);
digitalWrite (R2,LOW);
digitalWrite (G3, LOW);
digitalWrite (R3, HIGH);
digitalWrite (Y3, HIGH);
digitalWrite (G4,LOW);
digitalWrite (R4,HIGH);
digitalWrite (Y4,LOW);
//Serial.print ("number of car passed in 2: ");
//Serial.println(CarCounter2);
//interval= 5000;
CarCounter2=0;
//delay(1000);
}
else if(digitalRead(G2)==HIGH)
{
digitalWrite (G2, LOW);
digitalWrite (R2, LOW);
digitalWrite (Y2, HIGH);
digitalWrite (G3, HIGH);
digitalWrite (Y3,LOW);
digitalWrite (R3,LOW);
digitalWrite (G4, LOW);
digitalWrite (R4, HIGH);
digitalWrite (Y4, HIGH);
digitalWrite (G1,LOW);
digitalWrite (R1,HIGH);
digitalWrite (Y1,LOW);
//Serial.print ("number of car passed in 3: ");
//Serial.println(CarCounter3);
//interval= 5000;
CarCounter3=0;
//delay(1000);

}
else if(digitalRead(G3)==HIGH)
{
digitalWrite (G3, LOW);
digitalWrite (R3, LOW);
digitalWrite (Y3, HIGH);
digitalWrite (G4, HIGH);
digitalWrite (Y4,LOW);
digitalWrite (R4,LOW);
digitalWrite (G1, LOW);
digitalWrite (R1, HIGH);
digitalWrite (Y1, HIGH);
digitalWrite (G2,LOW);
digitalWrite (R2,HIGH);
digitalWrite (Y2,LOW);
//Serial.print ("number of car passed in 4: ");
//Serial.println(CarCounter4);
//interval= 5000;
//delay(1000);
CarCounter4=0;
}
else if(digitalRead(G4)==HIGH)
{
digitalWrite (G4, LOW);
digitalWrite (R4, LOW);
digitalWrite (Y4, HIGH);
digitalWrite (G1, HIGH);
digitalWrite (Y1,LOW);
digitalWrite (R1,LOW);
digitalWrite (G2, LOW);
digitalWrite (R2, HIGH);
digitalWrite (Y2, HIGH);
digitalWrite (G3,LOW);
digitalWrite (R3,HIGH);
digitalWrite (Y3,LOW);
//Serial.print ("number of car passed in 1: ");
//Serial.println(CarCounter1);
//interval= 1000*CarCounter1+1000;
//delay(interval);
CarCounter1=0;
} } 
  else if((CarCounter1>=CarCounter2) && (CarCounter1>=CarCounter3) && (CarCounter1>=CarCounter4)){
   digitalWrite(G1,HIGH);
   digitalWrite(R1,LOW);
   digitalWrite(Y1,LOW);
   digitalWrite(G2,LOW);
   digitalWrite(G3,LOW);
   digitalWrite(G4,LOW);
   if ((CarCounter2>=CarCounter3)&&(CarCounter2>=CarCounter4)){
    digitalWrite(R2,HIGH);
    digitalWrite(Y2,HIGH);
    if  (CarCounter3>=CarCounter4){
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    
   }
  else if ((CarCounter3>=CarCounter4)&&(CarCounter3>CarCounter2)){
    digitalWrite(R3,HIGH);
    digitalWrite(Y3,HIGH);
    if  (CarCounter2>=CarCounter4){
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    
   }
   else if ((CarCounter4>CarCounter2)&&(CarCounter4>CarCounter3)){
    digitalWrite(R4,HIGH);
    digitalWrite(Y4,HIGH);
    if  (CarCounter2>=CarCounter3){
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    else {
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    
   }
gap= 1000*CarCounter1+1000;
delay(gap);
CarCounter1=0;
  }
  
 else if((CarCounter2>=CarCounter3) && (CarCounter2>=CarCounter4) && (CarCounter2>CarCounter1)){
   digitalWrite(G2,HIGH);
   digitalWrite(R2,LOW);
   digitalWrite(Y2,LOW);
   digitalWrite(G1,LOW);
   digitalWrite(G3,LOW);
   digitalWrite(G4,LOW);
   if ((CarCounter1>=CarCounter3)&&(CarCounter1>=CarCounter4)){
    digitalWrite(R1,HIGH);
    digitalWrite(Y1,HIGH);
    if  (CarCounter3>=CarCounter4){
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    
   }
  else if ((CarCounter3>=CarCounter4)&&(CarCounter3>CarCounter1)){
    digitalWrite(R3,HIGH);
    digitalWrite(Y3,HIGH);
    if  (CarCounter1>=CarCounter4){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
   else if ((CarCounter4>CarCounter1)&&(CarCounter4>CarCounter3)){
    digitalWrite(R4,HIGH);
    digitalWrite(Y4,HIGH);
    if  (CarCounter1>=CarCounter3){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    else {
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
gap= 1000*CarCounter2+1000;
delay(gap);
CarCounter2=0;
  }
  
 else if((CarCounter3>=CarCounter4) && (CarCounter3>CarCounter2) && (CarCounter3>CarCounter1)){
   digitalWrite(G3,HIGH);
   digitalWrite(R3,LOW);
   digitalWrite(Y3,LOW);
   digitalWrite(G2,LOW);
   digitalWrite(G1,LOW);
   digitalWrite(G4,LOW);
   if ((CarCounter1>=CarCounter2)&&(CarCounter1>=CarCounter4)){
    digitalWrite(R1,HIGH);
    digitalWrite(Y1,HIGH);
    if  (CarCounter2>=CarCounter4){
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    
   }
  else if ((CarCounter2>=CarCounter4)&&(CarCounter2>CarCounter1)){
    digitalWrite(R2,HIGH);
    digitalWrite(Y2,HIGH);
    if  (CarCounter1>=CarCounter4){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R4,LOW);
      digitalWrite(Y4,HIGH);
    }
    else {
      digitalWrite(R4,HIGH);
      digitalWrite(Y4,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
   else if ((CarCounter4>CarCounter2)&&(CarCounter4>CarCounter1)){
    digitalWrite(R4,HIGH);
    digitalWrite(Y4,HIGH);
    if  (CarCounter1>=CarCounter2){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    else {
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
gap= 1000*CarCounter3+1000;
delay(gap);
CarCounter3=0;
  } 
  else if((CarCounter4>CarCounter1) && (CarCounter4>CarCounter2) && (CarCounter4>CarCounter3)){
   digitalWrite(G4,HIGH);
   digitalWrite(R4,LOW);
   digitalWrite(Y4,LOW);
   digitalWrite(G2,LOW);
   digitalWrite(G3,LOW);
   digitalWrite(G1,LOW);
   if ((CarCounter1>=CarCounter2)&&(CarCounter1>=CarCounter3)){
    digitalWrite(R1,HIGH);
    digitalWrite(Y1,HIGH);
    if  (CarCounter2>=CarCounter3){
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    else {
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    
   }
  else if ((CarCounter2>=CarCounter3)&&(CarCounter2>CarCounter1)){
    digitalWrite(R2,HIGH);
    digitalWrite(Y2,HIGH);
    if  (CarCounter1>=CarCounter3){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R3,LOW);
      digitalWrite(Y3,HIGH);
    }
    else {
      digitalWrite(R3,HIGH);
      digitalWrite(Y3,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
   else if ((CarCounter3>CarCounter2)&&(CarCounter3>CarCounter1)){
    digitalWrite(R3,HIGH);
    digitalWrite(Y3,HIGH);
    if  (CarCounter1>=CarCounter2){
      digitalWrite(R1,HIGH);
      digitalWrite(Y1,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Y2,HIGH);
    }
    else {
      digitalWrite(R2,HIGH);
      digitalWrite(Y2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(Y1,HIGH);
    }
    
   }
gap= 1000*CarCounter4+1000;
delay(gap);
CarCounter4=0;
  }
 Serial.println("one loop ended "); 
 delay(1000) ;  
  }
 //Serial.println("one loop ended ");
 //delay(1000) ;

}