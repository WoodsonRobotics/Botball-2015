#include <stdio.h>
#include "jp.h"

void setup()
{
	//wait_for_light(0); // change the port number to match where your robot 
	//shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	create_connect();
}

int main()
{
	printf("Noice\n");
	setup();
	printf("Battery: %d\n",get_create_battery_capacity());
	
	move(100,100);

	create_disconnect();
	printf("Bai bai\n");
	return 0;
}
