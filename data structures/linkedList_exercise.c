#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

struct Item
{
	int val;
	struct Item* next;
};
struct Item* head = NULL;

void printLinkedList()
{
	struct Item* currentI = head;
	struct Item* printI;
	while (currentI != NULL)
	{
		printI = currentI;
		currentI = currentI->next;
		printf("%d\n", printI->val);
	}
}
void freeLinkedList()
{
	struct Item* currentI = head;
	struct Item* releaseI;
	while (currentI != NULL)
	{
		releaseI = currentI;
		currentI = currentI->next;
		free(releaseI);
	}
}
void find44()
{
	struct Item* currentI = head;
	struct Item* find44;
	int ind;
	int count = 0;
	printf("check how many 44 values are inside structs? 1 = yes | 0 = no:");
	scanf("%d", &ind);
	if (ind == 1)
	{
		while (currentI != NULL)
		{
			find44 = currentI;
			currentI = currentI->next;
			if (find44->val == 44)
			{
				count++;
			}
		}
		printf("44 was repeated %d times in structs.\n\n", count);
	}
	else
	{
		printf("skipped\n\n");
	}
}
void id()
{
	struct Item* currentI = head;
	struct Item* findnNum;
	int id;
	int count = 1;
	printf("pleas enter a value you wanna search in structs:");
	scanf("%d", &id);
	while (currentI != NULL)
	{
		findnNum = currentI;
		currentI = currentI->next;
		if (findnNum->val != id)
		{
			count++;
		}
		else
		{
			printf("the number %d located in struct num %d.\n\n", id, count);
			count++;
		}
	}
}
void SaveToFile(int size)
{
	struct Value
	{
		int Val;
		struct Value* next;
	};
	struct Item* currentI = head;
	struct Item* prevI;
	struct Value* origin;
	struct Value* currentV;
	origin = malloc(sizeof(struct Value) * size);
	currentV = origin;
	for (int i = 0; i < size; i++)
	{

		prevI = currentI;
		currentI = currentI->next;
		currentV->Val = prevI->val;
		currentV->next = prevI->next;
		currentV++;
	}
	currentV = origin;
	FILE* f = fopen("hm7.bin", "w");
	if (!f)
	{
		// ERROR
	}
	else
	{
		int write = fwrite(currentV, sizeof(struct Value), size, f);
		fclose(f);
	}
	free(origin);
}
int structCount()
{
	struct Item* currentI = head;
	struct Item* prevI;
	int count = 0;
	while (currentI != NULL)
	{
		prevI = currentI;
		currentI = currentI->next;
		count++;
	}
	return count;
}
void NewBeginnings()
{
	struct Copy
	{
		int val;
		struct Copy* next;
	};
	struct Copy* head = NULL;
	struct Copy* currentI;
	struct Copy* prevI = NULL;
	int ind = 1;
	FILE* f = fopen("hm7.bin", "r");
	while (ind)
	{
		currentI = malloc(sizeof(struct Copy));
		if (head == NULL)
		{
			head = currentI;
		}
		else
		{
			prevI->next = currentI;
		}
		int read = fread(currentI, sizeof(struct Copy), 1, f);
		currentI->next = NULL;
		prevI = currentI;
		if (read == 0)
		{
			ind = 0;
			break;
		}
	}
	fclose(f);
}

int main()
{
	struct Item* currentI;
	struct Item* prevI = NULL;
	int userResponse;
	int getIn = 1;
	printf("Type 1 for Adding value\nType 2 for Print all List\nType 3 for Exit\n");
	scanf("%d", &userResponse);
	while (getIn != 100)
	{
		if (userResponse == 1)
			{
			currentI = malloc(sizeof(struct Item));
			if (head == NULL)
			{
				head = currentI;
			}
			else
			{
				prevI->next = currentI;
			}
			printf("plaese enter a valeu:");
			scanf("%d", &currentI->val);
			getIn = currentI->val;
			currentI->next = NULL;
			prevI = currentI;
			if (getIn != 100)
			{
			printf("\nType 1 for Adding value\nType 2 for Print all List\nType 3 for Exit\n");
			scanf("%d", &userResponse);
			}
		}
		else if (userResponse == 2)
		{
			printLinkedList();
			printf("\nType 1 for Adding value\nType 2 for Print all List\nType 3 for Exit\n");
			scanf("%d", &userResponse);
		}
		else if (userResponse == 3)
		{
			break;
		}
		else
		{
			printf("invalid number. please try agian:");
			scanf("%d", &userResponse);
		}
	}
	find44();
	id();
	printf("save to file? 1 = yes | 0 = no:");
	scanf("%d", &userResponse);
	if (userResponse == 1)
	{
		SaveToFile(structCount());
		printf("saved\n\n");
	}
	else
	{
		printf("skipped saving\n\n");
	}
	freeLinkedList();
	NewBeginnings();
	freeLinkedList();
	return 0;
}