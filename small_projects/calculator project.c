#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

double sumtd(char sumtd[])
{
    char mathip[1000];
    char numholder[1000];
    char* ptr;
    char* numstart;
    char op = '+';
    double sum = 0;
    int counter = 0;
    ptr = sumtd;
    numstart = sumtd;
    for (int i = 0; i < strlen(sumtd); i++)
    {
        if (*ptr == '*' || *ptr == '/')
        {
            if (op == '+')
            {
                int numlen = ptr - numstart;
                strncpy(numholder, numstart, numlen);
                numholder[numlen] = 0;
                sum = sum + atoi(numholder);
                numstart = numstart + numlen + 1;
                op = *ptr;
            }
            else if (op == '*')
            {
                int numlen = ptr - numstart;
                strncpy(numholder, numstart, numlen);
                numholder[numlen] = 0;
                sum = sum * atoi(numholder);
                numstart = numstart + numlen + 1;
                op = *ptr;
            }
            else if (op == '/')
            {
                int numlen = ptr - numstart;
                strncpy(numholder, numstart, numlen);
                numholder[numlen] = 0;
                sum = sum / atoi(numholder);
                numstart = numstart + numlen + 1;
                op = *ptr;
            }
            counter++;
        }
        ptr++;
    }
    strcpy(numholder, numstart);
    if (op == '*')
    {
        sum = sum * atoi(numholder);
    }
    else
    {
        sum = sum / atoi(numholder);
    }
    if (counter == 0)
    {
        sum = 0;
    }
    return sum;
}
double sumpm(char sumpm[])
{
    char mathip[1000];
    char numholder[1000];
    char* ptr;
    char* numstart;
    char op = '+';
    double sum = 0;
    int counter = 0;
    int countzero = 0;
    ptr = sumpm;
    numstart = sumpm;
    for (int i = 0; i < strlen(sumpm) + 1; i++)
    {
        if (*ptr == '+' || *ptr == '-' || *ptr == NULL)
        {
            if (op == '+' && counter == 0)
            {
                int numlen = ptr - numstart;
                strncpy(numholder, numstart, numlen);
                numholder[numlen] = 0;
                sum = sum + atoi(numholder);
                numstart = numstart + numlen + 1;
                op = *ptr;
            }
            else if (op == '-' && counter == 0)
            {
                int numlen = ptr - numstart;
                strncpy(numholder, numstart, numlen);
                numholder[numlen] = 0;
                sum = sum - atoi(numholder);
                numstart = numstart + numlen + 1;
                op = *ptr;
            }
        }
        if (*ptr == '*' || *ptr == '/')
        {
            counter++;
        }
        if (*ptr == '+' || *ptr == '-')
        {
            countzero++;
            op = *ptr;
        }
        if (countzero == 1)
        {
            numstart = ptr + 1;
            counter = 0;
            countzero = 0;
        }
        ptr++;
    }
    return sum;
}
int main()
{
    char mathip[1000];
    char numholder[1000];
    char* ptr;
    char* numstart;
    char* tdmath;
    char* pmmath;
    int runagain = 1;
    while (runagain == 1)
    {
        char op = '+';
        double sum = 0;
        int counter = 0;
        int helper = 0;
        ptr = mathip;
        numstart = mathip;
        tdmath = mathip;
        printf("please enter a math equation using just +\\-\\*\\/:\n");
        scanf("%s", &mathip);
        for (int i = 0; i < strlen(mathip) + 1; i++)
        {
            if (*ptr == '+' || *ptr == '-' || *ptr == NULL)
            {
                if (op == '+')
                {
                    int numlen = ptr - numstart;
                    tdmath = tdmath + numlen + 1;
                    strncpy(numholder, numstart, numlen);
                    numholder[numlen] = 0;
                    double timdiv = sumtd(numholder);
                    sum = sum + timdiv;
                    numstart = numstart + numlen + 1;
                    op = *ptr;
                    helper++;
                }
                else if (op == '-')
                {
                    int numlen = ptr - numstart;
                    tdmath = tdmath + numlen + 1;
                    strncpy(numholder, numstart, numlen);
                    numholder[numlen] = 0;
                    double timdiv = sumtd(numholder);
                    sum = sum - timdiv;
                    numstart = numstart + numlen + 1;
                    op = *ptr;
                    helper++;
                }
            }
            ptr++;
        }
        sum = sum + (sumpm(mathip));
        printf("%s = %lf", mathip, sum);
        printf("\ndo you want to try again? (1 = yes\\0 = no):");
        scanf("%d", &runagain);
    }
    printf("good bye =]");
    return 0;
}
