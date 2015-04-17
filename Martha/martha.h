// Functions for Martha
#ifndef _HEADER_H_
#define _HEADER_H_

#define leftWheel 0   // motor
#define rightWheel 1  // motor
#define clawPort 3 	 // servo
#define armPort 2  	 // servo
#define pivotPort 1  	 // servo
#define dumpPort 0  	 // servo

#define lightPort 15   // infrared analog
#define topHatPort 2  // analog
#define touchPort 114  // analog

#define greenVal 0
#define redVal 1

#define armrest 1580
#define armdown 807
#define pivotrest 2048
#define pivotback 300
#define clawrest 550
#define clawclose 730
#define dumprest 800
#define dumpup 1700

//set_servo_position()
#define ssp(port,position) set_servo_position(port,position) 

extern int poms;
void setup();
void move(int speed, float seconds);
void scan();
void grab();
void dump();

#endif
