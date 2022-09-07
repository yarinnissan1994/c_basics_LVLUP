#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

#define FILE_NAME "cw1.bin"
#define Version 1

typedef struct s_item {
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;
} t_item;

typedef struct {
	int version;
	int serialNum;
	int itemsCount;
	char reserve[100];
} t_headerFile;

t_item* head = NULL;
t_item* tail = NULL;
int itemCount = 0;

t_item* findItem(int key)
{
	t_item* currentL = head;
	if (itemCount == 0)
	{
		return currentL;
	}
	while (currentL->key != key)
	{
		currentL = currentL->next;
		if (currentL == NULL)
		{
			printf("key not excist in List\n\n");
			break;
		}
	}
	return currentL;
}

t_item* addItem(int val, int key)
{
	t_item* ret = (t_item*)malloc(sizeof(t_item));
	ret->key = key;
	ret->val = val;
	ret->next = NULL;
	ret->prev = NULL;
	if (head == NULL)
	{
		head = ret;
		tail = ret;
	}
	else
	{
		ret->prev = tail;
		tail->next = ret;
		tail = ret;

	}
	return ret;
}

t_item* updateItem(int val, int key)
{
	t_item* ret = findItem(key);
	if (ret != NULL)
	{
		ret->val = val;
	}
	return ret;
}

t_item* removeItem(int key)
{
	t_item* removeI = findItem(key);
	if (removeI == NULL)
	{
		printf("back to MENU\n\n");
		return NULL;
	}
	else if (itemCount == 1)
	{
		head = NULL;
		tail = NULL;
		itemCount--;
		printf("last item in dictionary removed\n\n");
		return removeI;
	}
	else if (head != NULL)
	{
		if (removeI->prev == NULL)
		{
			head = removeI->next;
			removeI->next->prev = NULL;
		}
		else if (removeI->next == NULL)
		{
			tail = removeI->prev;
			removeI->prev->next = NULL;
		}
		else
		{
			removeI->prev->next = removeI->next;
			removeI->next->prev = removeI->prev;
		}
		itemCount--;
		return removeI;
	}
	else
	{
		return NULL;
	}
}

void printLinkedList()
{
	t_item* currentL = head;
	t_item* printL;
	while (currentL != NULL)
	{
		printL = currentL;
		currentL = currentL->next;
		printf("key - %d | value - %d\n", printL->key, printL->val);
	}
	printf("Items in List: %d\n", itemCount);
}

void freeMalloc()
{
	t_item* addFree = head;
	while (addFree != NULL)
	{
		addFree = addFree->next;
		free(head);
		head = addFree;
	}
	head = NULL;
	tail = NULL;
}

int main()
{
	t_headerFile fileHeader;
	fileHeader.version = 1;
	fileHeader.serialNum = 555;
	fileHeader.itemsCount = 0;

	char userResponse = 'A';
	int key;
	int val;
	t_item* ItemAdd;
	FILE* f;
	while (userResponse != 'E')
	{
		printf("*********MENU*********\ntype item charecter for execution\nA.add item to List\nF.find item in List\nU.update item in List\nD.delete item from List\nS.save List into file\nL.load List from file\nP.print List\nE.done\ntype here:");
		scanf(" %c", &userResponse);
		printf("\n\n");
		switch (userResponse)
		{
		case 'A':
			printf("enter key and value:");
			scanf("%d %d", &key, &val);
			addItem(val, key);
			itemCount++;
			fileHeader.itemsCount++;
			printf("\n\n");
			break;
		case 'F':
			printf("enter key to search in List:");
			scanf("%d", &key);
			ItemAdd = findItem(key);
			if (itemCount == 0)
			{
				printf("List is empty\n\n");
			}
			if (ItemAdd == NULL)
			{
				break;
			}
			printf("key - %d | value - %d", ItemAdd->key, ItemAdd->val);
			printf("\n\n");
			break;
		case 'U':
			printf("enter key and than a value to update key's value in List:");
			scanf("%d %d", &key, &val);
			ItemAdd = updateItem(val, key);
			if (ItemAdd = NULL)
			{
				printf("please check if key excist first");
			}
			break;
		case 'D':
			printf("enter key to remove from List:");
			scanf("%d", &key);
			ItemAdd = removeItem(key);
			if (itemCount == 0)
			{
				printf("dictionary is empty\n\n");
			}
			if (ItemAdd == NULL)
			{
				break;
			}
			printf("key - %d | value - %d | removed", ItemAdd->key, ItemAdd->val);
			free(ItemAdd);
			fileHeader.itemsCount--;
			printf("\n\n");
			break;
		case 'S':
			f = fopen(FILE_NAME, "w");
			if (!f)
			{
				// error
				return 1;
			}

			int write = fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
			t_item* curr = head;
			while (curr->next != NULL)
			{
				write = fwrite(curr, sizeof(t_item), 1, f);
				curr = curr->next;
			}
			fclose(f);
			fileHeader.itemsCount = 0;
			freeMalloc();
			break;
		case 'L':
			f = fopen(FILE_NAME, "r");
			if (!f)
			{
				//error
				return 1;
			}

			t_headerFile headreOfFile;
			int read = fread(&headreOfFile, sizeof(t_headerFile), 1, f);

			for (int i = 0; i < headreOfFile.itemsCount; i++)
			{
				curr = (t_item*)malloc(sizeof(t_item));
				read = fread(curr, sizeof(t_item), 1, f);
				addItem(curr->val, curr->key);
			}
			break;
		case 'P':
			if (itemCount == 0)
			{
				printf("lIST is empty\n\n");
				break;
			}
			printLinkedList();
			printf("\n\n");
			break;
		case 'E':
			printf("done!");
			freeMalloc();
			printf("\n\n");
			break;
		default:
			printf("invalid charecter");
			printf("\n\n");
			break;
		}
	}
	printf("thank you for using my program =]\n\n");
	return 0;
}
