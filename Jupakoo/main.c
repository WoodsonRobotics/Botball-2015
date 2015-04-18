#include "jp.h"

void setup()
{
	printf("Nooice\n");
	//wait_for_light(0); 
	//shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	enable_servos();
	create_connect();
	// ugly hack to make get_servo_position work as it returns last set position
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

void run () 
{
	msleep(1);
	// Pick up cubes
	armDown();
	clawClose(); 
	armMiddle();
	// orient
	//turn(100,45);
	// pick up cubes 
	
	// Move toward first poms
	move(200,280);
	/*
	turn(100,45);
	// Move toward second poms
	move(200,763);
	turn(100,-45);
	// Move toward end
	move(200,200);
	// Move back to top board
	armUp();
	turn(100,-90);
	clawOpen();
	move(100,500);
	*/
}
int main() 
{
	setup();
	
	//run();
	//move(100,100); 
	/*
	msleep(3000);
	armMiddle();
	msleep(5000);
	armUp();
	msleep(5000);
	armDown();
	*/
	shutdown();
	return 0;
}

