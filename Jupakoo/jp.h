// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

#define claw 1
#define arm 0

#define OPEN 600
#define CLOSE 1400

#define UP 0
#define DOWN 0
#define ssp(port,position) set_servo_positon(port,position)
void setup();

//Speed is in mm/sec on interval [-500,500], distance is in mm;
void move(int speed, int distance);

//Speed is in mm/s on interval [-500,500]
//Angle is positive angle is counterclockwise
void turn(int speed, int angle);

#endif
