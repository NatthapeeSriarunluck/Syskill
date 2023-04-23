#include <stdio.h>
#include <stdlib.h>
// takes in a pointer array, create a new potnier, copy the values, and free up the old pointer

int *extend_Array(int *a, int size);
int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int initial_size = sizeof(array);
    int extendSize = 5;
    int *A = malloc(sizeof(array) / sizeof(int));
    int *B = extend_Array(A, extendSize);
    for (int i = 0; i < initial_size + extendSize; i++) {
        array[i]= i+1;
    } // if there is no errors after this function, the program extends the array properly.
    return 0;
}

int *extend_Array(int *a, int size) // takes in array pointer, and the size you want to incerase by
{
    int *b = (int *)realloc(a, size * sizeof(a));
    free(a);
    return b;
}