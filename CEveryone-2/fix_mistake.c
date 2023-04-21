#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

int main(void)
{ 
    double interval;
    int i;
    for(i = 0; i < 30; i++)
    {
        interval = i/10.0;
        printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval))); //Changed abs to fabs for absolute value for float numbers
    }

    printf("\n+++++++\n");
    
    return 0;
}