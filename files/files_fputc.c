#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)
int main1()
{
	//char* fileName = "C:\\Users\\User\\Desktop\\C yarin\\new.txt";
	//char* relativFileName = "new.txt";


	//char* str;
	//str = malloc(100);
	//strcpy(str, "C:\\Users\\User\\Desktop\\C yarin\\new.txt");

	//// r - open for reading
	//// w - open for writing (overwrite already existed data)
	//// a - open for append to end of file

	//FILE* f = fopen(relativFileName, "w");
	//
	//if (f != NULL)
	//{
	//fputc('a', f);
	//fputc('b', f);
	//fputc('b', f);
	//fputc('1', f);
	//fputc('2', f);
	//fputc('3', f);
	//fputc('\n', f);
	//fputc('3', f);
	//fputc('2', f);
	//fputc('1', f);
	//fputc('c', f);
	//fputc('b', f);
	//fputc('a', f);
	//}

	//else
	//{
	//	// error
	//	fopen(relativFileName, "r");
	//}

	//fclose(f);

	/*cw1
	char* relativAstFile = "Astrix.txt";
	FILE* fA = fopen(relativAstFile, "w");

	if (fA != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fputc('*', fA);
			}
			fputc('\n', fA);
		}
	}

	else
	{
		// error
		fopen(relativAstFile, "r");
	}

	fclose(fA);
	*/


	/*cw2
	char* relativAFile = "Afile.txt";
	FILE* fa = fopen(relativAFile, "w");

	if (fa != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fputc('A', fa);
			}
			fputc('\n', fa);
		}
	}

	else
	{
		// error
		fopen(relativAFile, "r");
	}

	fclose(fa);
	*/

	/*cw3
	int num;
	printf("please enter a number of rows you want:");
	scanf("%d", &num);
	char* relativUserFile = "Userfile.txt";
	FILE* fu = fopen(relativUserFile, "w");

	if (fu != NULL)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				fputc('*', fu);
			}
			fputc('\n', fu);
		}
	}

	else
	{
		// error
		fopen(relativUserFile, "r");
	}

	fclose(fu);
	*/

	//*cw4
	char str[100];
	int rows;
	printf("please enter a few words:");
	gets(str);
	printf("please enter number of rows:");
	scanf("%d", &rows);
	int len = strlen(str);
	char* relativWordsFile = "Wordsfile.txt";
	FILE* fw = fopen(relativWordsFile, "w");

	if (fw != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < len; j++)
			{
				fputc(str[j], fw);
			}
			fputc('\n', fw);
		}
	}

	else
	{
		// error
		fopen(relativWordsFile, "r");
	}

	fclose(fw);
	//*/

	//*cw5
	
	return 0;
}