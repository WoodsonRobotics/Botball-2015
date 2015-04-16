// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

#define openClaw 600
#define closeClaw 1400

void setup();

//Speed is in mm/sec on interval [-500,500], distance is in mm;
void move(int speed, int distance);

//Speed is in mm/s on interval [-500,500]
//Angle is positive angle is counterclockwise
void turn(int speed, int angle);

#endif
