#include "driver.h"


void setup() {
	camera_open(LOW_RES);
	//servo positions
	set_servo_position(clawPort,clawrest);
	set_servo_position(armPort,armrest);
	set_servo_position(pivotPort,pivotrest);
	 
	enable_servos();
	beep();
	printf("Hello. \n");
	//wait_for_light(lightPort); //find the port
}

// 0 to 1000
void move(int lspeed, int rspeed) {	
	mav(leftWheel, lspeed);
	mav(rightWheel, rspeed);
}

void stop() {
	mav(leftWheel,0);
	mav(rightWheel,0);
}

void align(int channel, int i) {
	if(get_object_center(channel,i).x < LBOUND) {
		while(get_object_center(channel,i).x < LBOUND){
			camera_update();
			move(100,0);
			printf("COORD IS %d\n", get_object_center(channel,i).x);
		}
		stop();
	}
	else if(get_object_center(channel,i).x > RBOUND) {
		while(get_object_center(channel,i).x > RBOUND) {
			move(0,100);
			camera_update();
		}
		stop();
	}
	
	if(channel == redVal) {
		if(get_object_bbox(channel,i).height < RBHB){
			while(get_object_bbox(channel,i).height < RBHB) {
				camera_update();
				move(100,100);
			}
			stop();
		}
		else if(get_object_bbox(channel,i).height > RTHB) {
			while(get_object_bbox(channel,i).height > RTHB) {
				camera_update();
				move(-100,-100);
			}
			stop();
		}
	}
	else if(channel == greenVal) {
		if(get_object_bbox(channel,i).height < GBHB){
			while(get_object_bbox(channel,i).height < GBHB) {
				camera_update();
				move(-100,-100);
			}
			stop();
		}
		else if(get_object_bbox(channel,i).height > GTHB) {
			while(get_object_bbox(channel,i).height > GTHB) {
				camera_update();
				move(100,100);
			}
			stop();
		}
	}
	
	//check x value of the object
	//move to align x value (either move claw if close by, or turn and move towards it)
	//find area of object and move forward/back in order to align claw
}

int isCenter(int channel, int i) {
	if(LBOUND < get_object_center(channel,i).x < RBOUND) {
		return 1;
	} else {
		return 0;
	}
	
}

void agitate() {
	set_servo_position(clawPort,clawclose);
	set_servo_position(armPort,armdown);
	set_servo_position(pivotPort,pivotrest-20); //?
	set_servo_position(pivotPort,pivotrest+20); //?
	set_servo_position(pivotPort,pivotrest); //?
	set_servo_position(armPort,armrest);
	set_servo_position(clawPort,clawrest);
}
void scan() {
	// Move Martha around to look for poms lined up
}

void grab() {
	printf("GRABBING\n");
	set_servo_position(clawPort,clawrest);
	set_servo_position(armPort,armdown);
	printf("ARM SHOULD BE DOWN\n");
	msleep(800);
	set_servo_position(clawPort,clawclose);
	msleep(400);
	set_servo_position(armPort,armrest);
	set_servo_position(pivotPort,pivotback);
	msleep(1000);
	set_servo_position(clawPort,clawopen);
	msleep(500);
	set_servo_position(pivotPort,pivotrest);
	set_servo_position(clawPort,clawrest);
	printf("GRABBING DONE\n");
	POMS++;
}

void dump() {
	set_servo_position(dumpPort,dumpup);
	msleep(1000);
	set_servo_position(dumpPort,dumprest);
}

