/*
    Program for conversion of miles to kilometers
    Juan Avelino
    2023/04/17
*/
#include <stdio.h>

int main()
{
    int miles = 26, yards = 385;
    double kilometers;

    kilometers = 1.609 * (miles + yards / 1760.0);

    printf("\nA marathon is %lf kilometers.\n\n", kilometers);
    return 0;
}