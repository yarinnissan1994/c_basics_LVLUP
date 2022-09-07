#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	/* task 1
	int nums[10];
	for (int i = 0; i < 10; i++)
	{
		printf("please enter a number in cell %d:", i);
		scanf("%d", &nums[i]);
	}

	FILE* f = fopen("hm1.bin", "w");
	if (!f)
	{
		// ERROR
	}
	else
	{
		fwrite(nums, sizeof(int), 10, f);
		fclose(f);
	}

	//*/

	/* task 2
	int arr1[4];
	int arr2[8];
	int sum1 = 0, sum2 = 0;
	FILE* f = fopen("hm2.bin", "w");
	for (int i = 0; i < 4; i++)
	{
		printf("array 1 - please enter a number in cell %d:", i);
		scanf("%d", &arr1[i]);
		sum1 = sum1 + arr1[i];
	}
	for (int i = 0; i < 8; i++)
	{
		printf("array 2 - please enter a number in cell %d:", i);
		scanf("%d", &arr2[i]);
		sum2 = sum2 + arr2[i];
	}
	if (sum1 > sum2)
	{
		if (!f)
		{
			// ERROR
		}
		else
		{
			fwrite(arr1, sizeof(int), 4, f);
		}
	}
	else
	{
		if (!f)
		{
			// ERROR
		}
		else
		{
			fwrite(arr2, sizeof(int), 8, f);
		}
	}
	fclose(f);
	//*/

	/* task 3
	struct Hm3
	{
		char name[100];
		int val;
		short answer;
	};

	struct Hm3 s[3];
	for (size_t i = 0; i < 3; i++)
	{
		printf("please enter a name and a value:");
		scanf("%s %d", s[i].name, &s[i].val);
		s[i].answer = (strlen(s[i].name)) > 5 && s[i].val > 10 ? 1 : 0;
		//if (strlen(s[i].name) > 5 && s[i].val > 10)
		//{
		//	s[i].answer = 1;
		//}
		//else
		//{
		//	s[i].answer = 0;
		//}
	}
	FILE* f = fopen("hm3.bin", "w");
	if (!f)
	{
		// ERROR
	}
	else
	{
		int write = fwrite(&s, sizeof(struct Hm3), 3, f);
		fclose(f);
	}

	//*/

	/* task 4
	int arr[15] = { 10,20,30,40,50,60,70,80,90,100,1,2,3,4,5 };
	FILE* f = fopen("hm4.bin", "w");
	if (!f)
	{
		//ERROR
	}
	else
	{
		int write = fwrite(arr, sizeof(int), 15, f);
	}
	//*/

	/* task 5
	FILE* f = fopen("Q4.bin", "r");
	if (!f)
	{
		// ERROR
	}
	else
	{
		int num;
		int sum = 0;
		int count = 0;
		while (fread(&num, sizeof(int), 1, f))
		{
			printf("%d\t", num);
			sum = sum + num;
			count++;
		}
		printf("\nAdding all the numbers in the array gives us : %d", sum);
		printf("\namount of numbers in array : %d", count);
		fclose(f);
	}
	//*/

	/* task 6
	struct Hm6
	{
		char name[100];
		int val;
		short answer;
	};
	
	struct Hm6* origin;
	struct Hm6* currentS;
	int userSize;
	printf("plaese enter how many items you need in struct:");
	scanf("%d", &userSize);
	origin = malloc(sizeof(struct Hm6) * userSize);
	currentS = origin;
	for (int i = 0; i < userSize; i++)
	{
		printf("please enter a name and a value:");
		scanf("%s %d", &currentS->name, &currentS->val);
		currentS->answer = (strlen(currentS->name)) > 5 && currentS->val > 10 ? 1 : 0;
		//if (strlen(currentS->name) > 5 && currentS->val > 10)
		//{
		//	currentS->answer = 1;
		//}
		//else
		//{
		//	currentS->answer = 0;
		//}
		currentS++;
	}
	currentS = origin;
	for (int i = 0; i < userSize; i++)
	{
		printf("%s\t%d\t%d\n", currentS->name, currentS->val, currentS->answer);
		currentS++;
	}
	free(origin);
	//*/
	return 0;
}