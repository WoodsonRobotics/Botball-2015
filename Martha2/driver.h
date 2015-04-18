// Created on Fri April 17 2015

// Replace FILE with your file's name
#ifndef _FILE_H_
#define _FILE_H_

#define leftWheel 0   // motor
#define rightWheel 1  // motor
#define clawPort 3 	 // servo
#define armPort 2  	 // servo
#define pivotPort 1  	 // servo
#define dumpPort 0  	 // servo

#define lightPort 0   // infrared analog
#define touchPort 15  // analog

#define greenVal 0
#define redVal 1

#define armrest 350
#define armdown 1140
#define pivotrest 2047
#define pivotback 215
#define clawrest 1250
#define clawclose 1400
#define clawopen 1100
#define dumprest 1000
#define dumpup 1700

#define LBOUND 50
#define RBOUND 90 

#define RBHB 75
#define RTHB 85
#define	GBHB 5
#define GTHB 20
static int POMS = 0;

void setup();
void move(int lspeed, int rspeed);
void stop();
void align(int channel, int i);
void grab();
void dump();
void agitate();
void scan();


#endif
