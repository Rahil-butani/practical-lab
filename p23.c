#include <stdio.h>

int maxProfit(int prices[], int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int max_profit = 0;
    int min_price = prices[0];
    int buy_day = 0, sell_day = 0;
    int temp_buy_day = 0;
    int i;

    for (i = 1; i < n; i++)
    {
        if (prices[i] < min_price)
        {
            min_price = prices[i];
            temp_buy_day = i;
        }

        int current_profit = prices[i] - min_price;

        if (current_profit > max_profit)
        {
            max_profit = current_profit;
            buy_day = temp_buy_day;
            sell_day = i;
        }
    }

    if (max_profit > 0)
    {
        printf("\nTransaction Details:\n");
        printf("-------------------\n");
        printf("Buy on day %d at price: %d\n", buy_day + 1, prices[buy_day]);
        printf("Sell on day %d at price: %d\n", sell_day + 1, prices[sell_day]);
        printf("Profit: %d - %d = %d\n", prices[sell_day], prices[buy_day], max_profit);
    }
    else
    {
        printf("\nNo profitable transaction is possible.\n");
        printf("The prices keep decreasing or stay the same.\n");
    }

    return max_profit;
}

int main()
{
    int n;
    printf("RAHIL-25CE011");

    int i;
    int prices[100];

    printf("Fruit Stand Profit Maximizer\n");
    printf("=============================\n\n");

    printf("Enter the number of days: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of days! Please enter between 1 and 100.\n");
        return 1;
    }

    printf("Enter the fruit prices for %d days:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Day %d price: ", i + 1);
        scanf("%d", &prices[i]);
    }

    printf("\n=============================\n");
    printf("Prices entered: [");
    for (i = 0; i < n; i++) {
        printf("%d", prices[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    int profit = maxProfit(prices, n);

    printf("\n=============================\n");
    printf("Maximum Profit: %d\n", profit);
    printf("=============================\n");

    return 0;
}