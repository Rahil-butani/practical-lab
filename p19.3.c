#include <stdio.h>

int main()
{
    int n = 5;
    printf("RAHIL-25CE011");

    for (int i = 1; i <= n; i++)
    {
        for (int s = 1; s < i; s++)
        {
            printf(" ");
        }
        int start_num = n - i + 1;
        for (int j = start_num; j >= 1; j--)
        {
            printf("%d", j);
        }
        for (int j = 2; j <= start_num; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) 
    {
        for (int s = 1; s < i; s++) {
            printf(" ");
        }
        int start_num = n - i + 1;
        for (int j = start_num; j >= 1; j--) {
            printf("%d", j);
        }
        for (int j = 2; j <= start_num; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}