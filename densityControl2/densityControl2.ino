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







 //Prepare binary array for all 7 segment to turn on 7 segment at position of a,b,c,d,e,f,g
int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};

int digit1, digit2; // initialize individual digit to controll each segment


void dis(int num)
{
  for (int i = 22; i< 29; i++)
  {
digitalWrite(i, bitRead(digit[num], i - 22));
  }
}

void dis2(int num)
{
  for (int i = 40; i< 47; i++)
  {
digitalWrite(i, bitRead(digit[num], i - 40));
  }
}

void dis3(int num)
{
  for (int i = 49; i< 54; i++)
  {
digitalWrite(i, bitRead(digit[num], i - 49));
  }
  int i=54;
digitalWrite(A8,bitRead(digit[num],i-49));
i++;
digitalWrite(A9,bitRead(digit[num],i-49));
}


void dis1(int num)
{
  for (int i = 31; i< 38; i++)
  {
digitalWrite(i, bitRead(digit[num], i - 31));
  }
}














void setup()
{

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


pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(A6,INPUT);
pinMode(A7,INPUT);




  for (int i = 22; i< 29; i++)
  {
pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
pinMode(29, OUTPUT); //declare 7 seg Digit1 pin as output
pinMode(30, OUTPUT);//declare 7 seg Digit2 pin as output

  for (int i = 40; i< 47; i++)
  {
pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
pinMode(48, OUTPUT); //declare 7 seg Digit1 pin as output
pinMode(47, OUTPUT);//declare 7 seg Digit2 pin as output

 for (int i = 49; i< 54; i++)
  {
pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
pinMode(A8, OUTPUT); 
pinMode(A9, OUTPUT);
pinMode(A10, OUTPUT); 
pinMode(A11, OUTPUT);

 for (int i = 31; i< 38; i++)
  {
pinMode(i, OUTPUT); // declare 0-9 th pin as output
  }
pinMode(39, OUTPUT); //declare 7 seg Digit1 pin as output
pinMode(38, OUTPUT);//declare 7 seg Digit2 pin as output

pinMode(19,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(19),ambulance,LOW);







}
void loop() {
  int IR1=analogRead(A6);
  int IR2=analogRead(A7);
if(IR1<=60 && IR2<=60)
  {


digitalWrite(G1,HIGH);
digitalWrite(R1,LOW);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);


  for (int j = 90; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y2,HIGH);
digitalWrite(R2, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;
    for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(30, HIGH);
digitalWrite(29, LOW);
      dis(digit2);
delay(10);




digitalWrite(29, HIGH);
digitalWrite(30, LOW);
      dis(digit1);
delay(15);
    }
  }
}

else if (IR1<=60 && IR2>60)
  {


digitalWrite(G1,HIGH);
digitalWrite(R1,LOW);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);




 for (int j = 60; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y2,HIGH);
digitalWrite(R2, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(30, HIGH);
digitalWrite(29, LOW);
      dis(digit2);
delay(10);




digitalWrite(29, HIGH);
digitalWrite(30, LOW);
      dis(digit1);
delay(15);
    }
  }
}


    else if (IR1>60 && IR2>60)
  {


digitalWrite(G1,HIGH);
digitalWrite(R1,LOW);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);




 for (int j = 30; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y2,HIGH);
digitalWrite(R2, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(30, HIGH);
digitalWrite(29, LOW);
      dis(digit2);
delay(10);




digitalWrite(29, HIGH);
digitalWrite(30, LOW);
      dis(digit1);
delay(15);
    }
  }
}

int IR3=analogRead(A0);
int IR4=analogRead(A1);

if(IR3<=60 && IR4<=60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,LOW);
digitalWrite(Y2,LOW);
digitalWrite(G2,HIGH);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);

  for (int j = 90; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y3,HIGH);
digitalWrite(R3, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(39, HIGH);
digitalWrite(38, LOW);
      dis1(digit2);
delay(10);




digitalWrite(38, HIGH);
digitalWrite(39, LOW);
      dis1(digit1);
delay(15);
    }
  }
}


else if(IR3<=60 && IR4>60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,LOW);
digitalWrite(Y2,LOW);
digitalWrite(G2,HIGH);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);

  for (int j = 60; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y3,HIGH);
digitalWrite(R3, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(39, HIGH);
digitalWrite(38, LOW);
      dis1(digit2);
delay(10);




digitalWrite(38, HIGH);
digitalWrite(39, LOW);
      dis1(digit1);
delay(15);
    }
  }
}


