#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

//int main1278_22()
//{
//	struct Item
//	{
//		int id;
//		int val;
//		struct Item* next;
//	};
//	int userResponse;
//
//	printf("Click 1 for Add\nClick 2 for Print all List\nClick 3 for Exit");
//	scanf("%d", &userResponse);
//	struct Item* head = NULL;
//	struct Item* currentI;
//	struct Item* prevI;
//	while (userResponse == 1)
//	{
//		currentI = malloc(sizeof(struct Item));
//
//		if (head == NULL)
//		{
//			head == currentI;
//		}
//		else
//		{
//			prevI->next = currentI;
//		}
//
//		scanf("%d %d", &head->id, &head->val);
//		currentI->next = NULL;
//		printf("Click 1 for Add\nClick 2 for Print all List\nClick 3 for Exit");
//		scanf("%d", &userResponse);
//		prevI = currentI;
//	}
//    return 0;
//}