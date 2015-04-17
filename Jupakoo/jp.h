// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

// Servos
#define claw 1
#define arm 0

// Claw constants
#define OPEN 600
#define CLOSE 1400

// Arm constants
#define UP 0
#define DOWN 0
#define MIDDLE 0

// Macro for servo position
#define ssp(port,position) set_servo_position(port,position)

//Speed is in mm/sec on interval [-500,500], distance is in mm, always positive;
void move(int speed, int distance);

//Speed is in mm/s on interval (0,500]
//Positive angle is counterclockwise measured in degrees
void turn(int speed, int angle);

#endif
