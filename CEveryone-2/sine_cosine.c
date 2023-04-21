/*
    Calculates and prints cosine and sine values from 0 to 1
    Juan Avelino
    2023/04/18
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Table of cosine and sine\n\n");

    printf("Value\t|\tCosine\t|\tSine\n");

    for (double i = 0.0; i <= 1; i += 0.1) { // This will print the cosine and sine values of 0 to 1 in steps of 0.1
        printf("%f\t|\t%f\t|\t%f\n", i, cos(i), sin(i));
    }

    return 0;
}