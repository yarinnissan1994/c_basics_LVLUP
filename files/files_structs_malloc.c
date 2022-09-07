#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main23_443()
{
	//struct

	struct Student
	{
		int age;
		char name[100];
		int classlevel;
	};

	struct Student s = { 20,"Amos",1 };
	FILE* f = fopen("oneStudent.dat", "w");
	if (!f)
	{
		//ERROR
	}
	else
	{
		fwrite(&s, sizeof(struct Student), 1, f);
		fclose(f);
	}

	//prepare memory
	struct Student* list;
	struct Student* currentStudent;
	int userSize = 4;
	list = malloc(sizeof(struct Student) * userSize);
	currentStudent = list;

	strcpy(currentStudent->name, "Matan");
	currentStudent->age = 30;
	currentStudent->classlevel = 2;
	
	currentStudent++;

	strcpy(currentStudent->name, "Amos");
	currentStudent->age = 22;
	currentStudent->classlevel = 3;

	currentStudent++;

	strcpy(currentStudent->name, "Amran");
	currentStudent->age = 24;
	currentStudent->classlevel = 5;

	currentStudent++;

	strcpy(currentStudent->name, "Yaacov");
	currentStudent->age = 120;
	currentStudent->classlevel = 123;

	//save memmory

	f = fopen("Students.dat", "w");
	if (!f)
	{
		//ERROR
	}
	else 
	{
	fwrite(list, sizeof(struct Student), userSize, f);
	fclose(f);
	}

	// free
	free(list);

	//f = fopen("Students.dat", "r");
	//if (!f)
	//{
	//	//ERROR
	//}
	//else
	//{
	//	fread(list, sizeof(struct Student), userSize, f);
	//	for (int i = 0; i < userSize; i++)
	//	{
	//	printf("%s\t%d\t%d", s.name, s.age, s.classlevel);
	//	}
	//	fclose(f);
	//}
	return 0;
}