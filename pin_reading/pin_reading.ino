/* Reads from pin A0 and prints to console */


#include <Pulse.h>

int pinDir = 8; // #define pinStep NOT signal (advancement)
int pinStep = 9; // #define pinDir Direction 
int tapeIn1 = A0;
int tapeIn2 = A1;
int trigPin = 13;
int echoPin = 12;
int led = 11;
int led2 = 10;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(tapeIn1, INPUT);
  pinMode(tapeIn2, INPUT);
}



 
/* Loops by reading a voltage and outputting a number [0-103] 
corresponding to the period of rotation (high number is slow).

If a key stroke is detected on serial input, then direction of 
rotation is changed by flipping the voltage on the direction pin*/
 void loop () {
   
   int v = analogRead(tapeIn1); 
   int v2 = analogRead(tapeIn2);
   
   Serial.print("Tape sensor reading #1: ");
   Serial.println(v);
   Serial.print("Tape sensor reading #2: ");
   Serial.println(v2);
   
   Serial.print("Distance: ");
   long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 7) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
  }
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);

   
 }

