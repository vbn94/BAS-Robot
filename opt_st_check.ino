#define S 5
#define D 4
#define OPT 0
volatile int count = 0;
char msg;

void inc()
{
  count++;
}

void setup() {
  Serial.begin(9600);
  pinMode(S, OUTPUT);
  pinMode(D, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(OPT), inc, FALLING);
}

void loop() {

  if(Serial.available()>0){
    msg = Serial.read();
    count = 0;
  }
    if(msg == 'L')
    {
      left(200);
      while(count < 18)
      {
        Serial.println(count);
        delay(10);
      }
    }
    else if(msg == 'R')
    {
      while(count < 18)
      {
        right(200);
      }
    }
  digitalWrite(S, LOW);
  digitalWrite(D, LOW);
  Serial.println(count);
  delay(200);
}

int left(int sp){
  analogWrite(S, sp);
  digitalWrite(D, HIGH);
}

int right(int sp){
  analogWrite(S, sp);
  digitalWrite(D, LOW);
}

