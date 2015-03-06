#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

enum tape_result_t{
	black,
	white
};

class LightSensor{
	public:
		LightSensor(int pin, int cutoff);
		tape_result_t read();
		int readRaw();
		String toString(); 
	private:
		int _pin;
		int _cutoff;
};

#endif
