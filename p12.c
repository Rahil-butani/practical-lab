#include <stdio.h>
int main(void)
{
    int n, i;
    printf("RAHIL-25CE011");

    printf("Enter the number of books in the library: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        if( i % 5 == 0)
        {
            printf("Book ID: %d(Special Edition)\n", i);
        }
        else
        {
            printf("Book ID: %d\n", i);
        }
    }
}