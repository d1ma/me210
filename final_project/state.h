#ifndef State_h
#define State_h

#include <Timers.h>

enum line_state_t{
	line_normal;
	line_timed_instruction;
	line_saving;
};


enum game_state_t {
	state_init,
	state_line_searching,
	state_line,
	state_dunk
};


enum line_orientation_t {
	unknown,
	right,
	left
};


class State{
public:
	State();
	virtual void execute(Driver d, LightModule lm);
	virtual bool done();
	void resetTimer(int millis);
	bool timerExpired();
private:
	int _timer;
};

bool State::timerExpired(){
  	return (bool)TMRArd_IsTimerExpired(_timer);
}

void State::resetTimer(int millis){
  TMRArd_InitTimer(_timer, millis);
}

class TestTurnRight : public State {
public:
	TestTurnRight(int amount);
	void execute(Driver d, LightModule lm);
	void bool done();
};


TestTurnRight::TestTurnRight(int amount){
	resetTimer(amount);
}

void TestTurnRight::execute(Driver d, LightModule lm){
	d.turnRight();
}

bool TestTurnRight::done(){
	return timerExpired();
}


#endif

