#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int poms = 0;
int main() {
	
	setup();
	
	msleep(10000); //wait for Jupakoo to push poms in place
	
	while(get_object_count(greenVal) == 0 && get_object_count(redVal) == 0) {
		printf("Looking for poms... \n");
		mav(leftWheel, 500); 
		mav(rightWheel, 500); 
		msleep(200);
		camera_update();
	}
	printf("Hey look! Poms! \n");
	
	// position correctly
	
	while(poms < 4) {
		scan(); 
	}
	
	move(-100,3);
	dump();
	
return 1;
}

