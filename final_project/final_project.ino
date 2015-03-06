#include <Timers.h>

#include "light_module.h"
#include "state.h"
#include "driver.h"

LightModule lm;
Driver d; 
State s;

void setup(){
  Serial.begin(9600);
  s = TestTurnRight(10000);
}

void printLM(){
   Serial.println("---------------------------------");
   Serial.println(lm.toString());
}

void mainLoop(){
  driver_dir_t d = dm.drive(lm_res);
}

void loop(){
    if (!s.done()){
    	s.execute(d, lm);
    }
  
}
