#include "light_sensor.h"
#include "light_module.h"


LightModule lm;
void setup(){
  Serial.begin(9600);
}

void loop(){
        Serial.println(lm.toString());
  	delay(300);
}
