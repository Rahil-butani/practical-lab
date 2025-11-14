#include <stdio.h>

int main(void)
{
    float temp;
    printf("RAHIL-25CE011");

    printf("What is the temperature in 'C: ");
    scanf("%f", &temp);
    float f = ((temp * 9) / 5) + 32;
    printf("The temperature in Farenheit is %.3f'f\n", f);
    return 0;
}