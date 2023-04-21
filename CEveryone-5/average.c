/*
    Computes the average weight for a population of elephant seals
    Juan Avelino
    2023/04/19
*/
#include <stdio.h>

/*
    Calculates the average of an int array
*/
double average(int size, int array[])
{

    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
};

int main(void)
{
    #define SIZE 1000 // Number of elephants inside the file

    int weights[SIZE];

    int i = 0;

    while (scanf("%d", &weights[i]) != EOF && i < SIZE)
    {
        i++;
    }

    printf("The average weight is %lf", average(i, weights));
    
}