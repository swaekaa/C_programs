#include<stdio.h>
#include<math.h>
int main()
{
   // math function are from the <math.h> library
    printf("%f \n", pow(3,4)); // prints 3 raise to 4 
    printf("%f\n", sqrt(49)); // prints square root of 49
    printf("%f\n", ceil(33.45667)); // roinds of to the greater number
    printf("%f\n", floor(34.5432)); // rounds of to the lesser number
    float x=34.4;
    printf("%f\n", abs(x));//	Returns the absolute value of x
    printf("%f\n", acos(x));//Returns the arccosine of x
    printf("%f\n", asin(x));//Returns the arcsine of x
    printf("%f\n", atan(x));//Returns the arctangent of x
    printf("%f\n", cbrt(x));//Returns the cube root of x
    printf("%f\n", cos(x));//	Returns the cosine of x
    printf("%f\n", exp(x));//Returns the value of Ex
    printf("%f\n", sin(x));//Returns the sine of x (x is in radians)
    printf("%f\n", tan(x));//Returns the tangent of an angle
   
    return 0;    
}