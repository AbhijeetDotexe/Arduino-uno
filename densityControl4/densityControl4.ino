#define R1 13
#define Y1 12
#define G1 11
#define R2 10
#define Y2 9
#define G2 8
#define R3 7
#define Y3 6
#define G3 5
#define R4 4
#define Y4 3
#define G4 2
 

#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3

float IR1=0;
float IR2=0;
float IR3=0;
float IR4=0;


void setup() {
pinMode(R1,OUTPUT);
pinMode(Y1,OUTPUT);
pinMode(G1,OUTPUT);

pinMode(R2,OUTPUT);
pinMode(Y2,OUTPUT);
pinMode(G2,OUTPUT);

pinMode(R3,OUTPUT);
pinMode(Y3,OUTPUT);
pinMode(G3,OUTPUT);

pinMode(R4,OUTPUT);
pinMode(Y4,OUTPUT);
pinMode(G4,OUTPUT);

pinMode(p1,INPUT);
pinMode(p2,INPUT);
pinMode(p3,INPUT);
pinMode(p4,INPUT);

}

void loop() {
 
  //L L L H 
 IR1=analogRead(p1);
 IR2=analogRead(p2);
 IR3=analogRead(p3);
 IR4=analogRead(p4);

if(IR1<500&&IR2<500&&IR3<500&&IR4>500)
 {digitalWrite(R1,HIGH);//g4 high
 digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y1,LOW);
   digitalWrite(G2,LOW);
   
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
   digitalWrite(G3,LOW);
   
  digitalWrite(R4,LOW);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  }
 //L L H L
 else if(IR1<500&&IR2<500&&IR3>500&&IR4<500)
  {digitalWrite(R1,HIGH);//g3 high
digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
 digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
}
//L L H H 
else if(IR1<500&&IR2<500&&IR3>500&&IR4>500)
 { digitalWrite(R1,HIGH);//G3 high
digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
 
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y3 and y4 high
digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
 
  digitalWrite(R3,LOW);
    digitalWrite(Y3,HIGH);
 digitalWrite(G3,LOW);
 
  digitalWrite(Y4,HIGH);
 digitalWrite(R4,LOW);
  digitalWrite(G4,LOW);
delay(1000);
 
  digitalWrite(R1,HIGH);//g4 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);

  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(5000);}
 //L H L L 
 else if(IR1<500&&IR2>500&&IR3<500&&IR4<500)
  {digitalWrite(R1,HIGH);//g2 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
 
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  }
//L H L H
 else if(IR1<500&&IR2>500&&IR3<500&&IR4>500)
  {digitalWrite(R1,HIGH);//g2 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
 
  digitalWrite(R3,HIGH);
 digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
 
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y2 y4 high
digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);

  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
 
  digitalWrite(Y4,HIGH);
 digitalWrite(R4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
  
   digitalWrite(R1,HIGH);//g4 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
 
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(5000);}
//L H H L 
else if(IR1<500&&IR2>500&&IR3>500&&IR4<500)
  {digitalWrite(R1,HIGH);//g2 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
 
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

digitalWrite(R1,HIGH);//y2 y3 high
 digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R1,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);

  digitalWrite(R3,LOW);
    digitalWrite(Y3,HIGH);
 digitalWrite(G3,LOW);
 
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
  digitalWrite(R1,HIGH);//g3 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);}
 //L H H H 
else if(IR1<500&&IR2>500&&IR3>500&&IR4>500)
//g2 high
{digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y2 y3 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R1,LOW);
  digitalWrite(Y2,HIGH);
    digitalWrite(G2,LOW);
 
  digitalWrite(R3,LOW);
   digitalWrite(Y3,HIGH);
 digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//g3 high
  digitalWrite(R1,HIGH);
 digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y3 y4 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
 digitalWrite(R3,LOW);
  digitalWrite(Y3,HIGH);
  digitalWrite(G3,LOW);

  digitalWrite(R4,LOW);
  digitalWrite(Y4,HIGH);
   digitalWrite(G4,LOW);
  delay(1000);
//g4 high
   digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(5000);}
