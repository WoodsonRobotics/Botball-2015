#include "martha.h"

void setup() {	
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);
	printf("Hello! I'm going to find poms. \n");
}

void move(int speed, float seconds) {		
	mav(leftWheel, -1*speed);
	mav(rightWheel, speed);
	msleep(seconds * 1000);
	mav(leftWheel, 0);
	mav(rightWheel, 0);
}

void scan() { // look through pile of poms to grab() the four we need
	printf("Looking for the poms I want..\n");
	
	
}

void grab() { // once pom is positioned corrrectly, grab and put in bucket
	printf("This one looks nice\n");
	
	set_servo_position(armPort, 1400); //arbitrary position for now
	set_servo_position(clawPort, 800); //arbitrary position for now
	set_servo_position(armPort, 0); //start position
	set_servo_position(pivotPort, 800); //start position
	set_servo_position(clawPort, 0); //open claw
	set_servo_position(pivotPort, 800); //start position
	
	poms++;
}

void dump() { // to drop poms in startzone
	printf("Goodbye poms.\n");
	
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 600);
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 600);
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 0);
	
}
