#include "jp.h"

void setup() {	
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);		
}

void move(int direction, int speed, float seconds) {		
	mav(leftWheel, -1*speed);
	mav(rightWheel, speed);
	msleep(seconds * 1000);
	mav(leftWheel, 0);
	mav(rightWheel, 0);
}

