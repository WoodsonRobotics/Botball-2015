// Functions for Martha
#ifndef _HEADER_H_
#define _HEADER_H_

#define leftWheel 3   // motor
#define rightWheel 2  // motor
#define clawPort 1 	 // servo
#define armPort 2  	 // servo
#define dumpPort 3  	 // servo

#define lightPort 0   // infrared analog
#define topHatPort 2  // analog
#define touchPort 15  // analog

#define greenVal 0
#define redVal 1

extern int poms;
void setup();
void move(int speed, float seconds);
void scan();
void grab();
void dump();

#endif
