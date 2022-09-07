#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

int main7823_847()
{
    int a;
    typedef char LastName[100]; //type defenition
    typedef unsigned char CarCount;
    //structure of family
    typedef struct
    {
        LastName name;
        char adress[100];
        int members;
        CarCount cars;
    }Family_s;

    Family_s oneFamily;
    oneFamily.cars = 12;


    struct StudentDetails
    {
        LastName name;
        char adress[100];
        int members;
        int cars;
    };

    LastName UserNameInput;
    char UserAdressInput[100];
    return 0;
}