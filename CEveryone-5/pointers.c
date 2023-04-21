/*
    Testing pointers in C
    Juan Avelino
    2023/04/18
*/

#include <stdio.h>

int main() {
    int i = 10;
    int *p = &i;
    printf("The value of i is %d", i);
    printf("The value of i is %d", *p);
    printf("The address of i is %p", &i);
    printf("The address of i is %p", p);
    printf("The address of p is %p", &p);
    printf("The value of p is %d", p);
    return 0;
}