#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct Item
{
    int num;
    struct Item* next;
    struct Item* prev;
}Item;

Item* head = NULL;
Item* tail = NULL;
int itemCount = 0;

void Log(char message[1000])
{
    time_t t;
    time(&t);
    struct tm* timeinfo;
    timeinfo = localtime(&t);
    char time[1000];

    sprintf(time, "%d.%d.%d-%d:%d:%d - %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
    FILE* f = fopen("cwLog.log", "a");
    fputs(time, f);
    fclose(f);
}

void LogError(char message[100])
{
    char error[100] = "Error - ";
    strcat(error, message);
    Log(error);
}

void LogEvent(char message[100])
{
    char event[100] = "Event - ";
    strcat(event, message);
    Log(event);
}

void LogEventVal(char message[100], int val)
{
    char event[100] = "Event - value %d was added to list by user ";
    strcat(event, message);
    Log(event);
}


void printLinkedList()
{
    Item* currentL = head;
    Item* printL;
    int count = 1;
    while (currentL != NULL)
    {
        printL = currentL;
        currentL = currentL->next;
        printf("#%d - num = %d\n", count, printL->num);
        count++;
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
void PUSH(int num)
{
    Item* currentI;
    currentI = (Item*)malloc(sizeof(Item));
    currentI->num = num;
    currentI->next = NULL;
    if (head == NULL)
    {
        head = currentI;
        tail = currentI;
        currentI->prev = NULL;
        itemCount++;
    }
    else
    {
        currentI->prev = tail;
        tail->next = currentI;
        tail = currentI;
        itemCount++;
    }
}
Item* POP()
{
    Item* freeAdd;
    if (itemCount == 1)
    {
        freeAdd = head;
        head = NULL;
        tail = NULL;
        itemCount--;
        printf("last item in queue removed - ");
        return freeAdd;
    }
    else if (head != NULL)
    {
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
void Swap(Item* Adress)
{
    if (Adress == NULL || Adress->next == NULL)
    {
        return;
    }
    Item* temp = (Item*)malloc(sizeof(Item));
    temp->next = Adress->next->next;
    temp->prev = Adress->next;
    Adress->next->next = Adress;
    Adress->next->prev = Adress->prev;
    Adress->next = temp->next;
    Adress->prev = temp->prev;
    free(temp);
    if (Adress->prev->prev==NULL)
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
void BubbleSort()
{
    Item* currentL = NULL;
    Item* currentLN = NULL;
    int swaps = 1;
    if (head == NULL)
    {
        return;
    }
    do
    {
        currentL = head;
        currentLN = head->next;
        swaps = 0;
        while (currentLN != NULL)
        {
            if (currentL->next && currentL->num > currentLN->num)
            {
                Swap(currentL);
                swaps = 1;
                currentLN = currentL->next;
            }
            else
            {
                currentL = currentL->next;
                currentLN = currentLN->next;
            }
        }
    } while (swaps);
    printf("list is now sorted\n\n");
}
void ShakerBubbleSort()
{
    Item* currentL = NULL;
    int swaps = 1;
    if (head == NULL)
    {
        return;
    }
    do
    {
        currentL = head;
        swaps = 0;
        while (currentL != NULL)
        {
            if (currentL->next && currentL->num > currentL->next->num)
            {
                Swap(currentL);
                swaps = 1;
            }
            currentL = currentL->next;
        }
    } while (swaps);
    printf("list is now sorted\n\n");
}

int main()
{
    int ind = 0;
    int num;
    Item* popedItem;
    while (ind != 5)
    {
        printf("*********MENU*********\ntype item number for execution\n1.add item to list\n2.remove item from list\n3.sort list\n4.print\n5.done\ntype here:");
        scanf("%d", &ind);
        printf("\n\n");
        switch (ind)
        {
        case 1:
            printf("enter a value:");
            scanf("%d", &num);
            PUSH(num);
            printf("\n\n");
            break;
        case 2:
            popedItem = POP();
            if (popedItem != NULL)
            {
                printf("number %d - removed\n\n", popedItem->num);
                free(popedItem);
            }
            printf("\n\n");
            break;
        case 3:
            BubbleSort();
            printf("\n\n");
            break;
        case 4:
            printLinkedList();
            printf("\n\n");
            break;
        case 5:
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

//מיון שייקר - shaking sort;