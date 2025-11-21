#include<stdio.h>
void saving(int);
void main()
{
    int rs=1;
    saving(rs);
}
void saving(int RS)
{
    int month,i,z,saving=RS;
    int x=RS,y=0;
  x:  printf("Enter a month:");
    scanf("%d",&month);
    if(month<=0)
    {
        goto x;
    }
    else
    {
        printf("series : 1 ");
         for(i=1;i<month;i++)
         {
            z=x+y;
            y=x;
            x=z;
            printf(" %d ",z);
     saving=saving+z;
         }

         printf("\n total saving after %d months:%d ",month,saving);

    }
    printf("\nthis program is created by  Rahil Butani");

}
