#include<stdio.h>
// Factorial(n) 	= 1 		if n == 1
// 		= n*Factorial(n-1)	Otherwise
long fact(long n)
{
	if(n==0) return 1;
	else return fact(n-1) * n;
}

void main()
{
	long a;
	scanf("%ld",&a);
	printf("factorial of %ld is %ld\n", a, fact(a));
}
