#include<Servo.h>
Servo servo;
#define trig 7
#define echo 8
long time , dist;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(1000);
  servo.attach(servP);
}
void loop()
{
  digitalWrite(trig, LOW);
  delay(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig ,LOW);
  time = pulseIn(echo , HIGH);
  dist = time / 2/ 29.1;
  Serial.print("Distance is ");
  Serial.print(dist);
  unsigned char pos = map(dist , 4,330, 0,130);
  servo.write(pos);
  Serial.print(" & Position is ");
  Serial.println(pos ,DEC);
  delay(2000);
}