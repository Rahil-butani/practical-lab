#include<stdio.h>
#include<ctype.h>
#include <stdbool.h>
void main()
{
    int n;
    float *p,*t,x,*h;
    printf("Number of items:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("no items to shot");
    }
    else
    {
    p=(float *)calloc(n,sizeof(float));
    t=p;
    h=p;
    for(int i=1;i<=n;i++)
    {
        printf("enter %d item price: ",i);
        fflush(stdin);
        scanf("%f",p);
        p++;
    }
    p=h;
    for(int i=1;i<=n;i++)
    {
        if(*p<=0 || *p>0)
        {
           continue;
        }
        else
        {
             printf("\n invalid value of price enter numerical value ");
            goto x;
        }
        p++;
    }
        p=t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(*p<*t)
            {
                 x=*p;
                 *p=*t;
                 *t=x;
            }
            t++;
        }
        t=h;
    p++;
    }
      p=h;
      printf("\nsort price");
    for(int i=1;i<=n;i++)
    {
        printf("\n%.2f",*p);
        p++;
    }
    }
    x:printf("\nthis program is made by Rahil Butani");
}
