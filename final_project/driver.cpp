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

void Driver::backHard() {
  _leftMotor.move(-_leftMotor._pow);
  _rightMotor.move(-_rightMotor._pow);
}
void Driver::back(){
  _leftMotor.move(false);
  _rightMotor.move(false);
  
}

void Driver::turnTinyLeft(){
  _leftMotor.move(-90);
  _rightMotor.move(200);
  delay(250);
  stop();
}

void Driver::straightAlongWall(){
  _leftMotor.move(180);
  _rightMotor.move(176);
  
 
//  delay(250);
//  stop();
//  delay(50);
}

void Driver::straightAlongWallSlowDown(){
  static bool timerInited = false;
  if (!timerInited){
    TMRArd_InitTimer(11, 800);
    timerInited = true;
  }
  if (TMRArd_IsTimerExpired(11)){
    _leftMotor.move(141);
    _rightMotor.move(141); 
  } else{
    _leftMotor.move(150);
    _rightMotor.move(150);
  }
}
  
  

void Driver::straight(){

	_rightMotor.move(true);
	_leftMotor.move(true);
//        delay(100);
//        stop();
//        delay(10);
//        delay(250);
//        stop();
//        delay(40);
}

void Driver::rotateLeft(){
	_rightMotor.move(true);
	_leftMotor.move(false);

}

void Driver::rotateLeftLittle(){
         _rightMotor.move(220);
         _leftMotor.move(-220);
         delay(200);
         stop();
}

void Driver::rotateRight(){
  _rightMotor.move(false);
  _leftMotor.move(true);
}

void Driver::rotateRightLittle(){
	_leftMotor.move(-220);
	_rightMotor.move(220);
        delay(200);
        stop();
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
