#include "jp.h"

double runtime;

void setup()
{
	printf("Nooice\n");
	runtime = seconds();
	
	msleep(100);
	create_connect();
	msleep(100);
	create_full(); //De-activate them pesky saftey features ;)
	msleep(100);
	printf("create connected\n");
	
	printf("Battery: %d\n",get_create_battery_capacity());
}

void shutdown() 
{
	create_disconnect();
	disable_servos();
	printf("Runtime %d\n", (int) (seconds()-runtime));
	printf("Bai bai\n");
}

void run () //#useless
{
	// orient
	//turn(100,90);
	// pick up cubes
	msleep(2000);
	armDown();
	//msleep(2000);
	//clawClose(); 
	//armMiddle();
	// Move toward first poms
	//move(200,500);
	/*
	turn(100,45);
	// Move toward second poms
	move(200,500);
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
	wait_for_light(0); 
	// ugly hack to make get_servo_position work as it returns last set position
	shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	enable_servos();
	ssp(ARM_A, MIDDLE);
	ssp(ARM_B, 2047-MIDDLE);
	
	
	//Move to pick up pink blocks
	clawOpen();
	msleep(1000);
	armDown();

	msleep(1000);
	move(100,260);
	
	msleep(2000);
	clawClose();
	msleep(1000);
	armUp();
	
	msleep(50);
	move(100, 30);
	msleep(1000);
	//End move to pick up pink blocks
	//Move into Poms and turn
	move(100,200);
	msleep(500);
	turn(50,41);//first turn
	msleep(1000);
	move(100,180);
	msleep(500);
	clawOpen();
	msleep(500);
	move(-100,350);
	msleep(500);
	armMiddle();
	//Move under Bridge then to the other side
	msleep(500);
	move(100,1550);
	msleep(500);
	//Second set of poms
	move(-100, 500);
	msleep(1000);
	turn(50,45);
	move(100,250);
	msleep(500);
	turn(50,-45);
	msleep(500);
	move(100,380);
	//Return to bridge
	armUp();
	msleep(500);
	move(-100,400);
	turn(50,-90);
	move(-100,160);
	//turn(50,-90);
	//move(100,20);
	clawOpen();
	msleep(1000);
	//setArmPosition(UP+100);
	disable_servos();
    msleep(1000);
	move(200,480);
	msleep(500);
    enable_servos(); 
	msleep(1000);
	armUp();
	move(-200,110);
	disable_servos();
	msleep(1000);
	move(500,150);
	msleep(1000);
	enable_servos();
	msleep(1000);
	move(-200,110);
	msleep(1000);
	move(500,170);
	
	
	shutdown();
	return 0;
}

