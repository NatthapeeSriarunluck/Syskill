#include <stdio.h>
#include <stdlib.h> //This is the library thatcontains sort

int compare_function(const void *a, const void *b)
{
        if ((int *)a < (int *)b)
    {
        return -1;
    }
    else if ((int *)a > (int *)b)
    {
        return 1;
    }
    else
        return 0;
}

void main()
{
    int a[8] = {4, 1, 6, 1, 7, 4, 63, 6257};
    int (*comp)(const void *, const void *) = compare_function;
    // Task: Sort a using qsort
    printf("Before Sorting: a = [");
    for (int i = 0; i < 8; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("]\n");
    qsort(a, 8, sizeof(int), compare_function);
    printf("After Sorting: a = [");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ,", a[i]);
    }
    printf("]\n");
}