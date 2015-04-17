#include "martha.h"

void setup() 
{	
	set_servo_position(armPort,armrest);
	set_servo_position(clawPort,clawrest);
	set_servo_position(dumpPort,dumprest);
	set_servo_position(pivotPort,pivotrest);
	enable_servos();
	
	wait_for_light(lightPort);
	beep();

	shut_down_in(118);
	printf("Hello! I'm going to find poms. \n");
}

void move(int speed, float seconds) 
{		
	mav(leftWheel, -1*speed);
	mav(rightWheel, speed);
	msleep(seconds * 1000);
	mav(leftWheel, 0);
	mav(rightWheel, 0);
}

int isCenter(int channel) {
	if(channel == greenVal) {
		if((105 < get_object_center(greenVal,0).x < 111) && (57 < get_object_center(greenVal,0).y < 63)) 
			return 1;
	} 
	if(channel == redVal) {
		if((91 < get_object_center(greenVal,0).x < 97) && (68 < get_object_center(greenVal,0).y < 75)) 
			return 1;
	} 
	else {
		return 0;
	}
}

void scan() 
// look through pile of poms to grab() the four we need
{ 
	printf("Looking for the poms I want..\n");
	
	
}

void grab() 
// once pom is positioned corrrectly, grab and put in bucket
{ 
	printf("This one looks nice\n");
	
	set_servo_position(armPort, 1400); //arbitrary position for now
	set_servo_position(clawPort, 800); //arbitrary position for now
	set_servo_position(armPort, 0); //start position
	set_servo_position(pivotPort, 800); //start position
	set_servo_position(clawPort, 0); //open claw
	set_servo_position(pivotPort, 800); //start position
	
	poms++;
}

void dump() 
// to drop poms in startzone
{ 
	printf("Goodbye poms.\n");
	
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 600);
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 600);
	set_servo_position(dumpPort, 1000);
	set_servo_position(dumpPort, 0);
	
}
