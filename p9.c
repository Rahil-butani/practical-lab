#include <stdio.h>

int main(void)
{
    int p;
    printf("Enter the cost of your items: ");
    scanf("%d", &p);
    printf("RAHIL-25CE011");

    if(p < 1000)
    {
        printf("Your final price is %d", p);
    }
    else if(p < 5000)
    {
        int a = (p * 90) / 100;
        printf("Your total is $%d\n", a);
    }
    else if( p > 5000)
    {
        int b = (p * 80) / 100;
        printf("Your total is $%d\n", b);
    }
}