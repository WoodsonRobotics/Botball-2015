#include "jp.h"

void setup()
{
	printf("Nooice\n");
	//wait_for_light(0); 
	//shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	enable_servos();
	create_connect();	
	ssp(ARM_A, 0);
	ssp(ARM_B, 2047);
	printf("Battery: %d\n",get_create_battery_capacity());
}

void shutdown() 
{
	create_disconnect();
	disable_servos();
	printf("Bai bai\n");
}

int main()
{
	setup();
	
	
	armUp();
	msleep(5000);
	armMiddle();
	msleep(5000);
	armUp();
	msleep(5000);
	armDown();
	
	shutdown();
	return 0;
}
