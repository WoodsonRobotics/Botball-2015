// Created on Thu April 16 2015

// Replace FILE with your file's name
#ifndef _DRIVERS_H_
#define _DRIVERS_H_

//Speed is in mm/sec on interval [-500,500], distance is in mm;
void move(int speed, int distance);

//Speed is in mm/s on interval [-500,500]
//Angle is positive angle is counterclockwise
void turn(int speed, int angle);


#endif
