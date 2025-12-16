#include<stdio.h>
#include<math.h>
int main()
{

    printf("this program is to check if the input number is an armstrong number or not\n");
    int n,rd,rd1,c=0,sum=0;
    printf("enter a positive integer number\n");
    scanf("%d",&n);
    int temp=n;
    int nn=n;

    while(n!=0)
    {
        rd=n%10;
        c++;
        n=n/10;
    }

    while(temp!=0)
    {
        rd1=temp%10;
        sum=sum+pow(rd1,c);
        temp=temp/10;
    }

    if(sum==nn)
    printf("%d is an armstrong number\n",nn);
    else
    printf("%d is not an armstrong number\n",nn);

    return 0;

}