#include "jp.h"

void setup()
{
	printf("Nooice\n");
	//wait_for_light(0); 
	//shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	create_connect();
	printf("Battery: %d\n",get_create_battery_capacity());
}

void shutdown() 
{
	create_disconnect();
	printf("Bai bai\n");
}

int main()
{
	setup();
	
	//move(100,100);
	//turn(100,180);
	//move(100,100);
	armUp();

	shutdown();
	return 0;
}
