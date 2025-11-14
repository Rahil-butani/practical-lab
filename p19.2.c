#include <stdio.h>

int main()
{
    printf("RAHIL-25CE011");

    int rows = 5;
    int cols = 9;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (i == 1)
            {
                printf("%d", j);
            }
            else
            {
                if (j == i || j == (cols + 1 - i))
            {
                    printf("%d", j);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}