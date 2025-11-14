#include <stdio.h>

int main(void)
{
    int n,m = 5000,d = 0,w;
    printf("RAHIL-25CE011");

    do
    {
            do{printf("\n=== Welcome to Bank of New York ===\n 1 =  Display the balance\n 2 = Deposit Money\n 3 = Withdraw Money\n 4 = Exit the loop\n");
            printf("Enter a number according to your need: ");
            scanf("%d", &n);}
            while(n < 1 || n > 4);

            switch (n)
        {
            case 1:
            {
                printf("Your Balance is $%d.\n", m);
            }
            break;
            case 2:
            {
                printf("Enter the amount of money you want to deposit: ");
                scanf("%d", &d);
                m += d; // m = m + d;
            }break;
            case 3:
            {
                printf("Enter the amount of money you want to withdraw: ");
                scanf("%d", &w);
                if ( w < m)
                {
                    m -= w;
                }
                else
                {
                    printf("Please enter a valid amount\n");
                }
            }break;
            case 4:
            break;

        }
    } while(n < 4);

    return 0;
}