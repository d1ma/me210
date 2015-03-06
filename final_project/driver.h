#ifndef Driver_h
#define Driver_h

#import "Arduino.h"
#import "decision_maker.h"
#import "motor.h"
    
class Driver{
  public:
    Driver();
    void straight();
  	void rotateLeft();
  	void rotateRight();
  	void stop();
    Motor _leftMotor = Motor(3,2,170);
    Motor _rightMotor = Motor(5,4,170);
  private:
  	int _timer = 5;
  	bool timerExpired();
  	void resetTimer(int millis);
};

#endif
