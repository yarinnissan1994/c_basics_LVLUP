#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main(int argc, char* argv[])
{
	int a;
	int b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("Start \n");
	printf("%d+%d=%d \n",a,b,a+b);
	printf("End \n");
	return 0;
}