#include<stdio.h>

int main()
{
	int i, n;
	printf("Enter a number: ");
	scanf("%d", &n);
	i = 2;
	while (n > 1 && n%i == 0)
	{
		n = n/i;
		i++;
	}
	if (n == 1)
		printf("Yes!\n");
	else 
		printf("No!\n");
	return 0;
}