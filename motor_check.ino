#include<SoftwareSerial.h>
#define SDIR 8
#define MDIR 4

#define SSPEED 6
#define MSPEED 5

#define SOPT 0
#define MOPT 1

SoftwareSerial bt(10, 11);
char msg;

void setup(){
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(SDIR, OUTPUT);
  pinMode(MDIR, OUTPUT);
  pinMode(SSPEED, OUTPUT);
  pinMode(MSPEED, OUTPUT);
  pinMode(SOPT, OUTPUT);
  pinMode(MOPT, OUTPUT);
}

void loop(){
 if(Serial.available() > 0){
  msg = Serial.read(); 
 }
 if(bt.available() > 0){
  msg = bt.read();
 }

  if(msg == 'F'){
    digitalWrite(MDIR, HIGH);
    digitalWrite(MSPEED, HIGH);
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW);
  }
  else if(msg == 'B'){
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, HIGH);
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW);
  }
  else if(msg == 'L'){
    digitalWrite(SDIR, HIGH);
    digitalWrite(SSPEED, HIGH);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
  else if(msg == 'R'){
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, HIGH);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
  else if(msg == 's' || msg == 'S'){
    digitalWrite(SDIR, LOW);
    digitalWrite(SSPEED, LOW);
    digitalWrite(MDIR, LOW);
    digitalWrite(MSPEED, LOW);
  }
  delay(20);
}