else if(IR3>60 && IR4>60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,LOW);
digitalWrite(Y2,LOW);
digitalWrite(G2,HIGH);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);

  for (int j = 30; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y3,HIGH);
digitalWrite(R3, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(39, HIGH);
digitalWrite(38, LOW);
      dis1(digit2);
delay(10);




digitalWrite(38, HIGH);
digitalWrite(39, LOW);
      dis1(digit1);
delay(15);
    }
  }
}



int IR5=analogRead(A2);
int IR6=analogRead(A3);

 if (IR5<=60 && IR6<=60)
  {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,LOW);
digitalWrite(Y3,LOW);
digitalWrite(G3,HIGH);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);




 for (int j = 90; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y4,HIGH);
digitalWrite(R4, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(47, HIGH);
digitalWrite(48, LOW);
      dis2(digit2);
delay(10);




digitalWrite(48, HIGH);
digitalWrite(47, LOW);
      dis2(digit1);
delay(15);
    }
  }
}


  else if (IR5<=60 && IR6>60)
  {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,LOW);
digitalWrite(Y3,LOW);
digitalWrite(G3,HIGH);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);


     for (int j = 60; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y4,HIGH);
digitalWrite(R4, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(47, HIGH);
digitalWrite(48, LOW);
      dis2(digit2);
delay(10);




digitalWrite(48, HIGH);
digitalWrite(47, LOW);
      dis2(digit1);
delay(15);
    }
  }
}


 else if(IR5>60 && IR6>60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,LOW);
digitalWrite(Y3,LOW);
digitalWrite(G3,HIGH);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);


     for (int j = 30; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y4,HIGH);
digitalWrite(R4, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(47, HIGH);
digitalWrite(48, LOW);
      dis2(digit2);
delay(10);




digitalWrite(48, HIGH);
digitalWrite(47, LOW);
      dis2(digit1);
delay(15);
    }
  }
}     


int IR7=analogRead(A4);
int IR8=analogRead(A5);

if(IR7<=60 && IR8<=60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,LOW);
digitalWrite(Y4,LOW);
digitalWrite(G4,HIGH);
delay(20);

  for (int j = 90; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y1,HIGH);
digitalWrite(R1, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(A10, HIGH);
digitalWrite(A11, LOW);
      dis3(digit2);
delay(10);




digitalWrite(A11, HIGH);
digitalWrite(A10, LOW);
      dis3(digit1);
delay(15);
    }
  }
}     


 else if(IR7<=60 && IR8>60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,LOW);
digitalWrite(Y4,LOW);
digitalWrite(G4,HIGH);
delay(20);

  for (int j = 60; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y1,HIGH);
digitalWrite(R1, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(A10, HIGH);
digitalWrite(A11, LOW);
      dis3(digit2);
delay(10);




digitalWrite(A11, HIGH);
digitalWrite(A10, LOW);
      dis3(digit1);
delay(15);
    }
  }
}     


  else if(IR7>60 && IR8>60)
   {


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,LOW);
digitalWrite(Y4,LOW);
digitalWrite(G4,HIGH);
delay(20);

  for (int j = 30; j>=0; j--)// for lopp to pass value from 00-99
  {
    if(j==10)
    {
digitalWrite(Y1,HIGH);
digitalWrite(R1, LOW);
    }
    digit2 = j / 10;
    digit1 = j % 10;


        for ( int k = 0; k < 35; k++)// For loop to control the digit control to print 00-99
    {
digitalWrite(A10, HIGH);
digitalWrite(A11, LOW);
      dis3(digit2);
delay(10);




digitalWrite(A11, HIGH);
digitalWrite(A10, LOW);
      dis3(digit1);
delay(15);
    }
  }
}

}



void ambulance()
{

run();

}

void run()
{
int  s=analogRead(A13);

  while(s<=500)
    {

digitalWrite(G1,HIGH);
digitalWrite(R1,LOW);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(R2,HIGH);
digitalWrite(Y2,LOW);
digitalWrite(G2,LOW);
delay(20);
digitalWrite(R3,HIGH);
digitalWrite(Y3,LOW);
digitalWrite(G3,LOW);
delay(20);
digitalWrite(R4,HIGH);
digitalWrite(Y4,LOW);
digitalWrite(G4,LOW);
delay(20);
 s=analogRead(A13);
delay(20);

    }


digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
digitalWrite(Y1,LOW);
delay(20);

digitalWrite(G2,HIGH);
digitalWrite(R2,LOW);
digitalWrite(Y2,LOW);
delay(20);




}