//H L L L
else if(IR1>500&&IR2<500&&IR3<500&&IR4<500)
  {digitalWrite(R1,LOW);//g1 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  }
//H L L H
else if(IR1>500&&IR2<500&&IR3<500&&IR4>500)
 { digitalWrite(R1,LOW);//g1 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(Y1,HIGH);//y1 y4 high
  digitalWrite(R1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(Y4,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(G4,LOW);
delay(1000);

   digitalWrite(R1,HIGH);//g4 high
 digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(5000);}
//H L H L 
else if(IR1>500&&IR2<500&&IR3>500&&IR4<500)
  {digitalWrite(R1,LOW);//g1 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

 digitalWrite(Y1,HIGH);//y1 y3 high
digitalWrite(R1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
 
  digitalWrite(R3,LOW);
    digitalWrite(Y3,HIGH);
    digitalWrite(G3,LOW);
    
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
  
   digitalWrite(R1,HIGH);//g3 high
   digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);}
//H L H H 
else if(IR1<500&&IR2>500&&IR3>500&&IR4>500)
//g1 high
{digitalWrite(R1,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);
 
  digitalWrite(Y1,HIGH);//y1 y3 high
  digitalWrite(R1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
 digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,HIGH);
  digitalWrite(G3,LOW);
 
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//g3 high
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
 
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y3 y4 high
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
    digitalWrite(Y3,HIGH);
    digitalWrite(G3,LOW);
    
digitalWrite(R4,LOW);
  digitalWrite(Y4,HIGH);
  digitalWrite(G4,LOW);
  delay(1000);
//g4 high
   digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
 digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(5000);}
//H H L L 
else if(IR1>500&&IR2>500&&IR3<500&&IR4<500)
//g1 high
{digitalWrite(R1,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
 digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
    digitalWrite(G3,LOW);
    
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);
 
  digitalWrite(Y1,HIGH);//y1 y2 high
  digitalWrite(R1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R1,LOW);
  digitalWrite(Y2,HIGH);
   digitalWrite(G2,LOW);
   
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//g2 high
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);}
//H H H L
else if (IR1>500&&IR2>500&&IR3>500&&IR4<500)
//g1 high

{  digitalWrite(R1,LOW);
   digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
 digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

 
  digitalWrite(Y1,HIGH);//y1 y2 high
  digitalWrite(R1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//g2 high
 digitalWrite(R1,HIGH);
 digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  
  digitalWrite(R3,HIGH);
 digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);

  digitalWrite(R1,HIGH);//y2 y3 high
digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);

  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,HIGH);
  digitalWrite(G3,LOW);
  
  digitalWrite(R4,HIGH);
 digitalWrite(Y4,LOW);
 digitalWrite(G4,LOW);
  delay(1000);
//g3 high
   
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  
  digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(5000);}

else 
{//G1 high for 3000 delay 
  digitalWrite(R1,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(3000);
//G1 and Y2 high for 1000 delay
  digitalWrite(R1,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//Y1 and G2 high for 1000 delay 
  digitalWrite(R1,LOW);
  digitalWrite(Y1,HIGH);
  digitalWrite(G1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//G2 high for 2000 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(2000);
//G2 and Y3 high for 1000 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  digitalWrite(R3,LOW);
  digitalWrite(Y3,HIGH);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//G3 and Y2 high for 1000 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,HIGH);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(1000);
//G3 high for 2000 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,LOW);
  delay(2000);
//G3 and Y4 for 1000 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(Y4,HIGH);
  digitalWrite(G4,LOW);
  delay(1000);
//G4 and Y3 HIGH for 1000 delay
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(Y3,HIGH);
  digitalWrite(G3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH); 
  delay(1000);
//G4 high for 200 delay 
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(2000);
//G4 and Y1 high for 1000 delay 
  digitalWrite(R1,LOW);
  digitalWrite(Y1,HIGH);
  digitalWrite(G1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(Y3,LOW);
  digitalWrite(G3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(Y4,LOW);
  digitalWrite(G4,HIGH);
  delay(1000);
  
}
 
  
}