#include <Arduino.h>
//Ultrasound sensor pins
const int trigPin = 9;
const int echoPin = 10;
//These are required to measure distance
long duration;
int distanceInch;
//This happens in the beginning of the power it has, it defines the pins and the power given.
void setup() {
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

//This part of the code happens again and again in a loop. It defines the function
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceInch);

if(distanceInch	< 72)
{
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
}
else 
{
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}

}