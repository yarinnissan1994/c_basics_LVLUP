#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<limits.h>
#pragma warning(disable : 4996)

void shiftLeft(unsigned char num, unsigned char steps) {
	for (int i = 0; i < steps; i++) {
		num <<= 1;
	}
	printf("After shifting left %d steps: ", steps);
	printf("%d", num);
}

void printMask(unsigned char num) {
	num &= 1111111;
	num == 1 ? printf("%d It's 1.\n", num) : printf("%d It's not 1.\n", num);
}

void binaryFormat(unsigned char num) {
	unsigned char maskNum = 0b10000000;
	int binFormat[8];
	for (int i = 0; i < 8; i++) {
		binFormat[i] = (num & maskNum) != 0 ? 1 : 0;
		maskNum >>= 1;

	}

	printf("\n********\n%d in binary format: ", num);
	for (int i = 0; i < 8; i++) {
		printf("%d", binFormat[i]);

	}
}

int main3()
{
	int num = INT_MIN;
	int temp = num, steps = 0;
	while (temp) {
		steps++;
		temp /= 2;
	}
	
	for (int i = 0; i < steps; i++) {
		num <<= 1;
	}
	
	printf("%d %d\n********\n", num, steps);
	
	unsigned char num2;
	int steps2;
	printf("Insert num and steps to shift to left please: ");
	scanf_s("%d%d", &num2, &steps2);
	shiftLeft(num2, steps2);
	printf("\n**********\n");
	printMask(1);
	printMask(5);
	binaryFormat(20);
	
	return 0;
}