#ifndef DecisionMaker_h
#define DecisionMaker_h
#include <Timers.h>
#include "Arduino.h"
#include "light_module.h"

class DecisionMaker {
public:
	DecisionMaker();
	void drive(lm_res_t lm_res); /* TODO: add sensors */
	String toString(driver_dir_t d);
	void drive(lm)
private:
	state_t _state;
	Motor _leftMotor = Motor(3,2,170);
    Motor _rightMotor = Motor(5,4,170);
};

#endif
