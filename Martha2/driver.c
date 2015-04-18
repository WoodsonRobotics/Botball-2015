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
	shut_down_in(118);
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
	printf("height: %d at %d \n",get_object_bbox(channel,i).height,get_object_center(channel,i).x);
	camera_update();
	if(get_object_count(channel) < 1) {
		//scan();
		move(-300,-300);
		msleep(200);
		stop();
	}
	camera_update();
	while(get_object_center(channel,i).x < LBOUND){
		camera_update();
		move(0,-150);
		//printf("COORD IS %d\n", get_object_center(channel,i).x);
		printf("to the left \n");
	}
	stop();
	camera_update();
	while(get_object_center(channel,i).x > RBOUND) {
		camera_update();
		move(-150,0);
		printf("to the right \n");
	}
	stop();
	camera_update();
	while(get_object_bbox(channel,i).height < RBHB) {
		camera_update();
		move(100,100);
	}
	stop();
	camera_update();
	while(get_object_bbox(channel,i).height > RTHB) {				
		camera_update();
		move(-200,-200);
	}
	stop();

}
	
	//check x value of the object
	//move to align x value (either move claw if close by, or turn and move towards it)
	//find area of object and move forward/back in order to align claw


int isCenter(int channel, int i) {
	if(LBOUND < get_object_center(channel,i).x < RBOUND) {
		return 1;
	} else {
		return 0;
	}
	
}

void agitate() {
	set_servo_position(clawPort,clawclose);
	msleep(800);
	set_servo_position(armPort,armdown);
	msleep(800);
	set_servo_position(pivotPort,pivotrest-5); //?
	msleep(800);
	set_servo_position(pivotPort,pivotrest+5); //?
	msleep(800);
	set_servo_position(pivotPort,pivotrest); //?
	msleep(800);
	set_servo_position(armPort,armrest);
	msleep(800);
	set_servo_position(clawPort,clawrest);
	msleep(800);
}
void scan() {
	// Move Martha around to look for poms lined up
	int i = 0;
	while(get_object_count(redVal) == 0) {
		printf("looking for red.... \n");
		move(-100,100);
		msleep(200);
		i++;
		camera_update();
		if(i > 13) {
			printf("nope.. \n");
			break;
		}
	}
	printf("found one \n");
	stop();
	
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
	msleep(1000);
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

