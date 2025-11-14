#include <stdio.h>
int main(void)
{
    int capacity, i;
    printf("RAHIL-25CE011");

    printf("Enter the capacity of the Tank: ");
    scanf("%d", &capacity);

    for(i = 0; i<= capacity; i+=10)
    {
        if(i == capacity)
        {
            printf("The Tank is full.\n");
        }
        else
        {
            printf("Current water level: %d\n", i);
        }
    }
}