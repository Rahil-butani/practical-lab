#include <stdio.h>

int main()
{
    int age;
    char answer;
    do
    {
        printf("Enter your Age: ");
        scanf("%d", &age);
    printf("RAHIL-25CE011");

        if (age <= 12)
        {
        printf("Your fare is free since you are under our criterion\n");
        }
        else if (age > 12)
        {
            printf("Your fare is $250\n");
        }
        else
        {
            printf("Your are not required to pay the fair since you are a senior citizen");
        }

        printf("Do you want to add a member to your ticket(Y or N): ");
        scanf(" %c", &answer);
    }
    while (answer == 'Y' || answer == 'y');

}