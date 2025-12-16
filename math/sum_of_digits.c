#include<stdio.h>
int main()
{
    printf("enter a 4 digit number\n");
    int n,r; 
    int sum=0;
    scanf("%d",&n);
    r=n/1000;
    sum=sum+r;
    r=n%1000/100;
    sum=sum+r;
    printf("\nthe hundreds place is %d",r);
    n=n-n%1000;
    r=n/10;
    sum=sum+r;
    printf("\nthe tens place is %d",r);
    n=n-n%10;
    sum=sum+n;
    printf("\nThe ones place is %d",n);
    
    return 0;
}


    

    