#include <stdio.h>

int main(void)
{
    int age;
    printf("RAHIL-25CE011");

    do
    {
    printf("Enter your age: ");
    scanf("%d", &age);
    }
    while (age <= 0);

    if (age < 18)
    {
        printf("We are sorry to inform you but you aren't eligible to open an account in this bank since you don't meet the age requirements\n");
    }
    else if (age < 60)
    {
        printf("Congratulation! you can open a Regular Savings Account\n");
    }
    else if(age > 60)
    {
        printf("You are eligible for a Senior Citizen Account\n");
    }

}