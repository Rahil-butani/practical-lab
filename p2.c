#include <stdio.h>

int main(void)
{
    float length = 90;
    float breadth = 70;
    printf("RAHIL-25CE011");
    printf("The Length of the track is %.fm and the breadth is %.fm\n", length, breadth);
    float area = length * breadth;
    float perimeter = 2 * (length + breadth);
    printf("The area of your garden is %.2f\n", area);
    printf("The perimeter of your garden is %.2f\n", perimeter);
    //Supposing that the cost of fencing the garden is Rs.100 and grass laying cost is Rs.300
    float fencing = 100 * perimeter;
    float grassing = 300 * area;
    printf("The cost of fencing your garden is Rs.%.2f\n", fencing);
    printf("The cost for gracing your garden is Rs.%.2f\n", grassing);
}