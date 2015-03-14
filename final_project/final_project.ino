#include <Timers.h>

#include "light_module.h"
#include "state.h"
#include "driver.h"
#include "motor.h"

enum state_t{
  init_bot,
  going_straight,
  wall_turn,
  adjust_sonar, 
  get_balls,
  along_long_wall,
  adjust_after_balls,
  stop_bot,
  adjust_after_turn,
  last_turn,
  last_left_turn,
  find_black,
  turn_right,
  dunk_last,
  write_sensors,
  verify_distance,
  line_up_back_up
};

state_t initial_state = init_bot;


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

int trigPin2 = 11;
int echoPin2 = 10;



state_t bot_state;


void setup() {
  Serial.begin(9600);
  forward = true;
  time = 500;
  foundBlack = false;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  //s = new LineFollow();
  //TMRArd_InitTimer(0, 5000);
  
  
//  
//  delay(2000);


  /* CHANGE HERE! */
  bot_state = initial_state;
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

int distance2(){
   Serial.print("Distance: ");
   long duration, distance;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);  
  return distance;
}

int rotateLeft45(){
  d.stop();
  delay(2000);
  d.rotateLeft();
  delay(960);
  d._rightMotor.move(-150);
  d._leftMotor.move(150);
  delay(110);
  d.stop();
  delay(500);
}

int rotateLeft90(){

  d._rightMotor.move(250);
  d._leftMotor.move(50);
  delay(925);
  d.stop();
}



