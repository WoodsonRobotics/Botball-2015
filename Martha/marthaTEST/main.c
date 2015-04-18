#include <stdio.h>

#define leftWheel 0   // motor
#define rightWheel 1  // motor
#define clawPort 3 	 // servo
#define armPort 2  	 // servo
#define pivotPort 1  	 // servo
#define dumpPort 0  	 // servo

#define lightPort 0   // infrared analog
#define topHatPort 2  // analog
#define touchPort 15  // analog

#define greenVal 0
#define redVal 1

#define armrest 1580
#define armdown 745
#define pivotrest 2046
#define pivotback 320
#define clawrest 1150
#define clawclose 1165
#define clawopen 1000
#define dumprest 1000
#define dumpup 1700

#define Gcx 108
#define Gcy 60
#define Rcx 95
#define Rcy 71

//opiuyfutyoihugkyftygihojiu

int isCenter(int channel);

int main() {

	//set_servo_position(clawPort,clawrest);
	//set_servo_position(armPort,armrest);
	//set_servo_position(pivotPort,pivotrest);
	//set_servo_position(clawPort,clawrest);
	enable_servos();
	
	camera_open(LOW_RES);
	camer_update();
	
	int minority;
	
	if(get_object_count(greenVal) > get_object_count(redVal)) {
		minority = greenVal; //doesn't make sense now but go with it for testing
	}
	
	while(!isCenter(minority)) {
		camera_update();
		msleep(300);
	}
	
	printf("found it? \n");
	
	
/*
	while((get_object_count(greenVal) || get_object_count(redVal)) > 0) {
		mav(leftWheel,500);
		mav(rightWheel,500);
		camera_update()
	}
	mav(leftWheel,0);
	mav(rightWheel,0);
	
	camera_update();
	while(get_object_count(greenVal) + get_object_count(redVal) < 8) {
		mav(leftWheel,200);
		mav(rightWheel,200);	
		camera_update();
	}
	mav(leftWheel,0);
	mav(rightWheel,0);	
	
	if(get_object_count(greenVal) > get_object_count(redVal) {
			minority = greenVal;
	}	
	if(get_object_count(redVal) > get_object_count(greenVal) {
			minority = redVal;
	}

	int offsetX,offsetY;
*/


	
	
return 0;	
}



//  105-111 57-63 is where a green pom can be grabbed.
//  91-97  68-75 is where a red pom can be grabbed.
// ..I don't know why..
int isCenter(int channel) {
	if(channel == greenVal) {
		if((50 < get_object_center(greenVal,0).x < 56) && (40 < get_object_center(greenVal,0).y < 46)) 
			return 1;
	} 
	if(channel == redVal) {
		if((50 < get_object_center(greenVal,0).x < 56) && (73 < get_object_center(greenVal,0).y < 76)) 
			return 1;
	} 
	else {
		return 0;
	}
}





