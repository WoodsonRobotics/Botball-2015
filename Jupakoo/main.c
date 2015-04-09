#include <stdio.h>
#include "jp.h"

int main () {
	create_connect();
	//setup();
	move(F,200,1);
	move(L,200,1);
	move(B,200,1);
	move(R,200,1);
	create_disconnect();
	return 0;
}
 
