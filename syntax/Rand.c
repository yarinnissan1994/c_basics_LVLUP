#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

int main412_99()
{
    time_t i = time(0);//unix time (seconds count from 1.1.1970 (00:00 Am))
    srand(i);
    long sum = 0;
    int a;
    for (int i = 0; i < 100000; i++)
    {
        a = rand();
        sum = sum + a;
    }
    printf("sum = %d\n", sum);
    int avg = sum / 100000;
    printf("avg = %d\n", avg);
    return 0;
}