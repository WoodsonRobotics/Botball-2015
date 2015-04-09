#include <stdio.h>
#include "jp.h"

int main () {
	create_connect();
	setup();
	move(F,100,1);
	move(B,100,1);
	move(L,100,1);
	move(R,100,1);
	create_disconnect();
	return 0;
}
