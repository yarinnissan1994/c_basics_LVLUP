#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main2_545()
{
	int arr[5] = { 23,44,56,100,1009 };
	int arr1[5];
	FILE* f = fopen("array.dat", "w");
	if (f == NULL)
	{
		// ERROR
	}
	else
	{
		// arr = &arr[0]
		int written = fwrite(arr, sizeof(int), 5, f);
		fclose(f);
	}

	f = fopen("array.dat", "r");
	if (f == NULL)
	{
		// ERROR
	}
	else
	{
		int read = fread(arr1, sizeof(int), 5, f);
		fclose(f);
		for (int i = 0; i < 5; i++)
		{
			printf("%d\t", arr1[i]);
		}
	}

	printf("\n\n");

	f = fopen("array.dat", "r");
	if (!f)
	{
		// ERROR
	}
	else
	{
		int read;
		int item;
		while (fread(&item, sizeof(int), 1, f))
		{
			printf("%d\t", item);
		}
		fclose(f);
	}
}