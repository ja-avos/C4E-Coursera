/*
    Merge sort algorithm
    Juan Avelino
    2023/04/19
*/
#include <stdio.h>

// Print int array

void print_array(int size, int array[]) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int array_a[], int array_b[], int array_c[], int m) 
{
    int i = 0, j = 0, k = 0, n = m;

    while(i < m && j < n) {
        if (array_a[i] < array_b[j])
            array_c[k++] = array_a[i++];
        else
            array_c[k++] = array_b[j++];
    }

    while(i < m) {
        array_c[k++] = array_a[i++];
    }

    while(j < n) {
        array_c[k++] = array_b[j++];
    }
}

void mergesort(int array[], int size) {
    int j, k;
    int ordered[size];

    for (k = 1; k < size; k *= 2)
    {
        for (j = 0; j < size - k; j += 2 * k)
        {
            merge(array + j, array + j + k, ordered + j, k);
        }
        for (j = 0; j < size; j++)
        {
            array[j] = ordered[j];
        }
    }
    
}

int main() {

    const int SIZE = 20;
    int array_a[] = {1, 3, 5, 7, 9};
    int array_b[] = {2, 4, 6, 8, 10};
    // Array of 20 random numbers
    int array_d[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int array_c[10];
    int m = 5, n = 5;

    // merge(array_a, array_b, array_c, m, n);
    mergesort(array_d, SIZE);
    print_array(SIZE, array_d);

    return 0;
}