#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

void LinkedList1()
    {
    struct Students
    {
        int age;
        int phone;
        int id;
    };
    struct Students* origin;
    struct Students* currentS;
    int userSize;
    printf("plaese enter how many items you need in struct:");
    scanf("%d", &userSize);
    origin = malloc(sizeof(struct Students) * userSize);
    currentS = origin;
    for (int i = 0; i < userSize; i++)
    {
        printf("please enter age, phone number and id:");
        scanf("%d %d %d", &currentS->age, &currentS->phone, &currentS->id);
        currentS++;
    }
    FILE* f = fopen("LinkedList.bin", "w");
    fwrite(origin, sizeof(struct Students), userSize, f);
    fclose(f);
    free(origin);
    }

void LinkedList2()
{
    struct Students
    {
        int age;
        int phone;
        int id;
    };
    struct Students s;
    int ind = 1;
    int count = 0;
    long sum = 0;
    FILE* f = fopen("LinkedList.bin", "r");
    if (!f)
    {
        //ERROR
    }
    else 
    {
        while (fread(&s, sizeof(struct Students), 1, f))
        {
            sum = sum + s.id;
        }
        fclose(f);
    }
    printf("adding all id's gives us %u", sum);
}

int main823_5()
{
    //LinkedList1();
    //LinkedList2();
    return 0;
}
