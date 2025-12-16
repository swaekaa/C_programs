#include<stdio.h>
int main()
{ 
    int x;
    int y;
    int sum;

    printf("Enter a number");
    scanf("%d",&x);
    printf("Enter another number");
    scanf("%d",&y);
    sum = x+y;
    printf("the sum of %d and %d is = %d",x,y,sum);
    return 0;

}