#include <stdio.h>
#include "hw2.h"

int main(){
	printf("func1 returns:%d\n",func1());
	printf("func2 returns:%d\n",func2());
	printf("global variable value: %d\n",g_magic_number);
	
	return 0;
}
