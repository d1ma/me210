#include "decision_maker.h"
#include "state.h"


void goStraight(){
	_leftMotor.move(true);
	_rightMotor.move(true);
}

DecisionMaker::DecisionMaker(){
	_state = State();
}

driver_dir_t followLine(lm_res_t lm_res){
	switch (lm_res){
	  case bbb:
	    return drive_forward;
	  case bbw:
	  	return drive_turn_left;
	  case wbw:
	  	return drive_forward;
	  case wbb:
	  	return drive_turn_right;
	  case wwb:
	  	return drive_turn_right;
	  case bww:
	  	return drive_turn_left;
	  case www:
	    /* Put on indicator lights to signal panic */
	  	return drive_stop;
	  default:
	  	return drive_stop;
	}
}

bool isOnBlack(lm_res_t lm_res){
	return (lm_res == wbb || lm_res == wbw || lm_res == bbw || lm_res == bbb);
}

void turn90Left(){
	_state.line_mode = line_timed_instruction;

}

driver_dir_t DecisionMaker::driveDecision(lm_res_t lm_res){
	if (_state.game_state == state_init){
		_state.game_state = state_line_searching;
	}
	if (_state.game_state == state_line_searching){
		goStraight();
		if (isOnBlack()){
			_state.game_state = state_line_turn_left;
			turnLeft();
		}
	}

	return drive_stop;
}

String DecisionMaker::toString(driver_dir_t d){
	switch(d){
		case drive_forward:
			return "FORWARD";
		case drive_turn_left:
			return "T LEFT";
		case drive_turn_right:
			return "T RIGHT";
		case drive_stop:
			return "STOP";
		default:
			return "n/a";
	}
}
