#include <stdio.h>
// testing header file
#include "fact.c"

int main()
{
    printf("Enter a number \n");
    int n;
    scanf("%d",&n);

    printf("factorial of %d is %d",n,factorial(n));
}