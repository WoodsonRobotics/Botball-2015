#include <stdio.h>
#include "jp.h"



int main () {
	create_connect();
	//setup();
	
	mv(100,1000);
	turn(100,90);
	
	create_disconnect();
	return 0;
}
 
