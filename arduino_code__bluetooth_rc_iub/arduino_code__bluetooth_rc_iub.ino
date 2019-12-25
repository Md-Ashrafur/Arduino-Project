/***************************BLUETOOTH CONTROLLED CAR CODE**************************/
#include <SoftwareSerial.h>

//Declare the arduino pins
SoftwareSerial mySerial(3,2);

int lm1 = 7;
int lm2 = 6;
int rm1 = 5;
int rm2 = 4;
int EN1 = 6; //(right)
int EN2= 5; // left


void setup()
{
  //initlize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
   pinMode(EN1,OUTPUT);
   pinMode(EN2,OUTPUT);

   //set the serial communication rate
  TCCR1B = (TCCR1B & 0b11111000) | 0x04;
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  char val;
  if(mySerial.available()){
    val = mySerial.read();
    Serial.println(val);
    }
 /* //check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  char val = Serial.read() ;//reads the signal
  Serial.print(val);*/

  /*********For Forward motion*********/
        if(val == '2')
       {
          digitalWrite(lm1,HIGH);  digitalWrite(rm2,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          //delay(5000);  
       }
       else if(val == '1')
       {
          digitalWrite(lm1,LOW);  digitalWrite(rm2,LOW);
          digitalWrite(lm2,HIGH);       digitalWrite(rm1,HIGH);
          analogWrite(EN1,150); analogWrite(EN2,150);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          
       }
       else if(val == '4')
       {
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          analogWrite(EN1,150); analogWrite(EN2,150);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          
       }
       else if(val == '3')
       {
          digitalWrite(lm2,HIGH);  digitalWrite(rm2,HIGH);
          digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          //delay(5000);
       }

  
}

