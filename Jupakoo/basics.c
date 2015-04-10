#include "jp.h"

struct coords {
	int l;
	int r;
};
void setup() {
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);		
}

struct coords direct(int direction, int speed) {
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
	struct coords dir;
	dir.l = lsp;
	dir.r = rsp;
	return dir;
}
void move(int direction, int speed, float seconds) {
	int lsp;
	int rsp;
	struct coords dir;
	dir = direct(direction, speed);
	lsp = dir.l;
	rsp = dir.r;
	create_drive_direct(lsp,rsp);
	msleep(seconds * 1000);
	create_stop();
}

void mv(int speed, int distance) {
	//distance is mm
	//speed in mm/s
	set_create_distance(0);
	create_drive_direct(speed, speed);
	int dist;
	do {
		dist = get_create_distance();
	} while(dist < distance);
	create_stop();
}

void turn(int speed, int angle) {
	set_create_total_angle(0);
	int ag;
	if(angle < 0) {
		do {
			create_drive_direct(speed,-speed);
			ag = get_create_total_angle();
		} while (ag > angle);
	} else {
		do {
			ag = get_create_total_angle();
		} while(ag < angle);
	}
}
