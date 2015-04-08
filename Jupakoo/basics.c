#include "jp.h"

void setup() {	
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);		
}

void move(int direction, int speed, float seconds) {
	int lsp = 0; // left speed
	int rsp = 0; // right speed
	switch(direction) {
		case L:
			rsp = speed;
			lsp = speed;
			break;
		case R:
			lsp = -1*speed;
			rsp = -1*speed;
			break;
		case F:
			lsp = -1*speed;
			rsp = speed;
			break;
		case B:
			lsp = speed;
			rsp = -1*speed; 
		default:
			
			break;
	}
	mav(leftWheel, lsp);
	mav(rightWheel, rsp);
	msleep(seconds * 1000);
	mav(leftWheel, 0);
	mav(rightWheel, 0);
}

