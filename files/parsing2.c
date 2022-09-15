#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct OskarActor {
	int index;
	int year;
	int age;
	int popolarity;
	char name[1000];
	char movie[1000];
	struct OskarActor* next;
	struct OskarActor* prev;
}t_OskarActor;

typedef struct OskarActor_Header {
	int Version;
	int ItemCount;
	char reserve[1000];
}t_OskarActor_Header;

t_OskarActor* head = NULL;
t_OskarActor* tail = NULL;

int itemCount = 0;

void addOskar(int index, int year, int age, char name[1000], char movie[1000])
{
	t_OskarActor* currentI;
	currentI = (t_OskarActor*)malloc(sizeof(t_OskarActor));
	currentI->index = index;
	currentI->year = year;
	currentI->age = age;
	currentI->popolarity = 0;
	strcpy(currentI->name, name);
	strcpy(currentI->movie, movie);
	currentI->next = NULL;
	if (head == NULL)
	{
		head = currentI;
		tail = currentI;
		currentI->prev = NULL;
	}
	else
	{
		currentI->prev = tail;
		tail->next = currentI;
		tail = currentI;
	}
	itemCount++;
}

void loafFile() 
{
	itemCount = 0;
	FILE* f = fopen("oscar2.txt", "r");
	if (!f)
	{
		//error
	}
	else
	{
		char str[10000];
		fgets(str, 10000, f);
		while (fgets(str, 10000, f) != NULL)
		{
			char index[1000];
			char year[1000];
			char age[1000];
			char name[1000];
			char movie[1000];
			char* token;

			token = strtok(str, ",");
			strcpy(index, token);
			token = strtok(NULL, ",");
			strcpy(year, token);
			token = strtok(NULL, ",");
			strcpy(age, token);
			token = strtok(NULL, ",");
			strcpy(name, token);
			token = strtok(NULL, ",");
			strcpy(movie, token);

			addOskar(atoi(index), atoi(year), atoi(age), name, movie);
		}
	}
}

void printLinkedList()
{
	t_OskarActor* currentL = head;
	t_OskarActor* printL;
	while (currentL != NULL)
	{
		printL = currentL;
		currentL = currentL->next;
		printf("#%d\npopolarity : %d\nyear : %d\nage : %d\nname : %s\nmovie :%s\n\n", printL->index, printL->popolarity, printL->year, printL->age, printL->name, printL->movie);
	}
	printf("Items in queue: %d\n", itemCount);
	printf("\n\n");
}

void ItemCount()
{
	printf("Items in queue: %d\n", itemCount);
}

void freeLinkedList()
{
	itemCount = 0;
	t_OskarActor* currentL = head;
	t_OskarActor* releaseL;
	while (currentL != NULL)
	{
		releaseL = currentL;
		currentL = currentL->next;
		free(releaseL);
	}
}

void SearchWinnersByYear(int year)
{
	t_OskarActor* currentL = head;
	int count = 0;
	if (itemCount == 0)
	{
		printf("cant find list");
		return currentL;
	}
	printf("%d winners are:\n", year);
	while (currentL != NULL)
	{
		currentL = currentL->next;
		if (currentL && currentL->year == year)
		{
			count++;
			printf("#%d - %s\n", count, currentL->name);
		}
	}
	if (!count)
	{
		printf("no oskar winners in %d\n", year);
	}
	printf("\n\n");
}

void SearchByIndex(int index)
{
	t_OskarActor* currentL = head;
	while (currentL && currentL->index != index)
	{
		currentL = currentL->next;
	}
	if (currentL != NULL)
	{
		printf("#%d\nyear : %d\nage : %d\nname : %s\nmovie : %s\n\n", currentL->index, currentL->year, currentL->age, currentL->name, currentL->movie);
	}
}

