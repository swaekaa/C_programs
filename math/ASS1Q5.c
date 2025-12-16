/**
1. Declare a variable named ‘principal’ of type ‘double’.
2. Declare a variable named ‘rate’ of type ‘float’
3. Declare a variable ‘duration’ of type ‘int’.
4. Read the values of all the variables declared above from user using scanf function
5. Compute the interest as ‘principle’ time ‘rate’ times ‘duration’
6. Display the values of all four variables on different lines using single printf() statement
**/ 
#include<stdio.h>
int main()
{
    double principal;
    float rate;
    int duration;
    float interest;
    printf("enter the amount of principal\n");
    scanf("%lf",&principal);
    printf("enter the value of rate\n");
    scanf("%f",&rate);
    printf("enter the amount of duration\n");
    scanf("%d",&duration);
    interest = (principal*rate*duration)/100;
    printf("principal= %lf \n",principal);
    printf("rate= %f \n",rate);
    printf("duration= %d \n",duration);
    printf("interest= %f \n",interest);
    return 0;

    
}//50.49