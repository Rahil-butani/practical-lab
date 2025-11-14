#include <stdio.h>

int main()
{
    int i, j;
    int n, m;
    printf("RAHIL-25CE011");

    printf("Enter how many multiplication tables do you want: ");
    scanf("%d", &n);
    printf("Enter how many multiples do you want: ");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    printf("Harshil Prajapati\n");
}
