/*  Take three numbers as input and print their sum.
    Juan Avelino
    2023/04/17
*/

#include <stdio.h>

int main(void)
{
    float a, b, c, sum;
    printf("Enter three numbers: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("a = %f, b = %f, c = %f\n", a, b, c);
    sum = a + b + c;
    printf("Sum = %f\n", sum);
    return 0;
}