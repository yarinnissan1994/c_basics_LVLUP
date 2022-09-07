#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
int func1(int num1, int num2, int num3, int num4)
{
	int* ptr;
	int* original;
	ptr = malloc(sizeof(int) * 4);
	original = ptr;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) 
		{
			*ptr = num1;
			ptr++;
		}
		else if (i == 1)
		{
			*ptr = num2;
			ptr++;
		}
		else if (i == 2)
		{
			*ptr = num3;
			ptr++;
		}
		else
		{
			*ptr = num4;
			ptr++;
		}
	}
	ptr = original;
	for (int i = 0; i < 4; i++)
	{
		printf("%d\t", *ptr);
		ptr++;
	}
	free(original);
	return 0;
}
int* func2(int num1, int num2, int num3, int num4, int num5)
{
	int* ptr;
	int* original;
	ptr = malloc(sizeof(int) * 5);
	original = ptr;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			*ptr = num1;
			ptr++;
		}
		else if (i == 1)
		{
			*ptr = num2;
			ptr++;
		}
		else if (i == 2)
		{
			*ptr = num3;
			ptr++;
		}
		else if (i == 3)
		{
			*ptr = num4;
			ptr++;
		}
		else
		{
			*ptr = num5;
			ptr++;
		}
	}
	return original;
}
int printFunc2(int* ptr)
{
	int* point = ptr;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", (*point));
		sum = sum + (*point);
		point++;
	}
	printf("\n%d", sum);

	return sum;
}
int func3()
{
	int num;
	printf("Enter the amount of numbers you want us to add and sum for you:\n");
	scanf("%d", &num);
	return num;

}
int main1_2()
{
	//func1(2, 4, 6, 8);


	/* func2
	int* FiveNums = func2(10, 20, 30, 40, 50);
	printf("\n%d",printFunc2(FiveNums));
	free(FiveNums);
	//*/

	//*func3
	int* ptr;
	int* original;
	int num = func3();
	ptr = malloc(sizeof(int) * num);
	original = ptr;
	for (int i = 0; i < num; i++)
	{
		printf("please enter a number:\n");
		scanf("%d", ptr);
		ptr++;
	}
	ptr = original;
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", (*ptr));
		sum = sum + (*ptr);
		ptr++;
	}
	printf("\n%d", sum);
	free(original);
	//*/
	return 0;
}

/*

	int a = 90;
	int c = 88;
	int* b;

	b = &a;
	printf("%x\n", b);
	printf("%d\n", *b);

	a = 100;
	printf("%x\n", b);
	printf("%d\n", *b);

	b = &c;

	b = malloc(10 * sizeof(int));
	*b = 100;
	int* original = b;
	b++;
	*b = 200;

	char* charPtr;
	charPtr = b;
	charPtr++;
	*charPtr = 'A';


	free(original);
*/