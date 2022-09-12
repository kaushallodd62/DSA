/*
Generate the first n terms of the sequence
1 2 4 8 16 32 64 128 ...
without using multiplication.
*/

#include<stdio.h>

int main()
{
	int i, n, next_term, curr_term;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	i = 0; curr_term = 1;
	while (i < n)
	{
		printf("%d ", curr_term);
		next_term = curr_term + curr_term;
		curr_term = next_term;
		i = i+1;
	}
	printf("\n");
	return 0;
}