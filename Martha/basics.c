#include "header.h"

void setup() {	
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);		
}

void move(int speed, float seconds) {		
	mav(leftWheel, -1*speed);
	mav(rightWheel, speed);
	msleep(seconds * 1000);
	mav(leftWheel, 0);
	mav(rightWheel, 0);
}

void scan() { // look through pile of poms to grab() the four we need
	printf("Looking for the poms I want..");
}

void grab() { // once pom is positioned corrrectly, grab and put in bucket
	printf("This one looks nice");
	
	
	poms++;
}

void dump() { // to drop poms in startzone
	printf("Goodbye poms.");
}
