#include <stdio.h>
#include "driver.h"

int main() {
	
	printf("Press A for start and C to test camera data \n");
	
	while(1){
	if(a_button()) {
		setup();
		
		//move(1000,1000);
		msleep(2000);
		stop();
		
		printf("time to grab red poms \n");
		
		//check for poms of interest
		camera_update();
		while(POMS < 6) {
			camera_update();
			if(get_object_count(redVal) > 0) {
				align(redVal, 0); //takes channel and int
				grab();
				//....?
			}
			else if(get_object_count(redVal) < 1) {
				//agitate(); //move poms around
				camera_update();
				if(get_object_count(redVal) < 1) {
					scan();
					camera_update();
				}
			}
		}
	}
	//if(b_button()) {}
	
	if(c_button()) {
		printf("A for coordinate B for area C for alternate \n");
		while(1==1) {
			camera_update();
			if(a_button()) {
				camera_update();

				printf("Red pom is at %d \n", get_object_center(redVal,0).x);
				printf("Green pom is at %d \n", get_object_center(greenVal,0).x);
			}
			if(b_button()) {
				camera_update();
				
				printf("Red pom's height is %d \n", get_object_bbox(redVal,0).height);
				printf("green pom's height is %d \n", get_object_bbox(greenVal,0).height);
			}
			if(c_button()) {
				//align(redVal, 0);
				//grab();
				scan();
			}
		}
			/*int red = get_object_count(redVal);
			int green = get_object_count(greenVal);
			int total = red + green;
			
			printf("Red: %d, Green: %d, Total: %d \n", red, green, total);
			
			int Rpositions[red];
			int Gpositions[green];
			int i;
			for(i = 0; i < total; i++) {
				positions[i] = get_object_position(greenVal,i).x; //don't know what color!!
			}*/
			
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}
