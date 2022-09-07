//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning (disable : 4996)
//
//struct Item
//{
//	int id;
//	int val;
//	struct Item* next;
//};
//struct Item* head = NULL;
//
//void printLinkedList()
//{
//	struct Item* currentI = head;
//	struct Item* printI;
//	while (currentI != NULL)
//	{
//		printI = currentI;
//		currentI = currentI->next;
//		printf("%d\t%d\n",printI->id, printI->val);
//	}
//}
//void freeLinkedList()
//{
//	struct Item* currentI = head;
//	struct Item* releaseI;
//	while (currentI != NULL)
//	{
//		releaseI = currentI;
//		currentI = currentI->next;
//		free(releaseI);
//	}
//}
//
//int main72138_87321()
//{
//	int userResponse;
//	struct Item* currentI;
//	struct Item* prevI = NULL;
//	printf("Click 1 for Add\nClick 2 for Print all List\nClick 3 for Exit\n");
//	scanf("%d", &userResponse);
//	while (userResponse == 1)
//	{
//		currentI = malloc(sizeof(struct Item));
//
//		if (head == NULL)
//		{
//			head = currentI;
//		}
//		else
//		{
//			prevI->next = currentI;
//		}
//		printf("plaese enter id and valeu:");
//		scanf("%d %d", &currentI->id, &currentI->val);
//		currentI->next = NULL;
//		printf("\nClick 1 for Add\nClick 2 for Print all List\nClick 3 for Exit\n");
//		scanf("%d", &userResponse);
//		prevI = currentI;
//		if (userResponse == 2)
//		{
//			printLinkedList();
//			printf("\nClick 1 for Add\nClick 2 for Print all List\nClick 3 for Exit\n");
//			scanf("%d", &userResponse);
//		}
//		else if (userResponse == 3)
//		{
//			freeLinkedList();
//		}
//	}
//	return 0;
//}

