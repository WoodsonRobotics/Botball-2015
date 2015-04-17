#include "jp.h"

void setArmPosition(int pos)
{
	int a = get_servo_position(ARM_A);
	printf("Servos a,b: %d, %d\n", get_servo_position(ARM_A),get_servo_position(ARM_B));
	
    if(a < pos){
		printf("loop a+\n");
		while(a < pos){
			a+=1;
			ssp(ARM_A,a);
			ssp(ARM_B,2047-a);
			
			printf("Servos a,b: %d, %d\n", get_servo_position(ARM_A),get_servo_position(ARM_B));
			msleep(1); //speed controll
		}
	} else {
		printf("loop a-\n");
		while(a > pos){
				a-=1;
				ssp(ARM_A,a);
				ssp(ARM_B,2047-a);

				printf("Servos a,b: %d, %d\n", get_servo_position(ARM_A),get_servo_position(ARM_B));
				msleep(1); // speed controll
		}
	}
	ssp(ARM_A, pos);
	ssp(ARM_B, 2047-pos);
}

void armUp() 
{
	setArmPosition(UP);
	printf("DONE MOVING ARM UP\n");
}

void armMiddle()
{
	setArmPosition(MIDDLE);
	printf("DONE MOVING ARM TO MIDDLE\n");
}

void armDown()
{
	setArmPosition(DOWN);
	printf("DONE MOVING ARM DOWN\n");
}

void clawOpen() 
{
	
}

void clawClose()
{
	
}
