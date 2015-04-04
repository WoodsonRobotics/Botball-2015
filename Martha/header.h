// Created on Wed April 1 2015

// Functions for Martha
#ifndef _FILE_H_
#define _FILE_H_

#define leftWheel 3   // motor
#define rightWheel 2  // motor
#define clawPort 1 	 // servo
#define armPort 2  	 // servo
#define dumpPort 3  	 // servo

#define lightPort 0   // infrared analog
#define topHatPort 2  // analog
#define touchPort 15  // analog

#define pinkVal 0
#define redVal 1


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



#endif
