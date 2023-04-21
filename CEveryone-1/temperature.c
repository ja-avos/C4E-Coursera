/*
    Converts from Farenheit to Celsius
    Juan Avelino
    2023/04/17
*/
#include <stdio.h>

int main() {

    int farenheit, celsius;

    printf("Please enter the temperature in Farenheit as an integer: ");
    scanf("%d", &farenheit);
    celsius = (farenheit - 32) * 5 / 9; // This part makes the calculation for the conversion
    printf("The temperature in Celsius is %d from %d Farenheit.\n", celsius, farenheit);

    return 0;
}