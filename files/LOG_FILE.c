#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
    FILE* f = fopen("mtProg.log", "w");

    fputs("line1\n", f);
    fputs("line2\n", f);
    fputs("line3\n", f);

    fclose(f);
    
    char str[1000];

    f = fopen("mtProg.log", "r");
    //           to-amount-from           //
    while (fgets(str, 1000, f) != NULL)
    {
        printf("%s", str);
    }

    return 0;
}

//LOG File
//ERRORS <-
//WARNINGS X
//EVENTS <-

//******log comamands******
//fputs - put string inside file
//fgets - get string from file