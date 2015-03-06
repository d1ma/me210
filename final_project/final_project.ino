#include <Timers.h>

#include "light_module.h"
#include "state.h"
#include "driver.h"



LightModule lm;
Driver d; 
State *s;
bool forward;
int time;
bool foundBlack;

int pinStep = 9;
int pinDir = 8;
int trigPin = 13;
int echoPin = 12;

void setup() {
  Serial.begin(9600);
  forward = true;
  time = 500;
  foundBlack = false;
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //s = new LineFollow();
  //TMRArd_InitTimer(0, 5000);
  
  
//  
//  delay(2000);
  pinMode(pinStep, OUTPUT);
  pinMode(pinDir, OUTPUT);
  digitalWrite(pinDir, HIGH);
}


int distance(){
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
  Serial.println(distance);  
  return distance;
}

int rotateLeft45(){
  d.rotateLeft();
  delay(400);
}

int dunk() {
  digitalWrite(pinDir,HIGH);
  for (int i = 0; i < 1050; i++){
    digitalWrite(pinStep,HIGH);
    delay(2);
    digitalWrite(pinStep,LOW);
    delay(2);
    Serial.println(i);
  }
   delay(3000);
   digitalWrite(pinDir,LOW);
   for (int j = 0; j < 1050; j++){
     digitalWrite(pinStep, HIGH);
     delay(2);
     digitalWrite(pinStep,LOW);
     delay(2);
     Serial.println(j);
   }
   delay(5000);
   Serial.println("End");
   digitalWrite(pinStep,LOW);
   int done = 1;
   return done;
}


void printLM(){
   Serial.println("---------------------------------");
   Serial.println(lm.toString());
}



bool getToBlack(){
  Serial.println(forward);
  Serial.println(time);
  TMRArdReturn_t timer_status = TMRArd_IsTimerExpired(4);
  
  
  if (timer_status == TMRArd_ERR ){
    TMRArd_InitTimer(4, time);
    Serial.println("Error");
  }else if (timer_status == TMRArd_EXPIRED){
    Serial.println("TIMER_EXPIRED!");
    Serial.print("Setting to ");
    Serial.println(time);
    TMRArd_InitTimer(4, time);
    forward = !forward;
    if (time + 4000 > 15000){
      time = 15000;
    }else {
      time = time + 4000; 
    }
    
    Serial.println("INCREASING/SWITCHING");
  }
  tape_result_t c = lm._middle.read();
  
  if (c == black){
    time = 1000;
    forward = true;
    d.stop();
    return true;
  }else {
    if (forward){
      Serial.println("Going forward");
      
      d.straight();
    }else{
      Serial.println("Going back");
      d.back();
    }
    
    return false;
  }
}


void loop(){
    //d.stop();
    
//    tape_result_t c = lm._middle.read();
//    int dist = distance();
//    if (dist <= 15){
//      d.stop();
//      delay(5000);
//      dunk();
//    }else{
//      d.straightAlongWall();
//    }
    rotateLeft45();
    Serial.println(lm.toString());
}
  

