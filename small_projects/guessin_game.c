#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable : 4996)

int main231()
{
    const int MIN = 1;
    const int MAX = 100;
    int guesses = 0;
    int guess;
    int answer;

    //uses the current time as a seed
    srand(time(0));

    //generate a random number between MIN & MAX
    answer = (rand() % MAX) + MIN;

    do {
        printf("Enter a guess: ");
        scanf("%d", &guess);
        if (guess > answer)
        {
            printf("Too high!\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n");
        }
        else {
            printf("CORRECT!\n");
        }
        guesses++;
    } while (guess != answer);

    printf("**********************\n");
    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    printf("**********************");

    return 0;
}