#include<stdio.h>

// FIB(0) = 0
// FIB(1) = 1
// FIB(n) = FIB(n-1) + FIB(n-2)

long fib(long input)
{
	if(input == 0) return 0;
	else if(input == 1) return 1;
	else return fib(input-1)+fib(input-2);
}

long fib_loop(long input)
{
	int i,temp;
	int first = 0, second = 1, third;
	if(input==0) return 0;
	else if(input==1) return 1;
	for(i=2;i<=input;i++)
	{
		third = first+second;
		first = second;
		second = third;
	}
	return third;
}

void main()
{
	long a;
	scanf("%ld",&a);
	printf("[Using loop] fibonacci of %ld is %ld\n", a, fib_loop(a));
	printf("[Using Recursion] fibonacci of %ld is %ld\n", a, fib(a));
}
