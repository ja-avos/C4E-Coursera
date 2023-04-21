/* Program for calcultaing circle area
    Juan Avelino
    2023/04/17
*/

#include <stdio.h>

#define PI 3.14159

int main()
{
    double area = 0.0, radius = 0.0;
    printf("Enter radius: ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("Radius of %lf meters; Area is %lf sq. meters\n", radius, area);
    return 0;
}