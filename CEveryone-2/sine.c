/*
    Computes the sine of the input
    Juan Avelino
    2023/04/18
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, sine;

    printf("Enter the value of x (radians): ");
    scanf("%lf", &x);

    sine = sin(x); // sin() is a function from math.h

    printf("sin(%lf) = %lf\n", x, sine);

    return 0;
}