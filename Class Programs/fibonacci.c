#include <stdio.h>

int main()
{
	int i, n, first_term, sec_term;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	i = 2; first_term = 0; sec_term = 1;
	while (i < n)
	{
		i = i+2;
		printf("%d %d ", first_term, sec_term);
		first_term = first_term + sec_term;
		sec_term = first_term + sec_term;
	}
	if (i == n)
		printf("%d %d\n", first_term, sec_term);
	else 
		printf("%d\n", first_term);
	return 0;
}