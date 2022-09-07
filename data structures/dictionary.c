#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct Item
{
    int val;
    int key;
    struct Item* next;
    struct Item* prev;
}Item;

Item* head = NULL;
Item* tail = NULL;
int itemCount = 0;

void printLinkedList()
{
    Item* currentL = head;
    Item* printL;
    while (currentL != NULL)
    {
        printL = currentL;
        currentL = currentL->next;
        printf("key - %d | value - %d\n", printL->key, printL->val);
    }
    printf("Items in dictionary: %d\n", itemCount);
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

Item* Search(int key)
{
    Item* currentL = head;
    if (itemCount == 0)
    {
        return currentL;
    }
    while (currentL->key != key)
    {
        currentL = currentL->next;
        if (currentL == NULL)
        {
            printf("key not excist in dictionary\n\n");
            break;
        }
    }
    return currentL;
}

void Add(int key, int val)
{
    Item* currentI;
    Item* checkI;
    checkI = Search(key);
    if (checkI == NULL)
    {
        currentI = (Item*)malloc(sizeof(Item));
        currentI->key = key;
        currentI->val = val;
        if (head == NULL)
        {
            head = currentI;
            tail = currentI;
            currentI->next = NULL;
            currentI->prev = NULL;
            itemCount++;
        }
        else
        {
            currentI->prev = head->prev;
            currentI->next = head;
            head->prev = currentI;
            head = currentI;
            itemCount++;
        }
    }
    else
    {
        printf("key already excist in dictionary!\nremove old key first and than try agian");
    }
}

Item* Remove(int key)
{
    Item* removeI = Search(key);
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


int main()
{
    int ind = 0;
    int key;
    int val;
    Item* ItemAdd;
    while (ind != 5)
    {
        printf("*********MENU*********\ntype item number for execution\n1.add item to dictionary\n2.search item in dictionary\n3.remove item from dictionary\n4.print\n5.done\ntype here:");
        scanf("%d", &ind);
        printf("\n\n");
        switch (ind)
        {
        case 1:
            printf("enter key and value:");
            scanf("%d %d", &key, &val);
            Add(key, val);
            printf("\n\n");
            break;
        case 2:
            printf("enter key to search in dictionary:");
            scanf("%d", &key);
            ItemAdd = Search(key);
            if (itemCount == 0)
            {
                printf("dictionary is empty\n\n");
            }
            if (ItemAdd == NULL)
            {
                break;
            }
            printf("key - %d | value - %d", ItemAdd->key, ItemAdd->val);
            printf("\n\n");
            break;
        case 3:
            printf("enter key to remove from dictionary:");
            scanf("%d", &key);
            ItemAdd = Remove(key);
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
            printf("\n\n");
            break;
        case 4:
            if (itemCount == 0)
            {
                printf("dictionary is empty\n\n");
                break;
            }
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