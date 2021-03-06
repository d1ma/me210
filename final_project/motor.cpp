#import "Arduino.h"
#import "motor.h"
Motor::Motor(int enablePin, int dirPin, int calibratedValue){
	_enablePin = enablePin;
	_dirPin = dirPin;
  _lastPwm = 0;
  _pow = calibratedValue;
       
	pinMode(_enablePin, OUTPUT);
	pinMode(_dirPin, OUTPUT);
}

bool signChanged(int one, int two){
  if (!((one > 0 and two > 0) || (one < 0 and two < 0))){
    return true;
  }
}

void Motor::move(int pwm){
  //if (pwm != _lastPwm){
    Serial.print("Motor: ");
    Serial.println(pwm);
    bool sc = signChanged(pwm, _lastPwm);
    if (sc){
      int dir = (pwm > 0) ? HIGH : LOW;
      digitalWrite(_dirPin, dir);
    }
    if (pwm >= 0){
      analogWrite(_enablePin, pwm);
    }else{
      analogWrite(_enablePin, -pwm);
    }
    _lastPwm = pwm;
  //}
}

void Motor::move(bool forward){
  if (forward)
  {
    this->move(_pow);
  }else{
    this->move(-_pow);
  }
}


