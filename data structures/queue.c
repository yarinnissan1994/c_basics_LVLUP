#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

typedef struct Item
{
	int val1;
	int val2;
	int id;
	struct Item* next;
    struct Item* prev;
}Item;

Item* head = NULL;
Item* tail = NULL;
int CounterID = 0;
int itemCount = 0;

void printLinkedList()
{
    Item* currentL = tail;
    Item* printL;
    while (currentL != NULL)
    {
        printL = currentL;
        currentL = currentL->prev;
        printf("#%d - val1 = %d & val2 = %d\n", printL->id, printL->val1, printL->val2);
    }
    printf("Items in queue: %d\n", itemCount);
}
void freeLinkedList()
{
    Item* currentL = head;
    Item* releaseL;
    while (currentL != NULL)
    {
        releaseL = currentL;
        currentL = currentL->next;
        free(releaseL);
    }
}
void PUSH(int val1, int val2)
{
    Item* currentI;
    currentI = (Item*)malloc(sizeof(Item));
    if (head == NULL)
    {
        head = currentI;
        tail = currentI;
        currentI->val1 = val1;
        currentI->val2 = val2;
        currentI->next = NULL;
        currentI->prev = NULL;
        CounterID++;
        itemCount++;
        currentI->id = CounterID;
    }
    else
    {
        currentI->prev = head->prev;
        currentI->next = head;
        head->prev = currentI;
        currentI->val1 = val1;
        currentI->val2 = val2;
        head = currentI;
        CounterID++;
        itemCount++;
        currentI->id = CounterID;
    }
}
Item* POP()
{
    if (itemCount == 1)
    {
        head = NULL;
        tail = NULL;
        itemCount--;
        printf("last item in queue removed");
        return head;
    }
    else if (head!=NULL)
    {
        Item* freeAdd;
        freeAdd = tail;
        tail = tail->prev;
        tail->next = NULL;
        itemCount--;
        return freeAdd;
    }
    else
    {
        printf("QUEUE IS EMPTY");
        return 0;
    }
}

int main()
{
    int ind = 0;
    int val1, val2;
    Item* popedItem;
    while (ind != 4)
    {
        printf("*********MENU*********\ntype item number for execution\n1.add item to list\n2.remove item from list\n3.print\n4.done\ntype here:");
        scanf("%d", &ind);
        printf("\n\n");
        switch (ind)
        {
        case 1:
            printf("enter two values:");
            scanf("%d %d", &val1, &val2);
            PUSH(val1, val2);
            printf("\n\n");
            break;
        case 2:
            popedItem = POP();
            free(popedItem);
            printf("\n\n");
            break;
        case 3:
            printLinkedList();
            printf("\n\n");
            break;
        case 4:
            printf("done!");
            printf("\n\n");
            break;
        default:
            printf("invalid number");
            printf("\n\n");
            break;
        }
    }
    freeLinkedList();
    printf("thank you for using my program =]\n\n");
	return 0;
}