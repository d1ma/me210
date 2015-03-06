#ifndef motor_h
#define motor_h
#import "Arduino.h"

class Motor{
  public:
    Motor(int enablePin, int dirPin, int calibratedValue);
    void move(int pwm);
    void move(bool forward);
    int _pow;

  private:
    int _enablePin;
    int _dirPin;
    int _lastPwm;
};

#endif
