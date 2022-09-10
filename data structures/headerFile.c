#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)
#include "useFunc.h"

#define FILE_NAME "data100.bin"
#define Version 2

t_item* head;
t_item* tail;


t_item* newItem(int val, int key)
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

t_item2* newItem2(int val, int key, int id)
{
	t_item2* ret = (t_item2*)malloc(sizeof(t_item2));
	ret->key = key;
	ret->val = val;
	ret->id = id;
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
	//init
	head = NULL;
	tail = NULL;
	t_item* curr;
	FILE* f;

	// operate 10 item
	t_headerFile fileHeader;
	fileHeader.version = 1;
	fileHeader.serialNum = 12345;
	fileHeader.itemsCount = 0;

	for (int i = 0; i < 10; i++)
	{
		newItem(i * 100, i);
		fileHeader.itemsCount++;
	}


	//// save in file
	//f = fopen(FILE_NAME, "w");
	//if (!f)
	//{
	//	// error
	//	return 1;
	//}

	//int write = fwrite(&fileHeader, sizeof(t_headerFile), 1, f);
	//curr = head;
	//while (curr->next != NULL)
	//{
	//	write = fwrite(curr, sizeof(t_item), 1, f);
	//	curr = curr->next;
	//}
	//fclose(f);

	freeMalloc();

	// read from file
	f = fopen(FILE_NAME, "r");
	if (!f)
	{
		//error
		return 1;
	}

	t_headerFile headreOfFile;
	int read = fread(&headreOfFile, sizeof(t_headerFile), 1, f);
	if (headreOfFile.version == 1)
	{
		t_item* curr1;
		int id = 0;
		for (int i = 0; i < headreOfFile.itemsCount; i++)
		{
			curr1 = (t_item*)malloc(sizeof(t_item));
			read = fread(curr1, sizeof(t_item), 1, f);
			newItem2(curr1->val, curr1->key, id);
			id++;
			free(curr1);
		}
	}
	else if (headreOfFile.version == 2)
	{
		t_item2* curr2;
		for (int i = 0; i < headreOfFile.itemsCount; i++)
		{
			curr2 = (t_item2*) malloc(sizeof(t_item2));
			read = fread(curr2, sizeof(t_item2), 1, f);
			newItem2(curr2->val, curr2->key, curr2->id);
			free(curr2);
		}
	}
	// build the list

	freeMalloc();
	return 0;
}
