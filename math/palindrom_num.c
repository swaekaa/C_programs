#include<stdio.h>
int main()
{
    int n,r=0,rn=0;
    printf("program ro check if a number is palindrom or not\n");
    printf("Enter the number: ");
    scanf("%d",&n);

    int temp=n;
    while(n!=0)
    {
        r=n%10;
        rn=rn*10+r;
        n/=10;
    }
    if(rn==temp)
    printf("%d is a plaindrome number\n",temp);
    else
    printf("%d is not a plaindrome number\n",temp);
    
    return 0;
}