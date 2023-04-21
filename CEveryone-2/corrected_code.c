#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
    double radius; // Changed int to double
    printf("Enter radius:");
    scanf("%lf", &radius); // Changed %d to %lf
    printf("volume is : %lf \n\n", 4 * PI *radius*radius*radius/3 ); // Changed %d to %lf
    return 0;
}