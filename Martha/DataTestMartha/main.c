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
#define armdown 807
#define pivotrest 2046
#define pivotback 300
#define clawrest 550
#define clawclose 730
#define clawopen 400
#define dumprest 1000
#define dumpup 1700

int main() {
	
	set_servo_position(pivotPort,pivotrest);
	set_servo_position(clawPort,clawrest);
	//set_servo_position(dumpPort,dumprest);
	set_servo_position(armPort,armrest);
	
	enable_servos();
	
	//move_relative_position(leftWheel,500,1000L);
	
	printf("eetryjukyjhdgjmkujthgrs");
	camera_open(LOW_RES);
	
	/*mav(rightWheel, 500);
	mav(leftWheel, 500);
	msleep(300);
	mav(rightWheel, 0);
	mav(leftWheel, 0);*/
	
	//while(1==1) {}
	/*printf("%d: ", i);
	if(get_object_count(greenVal) > get_object_count(redVal)) {
	printf("%d: %d \n", i, isCenter(greenVal));
	}
	if(get_object_count(redVal) > get_object_count(greenVal)) {
	printf("%d: %d \n", i, isCenter(redVal));
	}
	
	i++;
	msleep(400);*/
	
	/*	
	if(a_button()) {
	set_servo_position(clawPort, clawclose);
	}
	if(b_button()) {
	set_servo_position(clawPort, clawrest);
	}
	if(c_button()) {
	set_servo_position(clawPort, clawopen);
	}
	}
	*/
	int i = 0;
	while(1==1) {
		int a = 0;
		if(a_button()) { //for general checking
			camera_update();
			
<<<<<<< HEAD
		/*	
			if(a_button()) {
				set_servo_position(clawPort, clawclose);
			}
			if(b_button()) {
				set_servo_position(clawPort, clawrest);
			}
			if(c_button()) {
				set_servo_position(clawPort, clawopen);
			}
		}
		*/
		int i = 0;
		while(1==1) {
			int a = 0;
			if(a_button()) { //for general checking
				camera_update();
				
				if(get_object_count(greenVal) > 0) {
					printf("\n%d: green pom at %d,%d \n", i, get_object_center(greenVal,a).x,get_object_center(greenVal,a).y);
				} else if(get_object_count(redVal) > 0) {
					printf("\n%d: red pom at %d,%d \n", i, get_object_center(redVal,a).x,get_object_center(redVal,a).y);
				}			
				i++;
			}
			if(b_button()) {
				camera_update();
				printf("\n First pom is at %d,%d\n", get_object_center(greenVal,0).x, get_object_center(greenVal,0).y);
				printf("\n Second pom is at %d,%dc\n", get_object_center(greenVal,1).x, get_object_center(greenVal,1).y);
			}
	
=======
			if(get_object_count(greenVal) > 0) {
				printf("%d: green pom at %d,%d \n", i, get_object_center(greenVal,a).x,get_object_center(greenVal,a).y);
				} else if(get_object_count(redVal) > 0) {
				printf("%d: red pom at %d,%d \n", i, get_object_center(redVal,a).x,get_object_center(redVal,a).y);
			}			
			i++;
>>>>>>> origin/master
		}
		if(b_button()) {
			camera_update();
			printf("First pom is at %d,%d", get_object_center(greenVal,0). x,get_object_center(greenVal,0).y);
			printf("First pom is at %d,%d", get_object_center(greenVal,1). x,get_object_center(greenVal,1).y);
		}
	}
	return 0;
}
