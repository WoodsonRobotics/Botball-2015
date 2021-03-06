// Functions for Jupakoo
#ifndef _JP_H_
#define _JP_H_

#define POLL_TIME 1

// Servos
#define CLAW 1

#define ARM_A 0
#define ARM_B 2

// Claw constants
#define OPEN 100
#define CLOSE 2040

// Arm constants  All Arm constatns are (0,2047) <- non-inclusive!!!!!!
#define UP 1 
#define MIDDLE 1400
#define DOWN 2046

// Macro for servo position
#define ssp(port,position) set_servo_position(port,position)

//Speed is in mm/sec on interval [-500,500], distance is in mm, always positive;
void move(int speed, int distance);

//Speed is in mm/s on interval (0,500]
//Positive angle is counterclockwise measured in degrees
void turn(int speed, int angle);

void setArmPosition(int position);

void armUp();
void armDown();

void clawOpen();

void clawClose();


#endif
