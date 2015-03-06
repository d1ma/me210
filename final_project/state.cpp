#include "timer.h"
#include <Timers.h>

State::State(){
	TMRArd_InitTimer(_timer, 0);
}


void timerRest(int millis){
	TMRArd_InitTimer(_timer, millis);
}

bool isTimerExpired(){
	return (bool) TMRArd_IsTimerExpired(_timer);
}