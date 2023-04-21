/*
    Testing arrays in C
    Juan Avelino
    2023/04/18
*/

#include <stdio.h>

int main() {
    int i;
    int array[8];
    array[100] = 50;
    for (i = 0; i < 10; i++) {
        array[i] = i;
    }
    for (i = 0; i < 10; i++) {
        printf("%d", array[i]);
    }
    printf("The number at pos 100 is %d\n", array[100]); // This reads memory outside the array
    printf("The number at pos 1000 is %d\n", array[1000]); // This reads memory outside the array
    printf("The number in array addr is %d\n", array);

    return 0;
}