void move(int speed, int distance)
{
	set_create_distance(0);
	create_drive_straight(-1*speed);
	
	if(distance > 0){
	while(-1*get_create_distance() < distance)
		printf("%d mm moved\n", get_create_distance());
	}else{
	while(get_create_distance() < distance)
		printf("%d mm moved\n", get_create_distance());
	}
	create_stop();
}

void turn(int speed, int angle)
{
	
}
