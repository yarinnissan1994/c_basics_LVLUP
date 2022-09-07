#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

unsigned char binLeft(unsigned char num, unsigned char left)
{
	num <<= left;
	printf("%d", num);
	return num;
}
unsigned char if1(unsigned char num)
{
	char mask = 0b00000001;
	char ind = num ^ mask;

	//printf("%d", ind == 0);
}
unsigned char binPrint(unsigned char num)
{
	unsigned char hold = num;
	unsigned char mask = 0b00000001;
	for (int i = 0; i < 8; i++)
	{
		char onebit = hold & mask;
		hold >>= 1;
		printf("%d", onebit);
	}
	/*for (int i = 0; i <= 7; i++)
	{

	}*/

}
unsigned char PrintByte(unsigned char aByte)
{
	
}
int func1(char count)
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 8 - count)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}
int printOne(unsigned char x)
{
	unsigned char mask = 1;
	unsigned char result = 0;
	x = 0b00000101;
	result = x & mask >> x - 1;
	printf("%d\n", result);

}
int func2(char saveCount)
{
	char arr[8] = { 0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 8; i++)
	{
		if (i == 8 - saveCount)
		{
			if (arr[i] == 0)
			{
				arr[i] = 1;
			}
			else {
				arr[i] = 0;
			}
		}

		printf("%d", arr[i]);
	}
	printf("\n");
}


int main2()
{
	/* mask
	char a = 0b00000011;
	char b = 0b00000110;
	char c = a & b; //like && (and) gate
	char d = a | b; //like || (or) gate
	char e = a ^ b; //xor means if both are the same return 0 else return 1
	printf("%d %d %d", c, d, e);
	*/
	//binLeft(4, 2);
	//if1(1);
	/*
		int n, c, k;
		printf("Enter an integer in decimal number system\n");
		scanf("%d", &n);
		printf("%d in binary number system is:\n", n);
		for (c = 31; c >= 0; c--)
		{
			k = n >> c;
			if (k & 1)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
		*/

	//binPrint(6);
	//func1(6);



	return 0;
}
