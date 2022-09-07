#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main2()
{
	struct Item
	{
		int price;
		int barcode;
		char name[100];
		char color[100];
	};

	int a;
	struct Item item1;
	struct Item item2;

	item1.price = 12;
	strcpy(item1.name, "cola");
	strcpy(item1.color, "black");

	item2.price = 9;
	strcpy(item2.name, "pepsi");
	strcpy(item2.color, "black");

	printf("item:%s \t price:%d\n", item1.name, item1.price);
	printf("item:%s \t price:%d\n", item2.name, item2.price);

	struct Item itemList[10];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %s %s %d", &itemList[i].barcode, itemList[i].name, itemList[i].color, &itemList[i].price);
	}

	//struct Workers
	//{
	//	char name[100];
	//	int age;
	//	int id;
	//};

	//struct Workers workerlist[5];
	//for (int i = 0; i < 5; i++)
	//{
	//	scanf("%s %d %d", workerlist[i].name, &workerlist[i].age, &workerlist[i].id);
	//}
	//printf("\n***********************************************************************\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%s %d %d\n", workerlist[i].name, workerlist[i].age, workerlist[i].id);
	//}

	FILE* f = fopen("ItemList.dat", "m");
	if (f != NULL)
	{
		fwrite(&item1, sizeof(struct Item), 1, f);
		fwrite(&item2, sizeof(struct Item), 1, f);

		fclose(f);
		//------------------------------------------------
		struct Item ItemToRead;

		FILE* f = fopen("ItemList.dat", "r");
		if (f != NULL)
		{
			fread(&ItemToRead, sizeof(struct Item), 1, f);

			fclose(f);
		}
	}


	return 0;
}