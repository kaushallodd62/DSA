#include<stdio.h>

int main()
{
	int min, max, n, i, j, arr[100];
	printf("Enter min and max bounds: ");
	scanf("%d %d", &min, &max);
	printf("Enter the number n: ");
	scanf("%d", &n);
	i = max; j = 0;
	while (n != 0 && i >= min)
	{
		if (n-i >= 0)
		{
			n = n-i;
			arr[j]=i;
			j++;
		}
		i--;
	}
	if (n == 0)
	{
		for (i = 0; i < j; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("Not possible to find numbers in the range which add upto n");
	printf("\n");
	return 0;
}