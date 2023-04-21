/*
    Converts miles and yards to kilometers
    Juan Avelino
    2023/04/17
*/
#include <stdio.h>

int main(void)
{
    int miles, yards;
    double kilometers;

    printf("Enter miles: ");
    scanf("%d", &miles);
    printf("Enter yards: ");
    scanf("%d", &yards);

    kilometers = 1.609 * (miles + yards / 1760.0);

    printf("%d miles and %d yards are %lf kilometers", miles, yards, kilometers);

    return 0;

}