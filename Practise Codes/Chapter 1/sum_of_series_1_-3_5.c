/*
Develop an algorithm to compute the sum of the first n terms (n>=1)
of the series 
1 -3 5 -7 9 -11
*/

#include<stdio.h>

int main()
{
	int i, n, sum, sign, term;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	i = 1; sum = 1; term = 1; sign = 1;
	while (i < n)
	{
		term += 2;
		sign *= -1;
		sum += term*sign;
		i = i+1;
	}
	printf("Sum = %d\n", sum);
	return 0;
}