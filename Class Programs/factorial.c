#include<stdio.h>

int main()				// N-1 Iterations.
{
	int i, n;
	long long int fact;
	printf("Enter value of n: ");
	scanf("%d",&n);
	if (n == 0)
		printf("0! = 1\n");
	else
	{
		i = 1; fact = 1;
		while (i < n)
		{
			i = i+1;
			fact = fact * i;
		}
		printf("%d! = %lld\n", n, fact);
	}
	return 0;
}