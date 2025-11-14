#include <stdio.h>
int main(void)
{
    int i;
    printf("RAHIL-25CE011");

    do{
    printf("Enter your marks: ");
    scanf("%d", &i);}
    while (i < 0 || i>100);

    if(i >= 90){
        printf("You have got A grade\n");
    }
    if(i < 90 && i >= 80){
        printf("You have got B grade\n");
    }
    if(i < 80 && i >= 70 ){
        printf("You have got C grade\n");
    }
    if(i < 70 && i  >= 60){
        printf("You have got D grade\n");
    }
    if(i < 60){
        printf("You have got F grade\n");
    }
}