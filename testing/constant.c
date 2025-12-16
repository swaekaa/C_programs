#include<stdio.h>
int main()
{
    const int x = 5;
    printf("%d", x);
    // x=3; this will give an error as the value of x cannot be modified
    printf("%d",70);// here 70 acts as a constant
    printf("hello");// here 'hello' also acts as a constant 
    return 0;   

}//1 07 02