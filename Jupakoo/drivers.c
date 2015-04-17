#include "jp.h"

void move(int speed, int distance)
{
	set_create_distance(0);
	create_drive_straight(-1*speed);
	
	if(distance > 0)
	{
		while(-1*get_create_distance() < distance)
		{
			printf("%d mm moved\n", get_create_distance());
		}
	}
	else
	{
		while(get_create_distance() < distance)
		{
			printf("%d mm moved\n", get_create_distance());
		}
	}
	create_stop();
}

void turn(int speed, int angle)
{
	set_create_total_angle(0);
	if(angle < 0) 
	{
		create_spin_CW(speed);
		
		while(get_create_total_angle() > angle) 
		{
			printf("%d degrees turned\n", get_create_total_angle());
		}
		
		create_stop();
	} 
	
	else 
	{
		create_spin_CCW(speed);
		
		while(get_create_total_angle() < angle) 
		{
			printf("%d degrees turned\n", get_create_total_angle());
		}
		create_stop();
	}
}

void armUp() 
{
	ssp(arm,UP);
}
void armMiddle()
{
	ssp(arm,MIDDLE);
}

void armDown()
{
	ssp(arm,DOWN);
}

void clawOpen() 
{
	ssp(claw,OPEN);
}

void clawClose()
{
	ssp(claw,CLOSE);
}
