// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

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

#define openClaw 600
#define closeClaw 1400

//set_servo_position()
#define ssp(port,position) set_servo_position(port,position) 

void setup();

//Speed is in mm/sec on interval [-500,500], distance is in mm;
void move(int speed, int distance);

//Speed is in mm/s on interval [-500,500]
//Angle is positive angle is counterclockwise
void turn(int speed, int angle);

#endif
