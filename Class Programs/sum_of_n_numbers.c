#include<stdio.h>
#include<stdlib.h>

/*int main()				// N Additions.
{
	int i, n, num, sum;
	printf("Enter value of n: ");
	scanf("%d",&n);
	printf("Enter the n numbers\n");
	i = 0; sum = 0;
	while (i < n)
	{
		scanf("%d",&num);
		sum = sum+num;
		i = i+1;
	}
	printf("Sum = %d\n", sum);
	return 0;
}*/

int main()					// N-1 Additions.
{
	int i, n, num, sum;
	printf("Enter value of n: ");
	scanf("%d",&n);
	printf("Enter the n numbers\n");
	scanf("%d",&num);
	i = 1; sum = num;
	while (i<n)
	{
		scanf("%d",&num);
		sum = sum+num;
		i = i+1;
	}
	printf("Sum = %d\n", sum);
	return 0;
}