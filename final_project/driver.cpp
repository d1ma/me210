#include "motor.h"
#include "decision_maker.h"
#include "driver.h"
#include <Timers.h>

bool Driver::timerExpired(){
  	return (bool)TMRArd_IsTimerExpired(_timer);
}

void Driver::resetTimer(int millis){
  TMRArd_InitTimer(_timer, millis);
}

Driver::Driver(){
  return;
}

void Driver::straight(){
	_leftMotor.move(true);
	_rightMotor.move(true);
}

void Driver::rotateLeft(){
	_leftMotor.move(false);
	_rightMotor.move(true);
}

void Driver::rotateRight(){
	_leftMotor.move(false);
	_rightMotor.move(true);
}

void Driver::stop(){
	_leftMotor.move(0);
	_rightMotor.move(0);
}

void Driver::turnRight(){
	_leftMotor.move(true);
	_rightMotor.move(0);
}

void Driver::turnLeft(){
	_rightMotor.move(true);
	_leftMotor.move(0);
}
