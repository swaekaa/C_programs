#include <stdio.h>
int main()
{
int a = 10, b = 8, c = 6;
int x = a++ * b-- + c++;
printf(" \n x = %d \n a =%d \n b = %d \n c =%d \n", x, a, b, c);
int z = (a ==b) + (++b);
printf("\n z = %d \n ", z);
return 0;
}
