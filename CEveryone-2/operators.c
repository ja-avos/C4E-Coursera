/*
    Operators in C
    Juan Avelino
    2023/04/17
*/
#include <stdio.h>

int main(void)
{
    int a = 5, b = 2, c = 3, d = 4, e = 5, f = 6;
    int result;

    result = a - b; // subtraction
    printf("a - b = %d", result);

    result = b * c; // multiplication
    printf("b * c = %d", result);

    result = a / c; // division
    printf("a / c = %d", result);

    result = a + b * c; // precedence
    printf("a + b * c = %d", result);

    printf("a * b + c * d = %d", a * b + c * d);

    return 0;
}