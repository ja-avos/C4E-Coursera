/*
    Testing escape characters
    Juan Avelino
    2023/04/17
*/
#include <stdio.h>

int main(void)
{
    printf("Hello\tWorld!");
    printf("Hello World! \b\b");
    printf("Hello World! \r");
    printf("Hello World! \a");
    printf("Hello World! \v");
    printf("Hello World! \f");
    printf("Hello World! \?");
    printf("Hello World! \'");
    printf("Hello World! \"");
    printf("Hello World! \\");
    return 0;
}
