#include "jp.h"

void setup()
{
	//wait_for_light(0); 
	//shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	create_connect();
}

void shutdown() 
{
	create_disconnect();
	printf("Bai bai\n");
}

int main()
{
	printf("Nooice\n");
	setup();
	printf("Battery: %d\n",get_create_battery_capacity());
	
	turn(100,-75);
	msleep(10);


	shutdown();
	return 0;
}
