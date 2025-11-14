#include <stdio.h>
#include <unistd.h>

int main()
{
    int count, i;
    printf("RAHIL-25CE011");

    printf("Enter the starting number: ");
    scanf("%d", &count);

    for(i = count; i > 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }
    if(i == 0)
    {
        printf("Countdown Complete!\n");
    }
}