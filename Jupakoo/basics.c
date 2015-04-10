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
			lsp = -1*speed;
			rsp = speed;
			break;
		case R:
			lsp = speed;
			rsp = -1*speed;
			break;
		case F:
			lsp = -1*speed;
			rsp = -1*speed;
			break;
		case B:
			lsp = speed;
			rsp = speed; 
		default:
			
			break;
	}
	create_drive_direct(lsp,rsp);
	msleep(seconds * 1000);
	create_stop();
}

void movef(int speed, int distance) {
	//distance is mm
	//speed in mm/s
	set_create_distance(0);
	creat_drive_direct(speed, speed);
	int dist = 0;
	while(dist < distance) {
		dist = get_create_distance();
	}
	create_stop();
}
