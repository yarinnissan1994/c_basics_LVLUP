#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

//void charCount(FILE* f)
//{
//	if (f == NULL)
//	{
//		//problem
//		//eror massege
//	}
//	else
//	{
//		char ch = fgetc(f);
//		int count = 0;
//		while (ch != EOF)
//		{
//			ch = fgetc(f);
//			count++;
//		}
//		printf("\nnumber of characters in this file : %d\n", count);
//	}
//}
//void astCount(FILE* f)
//{
//	if (f == NULL)
//	{
//		//problem
//		//eror massege
//	}
//	else
//	{
//		char ch = fgetc(f);
//		int count = 0;
//		if (ch == '*')
//		{
//			count++;
//		}
//		while (ch != EOF)
//		{
//			ch = fgetc(f);
//			if (ch == '*')
//			{
//				count++;
//			}
//		}
//		printf("\nnumber of astrix in this file : %d\n", count);
//	}
//}
//void lineCount(FILE* f)
//{
//	if (f == NULL)
//	{
//		//problem
//		//eror massege
//	}
//	else
//	{
//		char ch = fgetc(f);
//		int count = 1;
//		while (ch != EOF)
//		{
//			ch = fgetc(f);
//			if (ch == '\n')
//			{
//				count++;
//			}
//		}
//		printf("\nnumber of lines in this file : %d\n", count);
//	}
//}
//int* intMalloc(int num)
//{
//	int* ptr;
//	ptr = malloc(sizeof(int) * num);
//	return ptr;
//}
//char* charMalloc(char num)
//{
//	char* ptr;
//	ptr = malloc(sizeof(char) * num);
//	return ptr;
//}
//void intUserInput(int* adress, char num)
//{
//	int* ptr = adress;
//	int* original = adress;;
//	for (int i = 0; i < num; i++)
//	{
//		printf("please enter a number:\n");
//		scanf("%d", ptr);
//		ptr++;
//	}
//	ptr = original;
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d\t", *ptr);
//		ptr++;
//	}
//}
//void charUserInput(char* adress, char num)
//{
//	int* ptr = adress;
//	int* original = adress;;
//	for (int i = 0; i < num; i++)
//	{
//		printf("please enter a number:\n");
//		scanf("%d", ptr);
//		ptr++;
//	}
//	ptr = original;
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d\t", *ptr);
//		ptr++;
//	}
//}
//


int main2_1()
{
	/* exemple
	FILE* f;

	f = fopen("C:\\Users\\User\\Desktop\\C yarin\\data.txt", "r");
	if (f == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch = fgetc(f);
		printf("%c", ch);
		while (ch != EOF) 
		{
		ch = fgetc(f);
		printf("%c", ch);
		}

		fclose(f);
	}
	*/

	/*FILE* f;

	f = fopen("C:\\Users\\User\\Desktop\\C yarin\\File1.txt", "r");
	if (f == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch = fgetc(f);
		printf("%c", ch);
		while (ch != EOF)
		{
			ch = fgetc(f);
			printf("%c", ch);
		}
		printf("\n");
	}
	fclose(f);

	f = fopen("C:\\Users\\User\\Desktop\\C yarin\\File1.txt", "r");
	charCount(f);
	fclose(f);

	f = fopen("C:\\Users\\User\\Desktop\\C yarin\\File1.txt", "r");
	astCount(f);
	fclose(f);*/


	/*FILE* f2;

	f2 = fopen("C:\\Users\\User\\Desktop\\C yarin\\File2.txt", "r");
	if (f2 == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch2 = fgetc(f2);
		printf("\n%c", ch2);
		while (ch2 != EOF)
		{
			ch2 = fgetc(f2);
			printf("%c", ch2);
		}
		printf("\n");
	}
	fclose(f2);

	f2 = fopen("C:\\Users\\User\\Desktop\\C yarin\\File2.txt", "r");
	lineCount(f2);
	fclose(f2);*/

	//*
	FILE* f3;

	f3 = fopen("C:\\Users\\User\\Desktop\\C yarin\\File3.txt", "r");
	if (f3 == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch3 = 0;
		int holder;
		int count = 0;
		while (ch3 != EOF)
		{
			ch3 = fgetc(f3);
			if (ch3 != 'c' && ch3 != 'i')
			{
				holder = ch3 - '0';
				count++;
			}
			else
			{
				if (ch3 == 'c')
				{
					char* Cadress = charMalloc(holder);
					printf("malloc num %d, in char var :\n", count);
					printf("%x\n", Cadress);
					printf("allocated %d bytes\n\n", (holder * sizeof(char)));
					charUserInput(Cadress, holder);
					printf("\n\n");
					//free(Cadress);
				}
				else
				{
					int* Iadress = intMalloc(holder);
					printf("malloc num %d, in int var :\n", count);
					printf("%x\n\n", Iadress);
					printf("allocated %d bytes\n\n", (holder * sizeof(int)));
					intUserInput(Iadress, holder);
					printf("\n\n");
					free(Iadress);
				}
			}
		}
	}
	fclose(f3);
	//*/
	return 0;
}