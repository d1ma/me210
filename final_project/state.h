#ifndef State_h
#define State_h

#include <Timers.h>
#include "driver.h"
#include "Arduino.h"
#include "light_module.h"

class State{
public:
	virtual void execute(Driver d, LightModule lm) =0;
	virtual bool done() = 0;
	void resetTimer(int t, int millis);
	bool timerExpired(int t);
};


class LineFollow : public State {
public:
  LineFollow();
  void execute(Driver d, LightModule lm);
  bool done();
private:
  void adjustLeft(Driver d);
  void adjustRight(Driver d);
  bool adjusting = false;
  int countWithoutBlack = 0;
  int oldL;
  int oldR;
  int oldM; 
};






#endif

