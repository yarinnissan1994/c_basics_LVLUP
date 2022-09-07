#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

void funcHM3(int x)
{
		for (int i = 1; i <= x; i++)
		{
			char fileName[20] = "File";
			char fileNum[20];
			sprintf(fileNum, "%s%d%s", fileName, i, ".txt");
			char* relativFileNums = fileNum;
			FILE* f = fopen(relativFileNums, "w");

			if (f != NULL)
			{
				for (int i = 0; i < x; i++)
				{
						fputc('*', f);
				}
			}

			else
			{
				// error
				fopen(relativFileNums, "r");
			}
		}
}

int main()
{
	/*hm1
	char* relativAstFile = "Ast.txt";
	FILE* f = fopen(relativAstFile, "w");
	int count = 1;

	if (f != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < count; j++)
			{
				fputc('*', f);
			}
			fputc('\n', f);
			count++;
		}
	}

	else
	{
		// error
		fopen(relativAstFile, "r");
	}

	fclose(f);
	//*/

	/*hm2
	char* relativNumsFile = "nums.txt";
	FILE* f = fopen(relativNumsFile, "w");
	char count = 49;

	if (f != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				fputc(count, f);
			}
			fputc('\n', f);
			count++;
		}
	}

	else
	{
		// error
		fopen(relativNumsFile, "r");
	}

	fclose(f);
	//*/

	/*hm3
	funcHM3(7);
	//*/

	/*hm4
	struct Car
	{
		char company[100];
		char model[10];
		int year;
		int carNum;
	};

	struct Car car1;
	strcpy(car1.company, "skoda");
	strcpy(car1.model, "fabia");
	car1.year = 2008;
	car1.carNum = 3083164;

	printf("%s\n%s\n%d\n%d", car1.company, car1.model, car1.year, car1.carNum);
	//*/

	/*hm5
	struct Car
	{
		char company[100];
		char model[10];
		int year;
		int carNum;
	};

	struct Car carList[2];
	for (int i = 0; i < 2; i++)
	{
		printf("company-model-year-number\n");
		scanf("%s %s %d %d", carList[i].company, carList[i].model, &carList[i].year, &carList[i].carNum);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("company-model-year-number\n");
		printf("%d. %s %s %d %d\n", (i+1), carList[i].company, carList[i].model, carList[i].year, carList[i].carNum);
	}
	//*/

	/*hm6
	struct Ex6
	{
		char name[100];
		char symbol[2];
		char code[3];
	};

	struct Ex6 item1;
	{
		strcpy(item1.name, "yarin");
		strcpy(item1.symbol, "$");
		strcpy(item1.code, "11");
	}
	char* relativStructFile = "Struct.txt";
	FILE* f = fopen(relativStructFile, "w");

	if (f != NULL)
	{
		int num1 = strlen(item1.name);
		for (int i = 0; i < num1; i++)
		{
			fputc(item1.name[i], f);
		}
			fputc('\n', f);
		int num2 = strlen(item1.symbol);
		for (int i = 0; i < num2; i++)
		{
			fputc(item1.symbol[i], f);
		}
			fputc('\n', f);
		int num3 = strlen(item1.code);
		for (int i = 0; i < num3; i++)
		{
			fputc(item1.code[i], f);
		}
			fputc('\n', f);
	}

	else
	{
		// error
		fopen(relativStructFile, "r");
	}

	fclose(f);
	//*/

	//*hm7
	struct Ex7
	{
		char name[11];
		char symbol[3];
		char code[4];
	};

	struct Ex7 itemList[2];
	for (int i = 0; i < 2; i++)
	{
		printf("10 charaters name-up to 2 symbols-3 digit code:\n");
		scanf("%s %s %s", itemList[i].name, itemList[i].symbol, itemList[i].code);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("user details:\n");
		printf("%s\n%s\n%s\n", itemList[i].name, itemList[i].symbol, itemList[i].code);
	}

	char* relativDetailsFile = "Details.txt";
	FILE* f = fopen(relativDetailsFile, "w");

	if (f != NULL)
	{
		for (int h = 0; h < 2; h++)
		{
			int num1 = strlen(itemList[h].name);
			for (int i = 0; i < num1; i++)
			{
				fputc(itemList[h].name[i], f);
			}
			fputc('\n', f);
			int num2 = strlen(itemList[h].symbol);
			for (int i = 0; i < num2; i++)
			{
				fputc(itemList[h].symbol[i], f);
			}
			fputc('\n', f);
			int num3 = strlen(itemList[h].code);
			for (int i = 0; i < num3; i++)
			{
				fputc(itemList[h].code[i], f);
			}
			fputc('\n', f);
		}
	}
	else
	{
		// error
		fopen(relativDetailsFile, "r");
	}
	fclose(f);

	//*/

	//*hm8
	struct Ex8
	{
		char name[11];
		char symbol[3];
		char code[4];
	};

	struct Ex8 itemList1[2];

	FILE* f1;

	f1 = fopen("Details.txt", "r");
	if (f1 == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch = 0;
		int countLine = 0;
		int countStr = 0;
		char txtHold[15];
		char* txtPointer = txtHold;
		while (ch != EOF)
		{
			ch = fgetc(f1);
			if (ch != '\n')
			{
				*txtPointer = ch;
				txtPointer++;
				*txtPointer = NULL;
			}
			else
			{
				txtPointer = txtHold;
				if (countLine == 0)
				{
					strcpy(itemList1[countStr].name, txtHold);
					countLine++;
				}
				else if (countLine == 1)
				{
					strcpy(itemList1[countStr].symbol, txtHold);
					countLine++;
				}
				else
				{
					strcpy(itemList1[countStr].code, txtHold);
					countStr++;
					countLine = 0;
				}
			}
		}
	}
	fclose(f1);
	//*/
	return 0;
}
	//char str1[100];
	//char str2[200] = "Abanibioboebe";

	//sprintf(str1, "TheFormat%d%s%d%s", 234, str2, 2 + 2, "maoz");

	//printf("%s", str1);
