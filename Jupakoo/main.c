#include <stdio.h>
#include "jp.h"



int main () {
	printf("Noice\n");
	create_connect();
	printf("Battery: %d\n",get_create_battery_capacity());
	//setup();
	
	mv(100,1000);
	turn(100,90);
	
	create_disconnect();
	printf("Shutting Down...\n");
	return 0;
}
 
