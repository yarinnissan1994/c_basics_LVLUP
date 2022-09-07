#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main432_45()
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

	//* task 6
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
		if (strlen(currentS->name) > 5 && currentS->val > 10)
		{
			currentS->answer = 1;
		}
		else
		{
			currentS->answer = 0;
		}
		currentS++;
	}
	currentS = origin;
	for (int i = 0; i < userSize; i++)
	{
		printf("%s\t%d\t%d\n", currentS->name, currentS->val, currentS->answer);
		currentS++;
	}
	//FILE* f = fopen("hm6.bin", "w");
	//fwrite(origin, sizeof(struct Hm6), userSize, f);
	//fclose(f);
	free(origin);
	//*/
	return 0;
}