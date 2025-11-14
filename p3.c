#include <stdio.h>

int main(void)
{
    printf("RAHIL-25CE011");


    float weight; float height;

    printf("Hello! what is your weight in kilograms: ");
    scanf("%f", &weight);
    printf("what is your height in meters: ");
    scanf("%f", &height);
    float bmi = weight / (height * height);
    printf("Your BMI is: %.2f\n", bmi);
}
