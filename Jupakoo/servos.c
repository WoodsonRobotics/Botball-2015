#include "jp.h"

void setArmPosition(int pos)
{
	int a = get_servo_position(ARM_A);
	int b = get_servo_position(ARM_B);
	//ssp(ARM_A, a);
	//ssp(ARM_B, b);
	
	printf("Servos starting at a,b: %d, %d\n", a, b);
    if(a < pos)
	{
		while(a < pos)
		{
			ssp(ARM_A,a++);
			ssp(ARM_B,2047-a);
			a = get_servo_position(ARM_A);
			b = get_servo_position(ARM_B);
			printf("Servos a,b: %d, %d\n", a, b);
			msleep(1000);
		}
	} 
	else 
	{
		while(a > pos)
		{
				ssp(ARM_A,a--);
				ssp(ARM_B,2047-a);
				a = get_servo_position(ARM_A);
			    b = get_servo_position(ARM_B);
				printf("Servos a,b: %d, %d\n", a, b);
				msleep(1000);
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
