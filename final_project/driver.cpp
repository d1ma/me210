#include "motor.h"
#include "driver.h"
#include "Arduino.h"
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

void Driver::back(){
  _leftMotor.move(false);
  _rightMotor.move(false);
  delay(300);
  stop();
  delay(150);
}

void Driver::straightAlongWall(){
  _leftMotor.move(205);
  _rightMotor.move(185);
  delay(300);
  stop();
  delay(50);
}
  
  

void Driver::straight(){
        static int counter = 0;
        counter++;
        if (counter % 2 == 0){
	_rightMotor.move(true);
	_leftMotor.move(true);
        }
        else{
	_leftMotor.move(true);
	_rightMotor.move(true);
        }

        delay(250);
        stop();
        delay(10);
        
}

void Driver::rotateLeft(){
	_rightMotor.move(true);
	_leftMotor.move(false);
        delay(500);
        stop();
}

void Driver::rotateRight(){
	_leftMotor.move(true);
	_rightMotor.move(false);
}

void Driver::stop(){
	_leftMotor.move(10);
	_rightMotor.move(10);
}

void Driver::turnRight(){
	_leftMotor.move(true);
	_rightMotor.move(6);
}

void Driver::turnLeft(){
	_rightMotor.move(true);
	_leftMotor.move(6);
}

void Driver::adjustLeft(){
//        _rightMotor.move(_rightMotor._pow + 10);
//        _leftMotor.move(_leftMotor._pow - 70);
  rotateLeft();
}

void Driver::adjustRight(){
//        _rightMotor.move(_rightMotor._pow -70);
//        _leftMotor.move(_leftMotor._pow + 10);
rotateRight();
}
