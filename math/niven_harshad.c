/**
 * Let's take a positive integer as an example, say 18. 
 * The sum of its digits is 1 + 8 = 9. Now, if 18 is divisible by 9, 
 * it is classified as a Niven Number. In this case, 18 is indeed divisible by 9, making it a Niven Number.
 * 
 * */
  #include<stdio.h>
int main()
{
    int n,r=0,sum=0;
    printf("enter a no.");
    scanf("%d", &n);
    int temp=n;
    while(n!=0)
    {
        r=n%10;
        sum=sum+r;
        n/=10;
    }
    if(temp%sum==0)
    printf( "%d is a Niven Number.", temp);
    else
    printf("%d is not a Niven Number.", temp);
    return 0;

}
 