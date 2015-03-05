#include "light_sensor.h"
#include "Arduino.h"

LightSensor::LightSensor(int pin, int cutoff){
	pinMode(pin, INPUT);
	_pin = pin;
	_cutoff = cutoff;
}


tape_result_t LightSensor::read(){
	int val = analogRead(_pin);
	if (val > _cutoff){
		return white;
	}else{
		return black; 
	}
}

int LightSensor::readRaw(){
	int val = analogRead(_pin);
	return val;
}

String LightSensor::toString(){
        String res = "Pin ";
        res += _pin;
        res += ": ";
        res += readRaw(); 
	tape_result_t r = this->read();
	if (r == white){
		res += " [white]";
	}else{
		res += " [black]";
	}
        return res;
}
