#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct Item
{
	int val;
	struct List* next;
	struct List* prev;
}Item;

Item* head = NULL;
Item* tail = NULL;

Item* FindHigher(Item* curr)
{
	Item* currentI = curr;
	Item* nextI = head;
	Item* ret = NULL;
	while (nextI != NULL)
	{
		if (nextI->val > currentI->val)
		{
			ret = nextI;
			break;
		}
		ret = nextI;
		nextI = nextI->next;
	}
	return ret;

}

void InsertItemH(int num)
{
	Item* currentI = (Item*) malloc(sizeof(Item));
	Item* nextI = NULL;
	Item* prevI = NULL;
	currentI->val = num;
	if (head == NULL)
	{
		head = currentI;
		tail = currentI;
		currentI->prev = NULL;
		currentI->next = NULL;
	}
	else
	{
		nextI = FindHigher(currentI);
		if (nextI->prev == NULL || head->next == NULL)//HEAD
		{
			currentI->prev = NULL;
			currentI->next = head;
			head->prev = currentI;
			head = currentI;
		}
		else if (nextI->next == NULL)//TAIL
		{
			currentI->prev = tail;
			currentI->next = NULL;
			tail->next = currentI;
			tail = currentI;
		}
		else//MIDDLE
		{
			prevI = nextI->prev;
			currentI->prev = nextI->prev;
			currentI->next = nextI;
			prevI->next = currentI;
			nextI->prev = currentI;
		}
	}
}

void PrintList()
{
	Item* currentI = head;
	int count = 1;
	while (currentI != NULL)
	{
		printf("#%d %d\n", count, currentI->val);
		currentI = currentI->next;
		count++;
	}
}

void InsertItemY(int num)
{
	Item* currentL;
	Item* prevL = NULL;
	Item* nextL = NULL;
	currentL = (Item*)malloc(sizeof(Item));
	currentL->val = num;
	if (head == NULL)
	{
		head = currentL;
		tail = currentL;
		currentL->next = NULL;
		currentL->prev = NULL;
	}
	else
	{
		nextL = head;
		prevL = NULL;
		while (currentL->val > nextL->val)
		{
			prevL = nextL;
			nextL = nextL->next;
			if (nextL == NULL)
			{
				break;
			}
		}
		if (prevL == NULL)
		{
			head = currentL;
			currentL->prev = NULL;
			currentL->next = nextL;
			nextL->prev = currentL;
		}
		else if (nextL == NULL)
		{
			tail = currentL;
			currentL->next = NULL;
			currentL->prev = prevL;
			prevL->next = currentL;
		}
		else
		{
			currentL->prev = prevL;
			currentL->next = nextL;
			prevL->next = currentL;
			nextL->prev = currentL;
		}
	}
}


int main()
{
	InsertItemY(3);
	InsertItemY(5);
	InsertItemY(1);
	InsertItemY(9);
	InsertItemY(2);
	InsertItemY(7);
	InsertItemY(12);
	InsertItemY(11);
	PrintList();
	return 0;
}
