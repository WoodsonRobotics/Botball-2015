// Functions for Jupakoo
#ifndef _HEADER_H_
#define _HEADER_H_

#define leftWheel 3   	// motor
#define rightWheel 2  	// motor
#define clawPort 1 	 	// servo
#define armPort 2  	  	// servo
#define dumpPort 3  	// servo

#define lightPort 0   	// infrared analog
#define topHatPort 2  	// analog
#define touchPort 15  	// analog

// Directions
#define L 0
#define R 1
#define F 2
#define B 3

void setup();
void move(int direction, int speed, float seconds);


#endif
