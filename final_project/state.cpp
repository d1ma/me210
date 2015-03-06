
#include <Timers.h>
#include "state.h"

bool State::timerExpired(int t){
  TMRArdReturn_t r = TMRArd_IsTimerExpired(t);
  return r == TMRArd_EXPIRED || r == TMRArd_ERR;
}

void State::resetTimer(int timer, int m){
  TMRArd_InitTimer(timer, m);
}


