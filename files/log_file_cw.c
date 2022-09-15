#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

void Log(char message[1000])
{
    time_t t;
    time(&t);
    struct tm* timeinfo;
    timeinfo = localtime(&t);
    char time[1000];

    sprintf(time, "%d.%d.%d-%d:%d:%d - %s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo ->tm_min, timeinfo->tm_sec, message);
    FILE* f = fopen("cwLog.log", "a");
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

int main()
{
    char userNum[100];
    char numToString[100];
    LogEvent("strat\n");

    printf("please enter a number:");
    scanf("%s", userNum);
    strcat(userNum, " - user input\n");
    LogEvent(userNum);

    FILE* f = fopen("numCount.txt", "a");
    if (!f)
    {
        LogError("failed to open numCount.txt\n");
    }
    else 
    {
        LogEvent("seccesfuly written to numCount.txt\n");
        for (int i = 1; i <= atoi(userNum); i++)
        {
            fputs((itoa(i, numToString, 10)), f);
            fputs("\n", f);
        }
        fclose(f);
    }

    LogEvent("end\n");

    return 0;
}