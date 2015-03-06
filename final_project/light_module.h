
#ifndef LightModule_h
#define LightModule_h

#include "Arduino.h"
#include "light_sensor.h"

enum lm_res_t {
  bbb,
  bbw,
  wbw,
  wbb,
  wwb,
  bww,
  www,
  err
};

class LightModule {
  public:
    LightModule();
    lm_res_t measure();
    String toString();
    int readLeft();
    int readRight();
  
    LightSensor _right = LightSensor (A0, 400);
    LightSensor _middle = LightSensor(A1, 400);
    LightSensor _left = LightSensor(A2, 400);
};

#endif
