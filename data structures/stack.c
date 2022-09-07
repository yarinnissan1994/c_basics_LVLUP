//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning (disable : 4996)
//
//typedef struct Item
//{
//    int val1;
//    int val2;
//    int id;
//    struct Item* next;
//    struct Item* prev;
//}Item;
//
//Item* head = NULL;
//Item* tail = NULL;
//int CounterID = 0;
//int itemCount = 0;
//
//void printLinkedList()
//{
//    Item* currentL = tail;
//    Item* printL;
//    while (currentL != NULL)
//    {
//        printL = currentL;
//        currentL = currentL->prev;
//        printf("#%d - val1 = %d & val2 = %d\n", printL->id, printL->val1, printL->val2);
//    }
//    printf("Items in queue: %d\n", itemCount);
//}
//void freeLinkedList()
//{
//    Item* currentL = head;
//    Item* releaseL;
//    while (currentL != NULL)
//    {
//        releaseL = currentL;
//        currentL = currentL->next;
//        free(releaseL);
//    }
//}
//void PUSH(int val1, int val2)
//{
//    Item* currentI;
//    currentI = (Item*)malloc(sizeof(Item));
//    if (head == NULL)
//    {
//        head = currentI;
//        tail = currentI;
//        currentI->val1 = val1;
//        currentI->val2 = val2;
//        currentI->next = NULL;
//        currentI->prev = NULL;
//        CounterID++;
//        itemCount++;
//        currentI->id = CounterID;
//    }
//    else
//    {
//        currentI->prev = head->prev;
//        currentI->next = head;
//        head->prev = currentI;
//        currentI->val1 = val1;
//        currentI->val2 = val2;
//        head = currentI;
//        CounterID++;
//        itemCount++;
//        currentI->id = CounterID;
//    }
//}
//void multiPUSH()
//{
//    Item* currentI;
//    srand(time(0));
//    int ind = 0;
//    if (head == NULL)
//    {
//        currentI = (Item*)malloc(sizeof(Item));
//        head = currentI;
//        tail = currentI;
//        currentI->val1 = (rand() % 100);
//        currentI->val2 = (rand() % 100);
//        currentI->next = NULL;
//        currentI->prev = NULL;
//        CounterID++;
//        itemCount++;
//        currentI->id = CounterID;
//        ind++;
//    }
//    int num;
//    if (ind = 0)
//    {
//        num = 100;
//    }
//    else
//    {
//        num = 99;
//    }
//    for (int i = 0; i < num; i++)
//    {
//    currentI = (Item*)malloc(sizeof(Item));
//    currentI->prev = head->prev;
//    currentI->next = head;
//    head->prev = currentI;
//    currentI->val1 = (rand() % 100);
//    currentI->val2 = (rand() % 100);
//    head = currentI;
//    CounterID++;
//    itemCount++;
//    currentI->id = CounterID;
//    }
//}
//Item* POP()
//{
//    if (itemCount == 1)
//    {
//        head = NULL;
//        tail = NULL;
//        itemCount--;
//        printf("last item in queue removed");
//        return head;
//    }
//    else if (head != NULL)
//    {
//        Item* freeAdd;
//        freeAdd = head;
//        head = head->next;
//        head->prev = NULL;
//        itemCount--;
//        return freeAdd;
//    }
//    else
//    {
//        printf("QUEUE IS EMPTY");
//        return 0;
//    }
//}
//
//
//int main()
//{
//    int ind = 0;
//    int val1, val2;
//    Item* popedItem;
//    while (ind != 6)
//    {
//        printf("*********MENU*********\ntype item number for execution\n1.add item to list\n2.add 100 random items to list\n3.remove item from list\n4.remove 10 items from list\n5.print\n6.done\ntype here:");
//        scanf("%d", &ind);
//        printf("\n\n");
//        switch (ind)
//        {
//        case 1:
//            printf("enter two values:");
//            scanf("%d %d", &val1, &val2);
//            PUSH(val1, val2);
//            printf("\n\n");
//            break;
//        case 2:
//            multiPUSH();
//            printf("\n\n");
//            break;
//
//        case 3:
//            popedItem = POP();
//            printf("%d %d - removed", popedItem->val1, popedItem->val2);
//            free(popedItem);
//            printf("\n\n");
//            break;
//        case 4:
//            for (int i = 0; i < 10; i++)
//            {
//            popedItem = POP();
//            printf("%d %d -  - removed", popedItem->val1, popedItem->val2);
//            free(popedItem);
//            printf("\n\n");
//            }
//            break;
//        case 5:
//            printLinkedList();
//            printf("\n\n");
//            break;
//        case 6:
//            printf("done!");
//            printf("\n\n");
//            break;
//        default:
//            printf("invalid number");
//            printf("\n\n");
//            break;
//        }
//    }
//    freeLinkedList();
//    printf("thank you for using my program =]\n\n");
//    return 0;
//}