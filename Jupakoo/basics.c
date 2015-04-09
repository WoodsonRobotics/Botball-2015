#include "jp.h"

void setup() {
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);		
}

void move(int direction, int speed, float seconds) {
	int lsp = 0; // left speed in mm/sec
	int rsp = 0; // right speed in mm/sec
	switch(direction) {
		case L:
			rsp = speed;
			lsp = -1*speed;
			break;
		case R:
			lsp = -1*speed;
			rsp = speed;
			break;
		case F:
			lsp = speed;
			rsp = speed;
			break;
		case B:
			lsp = -1*speed;
			rsp = -1*speed; 
		default:
			
			break;
	}
	create_drive_direct(lsp,rsp);
	msleep(seconds * 1000);
	create_stop();
}

