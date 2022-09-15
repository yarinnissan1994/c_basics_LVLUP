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

    sprintf(time, "%d.%d.%d-%d:%d:%d - %s\n\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
    FILE* f = fopen("HMlog.log", "a");
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
        LogEvent("last item in list removed - list is empty.");
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
        printf("LIST IS EMPTY");
        LogError("list is empty - failed to remove item.");
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
void BubbleSort()
{
    LogEvent("sort start.");
    Item* currentL = NULL;
    Item* currentLSwap = NULL;
    int swaps = 1;
    if (head == NULL)
    {
        printf("list is empty - sort failed");
        LogError("list is empty - sort failed.");
        return;
    }
    do
    {
        currentL = head;
        currentLSwap = head->next;
        swaps = 0;
        while (currentLSwap != NULL)
        {
            if (currentL->next && currentL->num > currentL->next->num)
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
    } while (swaps);
    LogEvent("list was sorted.");
    printf("list is now sorted\n\n");
}
void ShakerBubbleSort()
{
    LogEvent("sort start.");
    Item* currentL = NULL;
    Item* currentLSwap = NULL;
    Item* headStoper = NULL;
    Item* tailStoper = NULL;
    int swaps = 1;
    if (head == NULL)
    {
        printf("list is empty - sort failed");
        LogError("list is empty - sort failed.");
        return;
    }
    currentL = head;
    currentLSwap = head->next;
    do
    {
        swaps = 0;
        while (currentLSwap != NULL && currentL->next != tailStoper)
        {
            if (currentL->num > currentLSwap->num)
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
            if (currentL->num < currentLSwap->num)
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
    LogEvent("list was sorted.");
    printf("list is now sorted\n\n");
}

int main()
{
    LogEvent("program started seccesfuly.");
    int ind = 0;
    int num;
    Item* popedItem;
    srand(time(0));
    while (ind != 6)
    {
        printf("*********MENU*********\ntype item number for execution\n1.add item to list\n2.create random list\n3.remove item from list\n4.sort list\n5.print\n6.done\ntype here:");
        scanf("%d", &ind);
        printf("\n\n");
        switch (ind)
        {
        case 1:
            printf("enter a value:");
            scanf("%d", &num);
            PUSH(num);
            LogEvent("user enterd a value to list.");
            printf("\n\n");
            break;
        case 2:
            printf("select your random list size (type a number):");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                PUSH(rand()%1000);
            }
            LogEvent("created a random list.");
            printf("\n\n");
            break;
        case 3:
            popedItem = POP();
            if (popedItem != NULL)
            {
                printf("number %d - removed\n\n", popedItem->num);
                LogEvent("user removed item from list.");
                free(popedItem);
            }
            printf("\n\n");
            break;
        case 4:
            //BubbleSort();
            ShakerBubbleSort();
            printf("\n\n");
            break;
        case 5:
            printLinkedList();
            printf("\n\n");
            break;
        case 6:
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
    LogEvent("program ended seccesfuly.");
    return 0;
}