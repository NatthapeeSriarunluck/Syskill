#include<stdio.h>
#include<stdlib.h> //This is the library that contains qsort

int compare_function_large_to_small(const void *a, const void *b)
{
	// if a<b return 1
	if((*(int*)a) < (*(int*)b)) return 1;
	// else if a==b return 0
	else if((*(int*)a) == (*(int*)b)) return 0;
	// else return -1
	else return -1;
}


int compare_function_small_to_large(const void *a, const void *b)
{
	// if a<b return -1
	if((*(int*)a) < (*(int*)b)) return -1;
	// else if a==b return 0
	else if((*(int*)a) == (*(int*)b)) return 0;
	// else return 1
	else return 1;
}

void main()
{	
	int a[8] = {4,1,6,1,7,4,63,6257};
	int (* comp)(const void *, const void *) = compare_function_large_to_small;
	//int (* comp)(const void *, const void *) = compare_function_small_to_large;
	//Task: Sort a using qsort
	printf("Before Sorting: a = [");
	for(int i=0; i<8;i++)
	{
		printf("%d ,", a[i]);
	}
	printf("]\n");
	//int (*compar)(const void *, const void *)
	qsort(a, 8, sizeof(int),comp);
	printf("After Sorting: a = [");
	for(int i=0; i<8;i++)
	{
		printf("%d ,", a[i]);
	}
	printf("]\n");


}
