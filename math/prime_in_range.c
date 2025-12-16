#include<stdio.h>
int main()
{
    printf("this program is to check the prime numbers in a given range\n");
    printf("enter the first number of the range\n");
    int x,y,fact,count;
    count=0;
    fact=1;
    scanf("%d",&x);
    printf("enter second number of the range\n");
    scanf("%d",&y);
    printf("the prime numbers from %d to %d are: \n",x,y);

    for(;x<=y;x++)
    {
        for(fact=1;fact<=x;fact++)
        {
            if(x%fact==0)   
            {
                count++;
            }
            
        }
        if(count==2)
           {
             printf(" %d \n",x);  
           } 
            count=0;
    }
    return 0;
}