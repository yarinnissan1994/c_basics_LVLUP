#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

//#define TARGIL

//#ifdef TARGIL

//#endif

int main1_234()
{
	/* task1
	short num;
	printf("please enter a number (short):");
	scanf("%hu", &num);
	FILE* f1;
	f1 = fopen("task1.bin", "w");
	if (f1 == NULL)
	{
		// ERROR
	}
	else
	{
		fwrite(&num, sizeof(short), 1, f1);
		fclose(f1);
	}
	//*/

	/* task2
	short filenum;
	FILE* f2 = fopen("task1.bin", "r");
	if (f2 == NULL)
	{
		// ERROR
	}
	else
	{
		int read = fread(&filenum, sizeof(int), 1, f2);
		printf("%hu*%hu=%hu\t", filenum, filenum, (filenum * filenum));
	}
	//*/

	/* task3
	FILE* f3;
	f3 = fopen("task3.bin", "w");
	int num;
	if (f3 == NULL)
	{
		// ERROR
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			printf("please enter a number:");
			scanf("%d", &num);
			int write = fwrite(&num, sizeof(int), 1, f3);
		}
	}
		fclose(f3);
	//*/

	/* task4
	int num;
	int sum = 0;
	FILE* f4 = fopen("binary2.bin", "r");
	if (f4 == NULL)
	{
		// ERROR
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
		int read = fread(&num, sizeof(int), 1, f4);
		printf("%d\t", num);
		sum = sum + num;
		}
		printf("\n%d", sum);
	}
	fclose(f4);
	//*/

	//* task5
	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Item item1;
	printf("please enter a barcode:");
	scanf("%d", &item1.barcode);
	printf("please enter a price:");
	scanf("%d", &item1.price);
	printf("please enter a name:");
	scanf("%s", &item1.name);
	printf("please enter a color:");
	scanf("%s", &item1.color);

	FILE* f5;
	f5 = fopen("task5.bin", "w");
	if (f5 == NULL)
	{
		// ERROR
	}
	else
	{
		int write = fwrite(&item1, sizeof(struct Item), 1, f5);
	}
	fclose(f5);

	f5 = fopen("task5.bin", "r");
	if (f5 == NULL)
	{
		// ERROR
	}
	else
	{
		int read = fread(&item1, sizeof(struct Item), 1, f5);
		printf("%d\t%d\t%s\t%s", item1.barcode, item1.price, item1.name, item1.color);
	}
	fclose(f5);

	//*/
	return 0;
}