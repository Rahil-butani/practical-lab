#include<stdio.h>
int a,b,c;
float A;
void input();
void valid();
void area();
void main()
{
    input();
    printf(“This program is created by Rahil Butani”);
}
void input()
{
    printf("Enter length of 1st side:");
    scanf("%d",&a);

    printf("\nEnter length of 2nd side:");
    scanf("%d",&b);

    printf("\nEnter length of 3rd side:");
    scanf("%d",&c);

    valid();
}
void valid()
{
    if(a<=0 || b<=0 || c<=0)
    {
        printf("Valid Triangle: No\n ");
        printf("Massage: \"Side length must be a positive number\".\n ");
    }
    else if(a+b<=c || b+c<=a || a+c<=b)
    {
        printf("valid Triangle : No\n");
        printf("Massage: \"The give length is not a form of valid triangle\".\n ");
    }
    else
    {
        area();
    }
}
void area()
{
    float s;
    s=(a+b+c)/2.0;
     A=sqrt(s*(s-a)(s-b)(s-c));

     printf("valid Triangle : Yes");
     printf("\nArea :%f",A);

}
