#include<SoftwareSerial.h>
#define SDIR 8
#define MDIR 4
#define SSPEED 6
#define MSPEED 5

#define SOPT 1
#define MOPT 0

volatile int steeringCnt = 0;
volatile int moveCnt = 0;
SoftwareSerial bt(10, 11);

char msg;

void steeringInc();
void moveInc();
void go(char mode, int sp);

void setup(){
  Serial.begin(9600);
  bt.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SOPT), steeringInc, FALLING);
  attachInterrupt(digitalPinToInterrupt(MOPT), moveInc, FALLING);
  pinMode(SDIR, OUTPUT);
  pinMode(MDIR, OUTPUT);
  pinMode(SSPEED, OUTPUT);
  pinMode(MSPEED, OUTPUT);
}

void loop(){
   if(Serial.available() > 0){
    msg = Serial.read(); 
   }
   if(bt.available() > 0){
    msg = bt.read();
   }
   Serial.println(steeringCnt);
   if(msg == 'R' || msg == 'L'){
    steeringCnt = 0;
    go(msg, 255);
    while(steeringCnt < 18)
      Serial.println(steeringCnt);
    go('S', 0);
   }
   else if(msg == 'F' || msg == 'B'){
    moveCnt = 0;
    go(msg, 255);
    while(moveCnt < 9)
      Serial.println(moveCnt);
    go('S', 0);
   }
   else if(msg == 'S' || msg == 's'){
    go('S', 0);
   }
   
  delay(20);
}

void steeringInc()
{
  steeringCnt++;
}

void moveInc()
{
  moveCnt++;
}

void go(char mode, int sp)
{
  if(mode == 'F')
  {
    digitalWrite(MDIR, HIGH);
    analogWrite(MSPEED, sp);
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW); 
  }
  else if(mode == 'B')
  {
    digitalWrite(MDIR, LOW);
    analogWrite(MSPEED, sp);
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW);
  }
  else if(mode == 'L')
  {
    digitalWrite(SDIR, HIGH);
    analogWrite(SSPEED, sp);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
  else if(mode == 'R')
  {
    digitalWrite(SDIR, LOW);
    analogWrite(SSPEED, sp);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
  else if(mode == 'S')
  {
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
}