void Swap(t_OskarActor* Adress)
{
	if (Adress == NULL || Adress->next == NULL)
	{
		return;
	}
	t_OskarActor* temp = (t_OskarActor*)malloc(sizeof(t_OskarActor));
	temp->next = Adress->next->next;
	temp->prev = Adress->next;
	Adress->next->next = Adress;
	Adress->next->prev = Adress->prev;
	Adress->next = temp->next;
	Adress->prev = temp->prev;
	free(temp);
	if (Adress->prev->prev == NULL)
	{
		head = Adress->prev;
	}
	else
	{
		Adress->prev->prev->next = Adress->prev;
	}
	if (Adress->next == NULL)
	{
		tail = Adress;
	}
	else
	{
		Adress->next->prev = Adress;
	}
}

void ShakerBubbleSortAge()
{
	t_OskarActor* currentL = NULL;
	t_OskarActor* currentLSwap = NULL;
	t_OskarActor* headStoper = NULL;
	t_OskarActor* tailStoper = NULL;
	int swaps = 1;
	if (head == NULL)
	{
		return;
	}
	currentL = head;
	currentLSwap = head->next;
	do
	{
		swaps = 0;
		while (currentLSwap && currentL->next != tailStoper)
		{
			if (currentL->age > currentLSwap->age)
			{
				Swap(currentL);
				swaps = 1;
				currentLSwap = currentL->next;
			}
			else
			{
				currentL = currentL->next;
				currentLSwap = currentLSwap->next;
			}
		}
		tailStoper = currentL;
		currentL = currentL->prev;
		currentLSwap = currentL->prev;
		while (currentLSwap != NULL && currentL->prev != headStoper)
		{
			if (currentL->age < currentLSwap->age)
			{
				Swap(currentLSwap);
				swaps = 1;
				currentLSwap = currentL->prev;
			}
			else
			{
				currentL = currentL->prev;
				currentLSwap = currentLSwap->prev;
			}
		}
		headStoper = currentL;
		currentL = currentL->next;
		currentLSwap = currentL->next;
	} while (swaps);
	printf("list is now sorted\n\n");
}\

void ShakerBubbleSortPopolarity()
{
	t_OskarActor* currentL = NULL;
	t_OskarActor* currentLSwap = NULL;
	t_OskarActor* headStoper = NULL;
	t_OskarActor* tailStoper = NULL;
	int swaps = 1;
	if (head == NULL)
	{
		return;
	}
	currentL = head;
	currentLSwap = head->next;
	do
	{
		swaps = 0;
		while (currentLSwap && currentL->next != tailStoper)
		{
			if (currentL->popolarity > currentLSwap->popolarity)
			{
				Swap(currentL);
				swaps = 1;
				currentLSwap = currentL->next;
			}
			else
			{
				currentL = currentL->next;
				currentLSwap = currentLSwap->next;
			}
		}
		tailStoper = currentL;
		currentL = currentL->prev;
		currentLSwap = currentL->prev;
		while (currentLSwap != NULL && currentL->prev != headStoper)
		{
			if (currentL->popolarity < currentLSwap->popolarity)
			{
				Swap(currentLSwap);
				swaps = 1;
				currentLSwap = currentL->prev;
			}
			else
			{
				currentL = currentL->prev;
				currentLSwap = currentLSwap->prev;
			}
		}
		headStoper = currentL;
		currentL = currentL->next;
		currentLSwap = currentL->next;
	} while (swaps);
	printf("list is now sorted\n\n");
}

void UpdatePopolarity(int index)
{
	t_OskarActor* currentL = head;
	while (currentL != NULL)
	{
		if (currentL->index == index)
		{
			currentL->popolarity++;
			break;
		}
		currentL = currentL->next;
	}
}

void run()
{
	srand(time(0));
	for (int i = 0; i < 10000; i++)
	{
		UpdatePopolarity(rand()%1000);
	}
}

void saveFile(char fileName[100])
{
	t_OskarActor_Header* OskarHeader = (t_OskarActor_Header*)malloc(sizeof(t_OskarActor_Header));
	t_OskarActor* curr = head;
	OskarHeader->Version = 1;
	OskarHeader->ItemCount = itemCount;

	FILE* f = fopen(fileName, "w");
	if (!f)
	{
		//error
	}
	else
	{
		int write;
		write = fwrite(OskarHeader, sizeof(t_OskarActor_Header), 1, f);
		if (!write)
		{
			//error
		}
		for (int i = 0; i < itemCount; i++)
		{
			write = fwrite(curr, sizeof(t_OskarActor), 1, f);
			if (!write)
			{
				//error
			}
			curr = curr->next;
		}
		fclose(f);
		free(OskarHeader);
	}
}

