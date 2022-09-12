#include <stdio.h>
#include <math.h>

int main() 
{
	int prime=1;
	int i, n;
	printf("Enter a number: ");
	scanf("%d", &n);
	if (n<=1) 
		printf("Entered Number is neither PRIME nor COMPOSITE\n");
	else if (n%2==0 && n!=2)
		printf("Entered Number is NOT PRIME\n");
	else 
	{
		i=3;
		while (i<=sqrt(n) && prime==1) 
		{
			if (n%i==0)
				prime = 0;
			else 
				i = i+2;
		}
		if (prime == 1)
			printf("Entered Number is PRIME\n");
		else 
			printf("Entered Number is NOT PRIME\n");
	}
	return 0;
}