#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)
typedef struct List
{
    int val;
    struct List* next;
    struct List* prev;
}List;
List* head = NULL;
List* tail = NULL;

void printLinkedList()
{
	List* currentL = head;
	List* printL;
    int count = 1;
	while (currentL != NULL)
	{
		printL = currentL;
		currentL = currentL->next;
		printf("#%d - %d\n",count, printL->val);
        count++;
	}
}
void freeLinkedList()
{
    List* currentL = head;
    List* releaseL;
    while (currentL != NULL)
    {
        releaseL = currentL;
        currentL = currentL->next;
        free(releaseL);
    }
}
void GenerateXList(int num)
{
    srand(time(0));
    List* currentL;
    List* prevL = NULL;
    for (size_t i = 0; i < num; i++)
    {
        currentL = (List*) malloc(sizeof(List));
        currentL->val = rand();
        if (head == NULL)
        {
            head = currentL;
            tail = currentL;
            currentL->next = NULL;
            currentL->prev = NULL;
        }
        else
        {
            tail = currentL;
            currentL->next = NULL;
            currentL->prev = prevL;
            prevL->next = currentL;
        }
        prevL = currentL;
    }
}
void InsertItem()
{
    List* currentL;
    List* prevL = NULL;
    List* nextL = NULL;
    int ind;
    int num;
    int count = 0;
    printf("insert item to list? 1 = yes | 0 = no : ");
    scanf("%d", &ind);
    while (ind == 1)
    {
        count++;
        printf("please enter a number:");
        scanf("%d", &num);
        currentL = (List*)malloc(sizeof(List));
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
        printf("insert item to list? 1 = yes | 0 = no : ");
        scanf("%d", &ind);
    }
    printf("done/skipped\n\n");
    if (count > 0)
    {
        printf("print list? 1 = yes | 0 = no : ");
        scanf("%d", &ind);
        if (ind == 1)
        {
            printLinkedList();
        }
    }
}
List* findVal()
{
    List* currentL = head;
    List* find;
    int ind;
    int num;
    printf("check wanted number adress? 1 = yes | 0 = no:");
    scanf("%d", &ind);
    if (ind == 1)
    {
        printf("type wanted number:");
        scanf("%d", &num);
        while (currentL != NULL)
        {
                find = currentL;
                currentL = currentL->next;
                if (find->val == num)
                {
                    printf("adress - %x\n", find);
                    return find;
                }
        }
                    printf("number does not excist\n");
                    return NULL;
    }
    else
    {
        return 1;
    }
}
void changeVal()
{
    List* AdressToChange = findVal();
    while (AdressToChange == NULL)
    {
        AdressToChange = findVal();
    }
    if (AdressToChange == 1)
    {
        printf("skipped\n\n");
    }
    else
    {
    printf("pleas pick a new number to switch %d in Adress:", AdressToChange->val);
    scanf("%d", &AdressToChange->val);
    printLinkedList();
    }
}
void resetList()
{
    if (head != NULL)
    {
        freeLinkedList();
        head = NULL;
        tail = NULL;
    }
}

int main()
{
    //GenerateXList(100);
    //printLinkedList();
    //changeVal();
    //resetList();
    InsertItem();

    return 0;
}