#ifndef Driver_h
#define Driver_h

#import "Arduino.h"
#import "motor.h"
    
class Driver{
  public:
    Driver();
    void straight();
    void straightAlongWall();
    void straightAlongWallSlowDown();
    void rotateLeft();
    void rotateRight();
    void turnRight();
    void turnLeft();
    void adjustLeft();
    void adjustRight();
    void turnTinyLeft();
    void back();
    void backHard();
    void rotateRightLittle();
    void rotateLeftLittle();
    void stop();
    Motor _leftMotor = Motor(3,2,175);
    Motor _rightMotor = Motor(5,4,180);
  private:
  	int _timer = 5;
  	bool timerExpired();
  	void resetTimer(int millis);
};

#endif
