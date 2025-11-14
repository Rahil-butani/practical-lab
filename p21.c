#include <stdio.h>
#include <string.h>

int main()
{
    int num[25];
    printf("RAHIL-25CE011");

    int pos = 0, even = 0, odd = 0, neg = 0;
    for (int j = 0; j < 25; j++)
    {
        printf("Enter the %d number: ", j + 1);
        scanf("%d", &num[j]);
    }
    printf("\n");
    for (int i = 0; i < 25; i++)
    {
        if (num[i] > 0)
        {
            pos += 1;
        }
        else if (num[i] < 0)
        {
            neg += 1;
        }
    }
    for (int i = 0; i < 25; i++)
    {
        if (num[i] % 2 == 0)
        {
            even += 1;
        }
        else
        {
            odd += 1;
        }
    }
    printf("The number of even number is %d.\n", even);
    printf("The number of odd number is %d.\n", odd);
    printf("The number of positive number is %d.\n", pos);
    printf("The number of negative number is %d.\n", neg);
}