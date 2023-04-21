/*
    Testing if - else flow
    Juan Avelino
    2023/04/18
*/
#include <stdio.h>

int main(void)
{
    int speed;
    printf("Enter the speed: ");
    scanf("%d", &speed);

    if (speed < 65) {
        printf("You are going under the speed limit.\n");
    } else {
        printf("You are going over the speed limit.\n");
    }
    return 0;

}