// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

#define claw 1
#define arm 0

#define OPEN 600
#define CLOSE 1400

#define UP 0
#define DOWN 0
#define MIDDLE 0

#define ssp(port,position) set_servo_position(port,position)

// Speed is in mm/sec on interval [-500,500], distance is in mm, always positive;
void move(int speed, int distance);

// Speed is in mm/s on interval (0,500]
// Angle is positive, counterclockwise in degrees (not radians, or celsius, or fareignheight, or kelvin)
void turn(int speed, int angle);

// Move arm servo to the up position
void armUp();

// Move arm servo to the middle position
void armMiddle();

// Move arm servo to the down position
void armDown();

// Open claw
void clawOpen();

// Close claw
void clawClose();

#endif
