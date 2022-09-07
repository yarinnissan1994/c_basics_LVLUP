#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main1_23()
{
	FILE* f;

	int a = 190;
	int b = 290;
	int c = 390;
	f = fopen("data.bin", "w");
	if (f == NULL)
	{
		// ERROR
	}
	else
	{
		// (&a = value adress (source), sizeof = size you need, 1 = how many, f = where to write)
		fwrite(&a, sizeof(int), 1, f);
		fwrite(&b, sizeof(int), 1, f);
		fwrite(&c, sizeof(int), 1, f);
		fclose(f);
	}

	FILE* f1 = fopen("data.bin", "r");
	if (f1 == NULL)
	{
		// ERROR
	}
	else
	{
		// (&a = value adress, sizeof = size you need, 1 = how many, f = where to read)
		int read = fread(&c, sizeof(int), 1, f1);
		printf("%d\t", c);
		read = fread(&c, sizeof(int), 1, f1);
		printf("%d\t", c);
		read = fread(&c, sizeof(int), 1, f1);
		printf("%d\t", c);
		fclose(f1);
	}

	printf("\n\n");

	FILE* f2;
	struct  student
	{
		char name[100];
		int age;
	};

	f2 = fopen("struct.bin", "w");

	struct student stu;
	strcpy(stu.name, "shlomi");
	stu.age = 18;

	if (f2 == NULL)
	{
		// ERROR
	}
	else
	{
		fwrite(&stu, sizeof(struct student), 1, f2);
		fclose(f2);
	}


	f2 = fopen("struct.bin", "r");

	struct student newstu;
	strcpy(stu.name, "shlomi");
	stu.age = 18;

	if (f2 == NULL)
	{
		// ERROR
	}
	else
	{
		int read = fread(&newstu, sizeof(struct student), 1, f2);
		printf("%s\t%d", newstu.name, newstu.age);
		fclose(f2);
	}

	return 0;
}