void fileLoad(char fileName[100])
{
	freeLinkedList();
	head = NULL;
	tail = NULL;
	t_OskarActor_Header* OskarHeader = (t_OskarActor_Header*)malloc(sizeof(t_OskarActor_Header));
	t_OskarActor* curr = (t_OskarActor*)malloc(sizeof(t_OskarActor));
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		//error
	}
	else
	{
		int read;
		read = fread(OskarHeader, sizeof(t_OskarActor_Header), 1, f);
		if (!read)
		{
			//error
		}
		for (int i = 0; i < OskarHeader->ItemCount; i++)
		{
			read = fread(curr, sizeof(t_OskarActor), 1, f);
			if (!read)
			{
				//error
			}
			addOskar(curr->index, curr->year, curr->age, curr->name, curr->movie);
		}
		fclose(f);
		free(curr);
		free(OskarHeader);
	}
}

int main()
{
	//char str[100] = "123, 42545,23,44,123,3,3,4";
	//char* token = strtok(str, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");
	//token = strtok(NULL, ",");

	//char str[100] = "aaa*bbb*ccc";
	//char* token = strtok(str, "*");
	//while (token)
	//{
	//	printf("%s\n", token);
	//	token = strtok(NULL, "*");
	//}

	////cw1
	//char str[100] = "123,456,789,1,2,3,4,5,6,7,2000";
	//int number;
	//char* token = strtok(str, ",");
	//int sum = 0;
	//while (token)
	//{
	//	number = atoi(token);
	//	sum = sum + number;
	//	printf("+%s\n", token);
	//	printf("%d\n", sum);
	//	token = strtok(NULL, ",");
	//}

	////cw2
	//char str[100];
	//printf("plaese write you full name:");
	//gets(str);
	//char* token = strtok(str, " ");
	//while (token)
	//{
	//	printf("%s\n", token);
	//	token = strtok(NULL, " ");
	//}

	////cw3
	//char str[100];
	//int count = 0;
	//printf("plaese write you full name (last name first):");
	//gets(str);
	//char* token = strtok(str, " ");
	//while (token)
	//{
	//	(!count) ? printf("%s\n", token) : printf("%s ", token);
	//	token = strtok(NULL, " ");
	//	count++;
	//}

	////cw4
	//typedef struct OskarActor {
	//	int index;
	//	int year;
	//	int age;
	//	char name;
	//	char movie;
	//	struct OskarActor* next;
	//	struct OskarActor* prev;
	//}OskarActor;

	//FILE* f = fopen("oscar_age_female.txt", "r");
	//if (!f)
	//{
	//	//error
	//}
	//else
	//{
	//	char str[10000];
	//	fgets(str, 10000, f);
	//	while (fgets(str, 10000, f) != NULL)
	//	{
	//		char index[1000];
	//		char year[1000];
	//		char age[1000];
	//		char name[1000];
	//		char movie[1000];
	//		char* token;

	//			token = strtok(str, ",");
	//			strcpy(index, token);
	//			token = strtok(NULL, ",");
	//			strcpy(year, token);
	//			token = strtok(NULL, ",");
	//			strcpy(age, token);
	//			token = strtok(NULL, ",");
	//			strcpy(name, token);
	//			token = strtok(NULL, ",");
	//			strcpy(movie, token);

	//			printf("The Oskar Goes To %s - At %s - Movie : %s\n", name, year, movie);
	//	}
	//}

	//cw5

	loafFile();
	//printLinkedList();
	//SearchWinnersByYear(2000);
	//SearchWinnersByYear(2016);
	//SearchByIndex(50);
	//SearchByIndex(90);
	//ShakerBubbleSortAge();
	//run();
	//ShakerBubbleSortPopolarity();
	//printLinkedList();
	//ItemCount();
	saveFile("test.bin");
	fileLoad("test.bin");
	printLinkedList();
	freeLinkedList();


	return 0;
}