void cornerLeftTurn(){
    d.stop();
    delay(1000);
    int dist = distance();
    if (dist < 13){
       d._leftMotor.move(-150);
       d._rightMotor.move(-150);
       delay(300);
       d.stop(); 
    }
    rotateLeft45();
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

bool didSonarProgress(){
  static int dist = -1;
  if (TMRArd_IsTimerExpired(14) || TMRArd_IsTimerExpired(14) == TMRArd_ERR){
    TMRArd_InitTimer(14, 1000);
    int di = distance();
    bool to_return = (di != dist);
    dist = di;
    return to_return;
  }
  return true;
}

bool timerInited = false;
void resetStateTimer(){
  TMRArd_InitTimer(7, 7000); 
}

bool timerExpired(){
  return (TMRArd_IsTimerExpired(7) == TMRArd_EXPIRED);
}

void loop(){
    if (!timerInited){
      resetStateTimer();
      timerInited = true;
    }
    if (timerExpired() && bot_state != dunk_last && bot_state != get_balls && bot_state != stop_bot){
      d.back();
      delay(800);
      d.stop();
      delay(10);
      d._rightMotor.move(150);
      d._leftMotor.move(-150);
      delay(240);
      d.stop();
      resetStateTimer();
      
    }
    
    if (bot_state == write_sensors){
      int dist = distance();
      Serial.println(lm.toString());
      Serial.print("Distance: ");
      Serial.println(dist);
    }
  
    //d.stop();
    if (bot_state == going_straight){
      int dist = distance();
      if (dist < 20){
        d.stop();
      }else{
        d.straight();
      }
    }
      
    
    if (bot_state == stop_bot){
      d.stop();
      delay(2000);
    }
    
    if (bot_state == init_bot){
      static bool initTimerInited = false;      
      if (!initTimerInited){
        TMRArd_InitTimer(9, 1000); // *makes sure we are in this state for at least this long *//
        initTimerInited = true;
      }
      if (TMRArd_IsTimerExpired(9)){
        int dist = distance();
        if (dist < 20){
          d.stop();
          d._leftMotor.move(-200);
          d._rightMotor.move(-200);
          delay(120);
          d.stop();
          delay(100);
          bot_state = wall_turn;
          resetStateTimer();
        }
      }
      d.straight();
        
     
    }
    
    if (bot_state == get_balls){
      d.stop();
      delay(1000);
      d.backHard();
      delay(3000);
      d.stop();
      delay(300);
      
      d.straight();
      delay(500);
      d.stop();
      delay(300);
      d.backHard();
      delay(1000);
      d.straight();
      delay(500);
      d.stop();
      delay(500);
      d.backHard();
      delay(1500);
      d.stop();
      delay(500);
      d._leftMotor.move(-250);
      d._rightMotor.move(10);
      delay(600);
      d.stop();
      delay(500);
      d._rightMotor.move(-250);
      d._leftMotor.move(10);
      delay(600);
      d.stop();
      d.back();
      delay(500);
      d.stop();
      delay(100);
      bot_state = along_long_wall;
              resetStateTimer();

    }
    
    if (bot_state == dunk_last){
      
      
      dunk();
     
      bot_state = stop_bot;
              resetStateTimer();

    }
    
    if(bot_state == find_black){
        static bool searchTimer = false;
        static bool goingForward = true;
        static int switches = 0;
        if (!searchTimer){
           TMRArd_InitTimer(12, 2000);
           searchTimer = true;
        }
        
        
        
//        if (!TMRArd_IsTimerExpired(searchTimer)){
//          /* in the first two seconds make sure that the bot is moving */
//           if (!didSonarProgress()){
//            d._leftMotor.move(-200);
//            d._rightMotor.move(-140);
//            delay(800);
//            d.stop();
//            delay(100);
//            TMRArd_InitTimer(12, 2000);
//          }
//        }
          
        tape_result_t c = lm._middle.read();
        int dist = distance();
        if (c == black){
            d._rightMotor.move(-200);
            d._leftMotor.move(-200);
            delay(120);
            d.stop();
            delay(10);
            bot_state = dunk_last;
            resetStateTimer();
        }else{
          d.straightAlongWallSlowDown();
        }
    }
        
//          }else{
//            goingForward = !goingForward;
//            switches += 1;
//          }
//        }
//        if (goingForward){
//          d.straightAlongWallSlowDown();
//        }else {
//          d.back();
        
        
    
    if (bot_state == verify_distance){
      
      static bool distanceTimer = false;
        if (!distanceTimer){
           TMRArd_InitTimer(12, 10000);
           distanceTimer = true;
        }
        
        
        
      if (TMRArd_IsTimerExpired(distanceTimer)){
        bot_state=dunk_last;
        resetStateTimer();
      }
      int dist = distance();
      if (dist < 49) {
        d.back();
        delay(200);
        d._leftMotor.move(200);
        d._rightMotor.move(200);
        delay(50);
        d.stop();
      }
      else if (dist > 54){
        d.straight();
        delay(200);
        d._leftMotor.move(-200);
        d._rightMotor.move(-200);
        delay(50);
        d.stop();
      }
      else{
         d.stop();
         bot_state= dunk_last;
         resetStateTimer();
       }
    }
    
//    if (bot_state == last_turn){
//      
//      d._rightMotor.move(190);
//      d._leftMotor.move(0);
//      delay(1700);
//      d.stop();
//      delay(100);
//      bot_state = find_black;
//      resetStateTimer();
//
//    }
    
  
    
    if (bot_state == along_long_wall){
      static bool stateTimerInited = false;
      
      
      bool fullSpeed = false;
      if (!stateTimerInited){
        TMRArd_InitTimer(9, 2000); // *makes sure we are in this state for at least this long *//
        stateTimerInited = true;
      }
      
      d.straightAlongWall(); 
  
      
      
      if (TMRArd_IsTimerExpired(9)){
        /* look for transition */ 
        int dist = distance();
        if (dist < 29){
          d.back();
          delay(180);
          rotateLeft90();

          bot_state = line_up_back_up;
          resetStateTimer();
        }
      }
      
    }
    if (bot_state == last_left_turn){
      
       static bool turnTimer = false;
        if (!turnTimer){
          delay(4000);
           TMRArd_InitTimer(12, 6000);
           turnTimer = true;
        }
        
        
        
      if (TMRArd_IsTimerExpired(turnTimer)){
        bot_state=dunk_last;
        resetStateTimer();
      }
      int dist = distance();
      if (dist < 20) {
        d.back();
        delay(200);
        d.stop();
        delay(200);
      }
      else if (dist > 26){
        d.straight();
        delay(200);
        d.stop();
        delay(200);
      }else{
        rotateLeft90();
        bot_state = line_up_back_up;
              resetStateTimer();

      }

    }
    
    if (bot_state == wall_turn){
      Serial.println("Entered wall_turn");
      cornerLeftTurn();

      bot_state = get_balls;
      resetStateTimer();
    }
    
    if (bot_state == line_up_back_up){
      d.back();
      delay(2000);
      d.stop();
      
      delay(500);
      d._leftMotor.move(-250);
      d._rightMotor.move(10);
      delay(1000);
      d.stop();
      delay(500);
      d._rightMotor.move(-250);
      d._leftMotor.move(10);
      delay(1000);
      d.stop();
      d.back();
      delay(500);
      d.stop();
      delay(100);
      bot_state = find_black;
      resetStateTimer();
    }    
    
}
  

