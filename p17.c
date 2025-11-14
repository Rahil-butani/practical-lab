#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, t;
    printf("RAHIL-25CE011");

    printf("How long is your marathon: ");
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        float d = i * 0.5;
        printf("%d Minute = %.1f kms\n", i, d);
        sleep(1);
    }
    printf("Marathon Complete!!\n");
}