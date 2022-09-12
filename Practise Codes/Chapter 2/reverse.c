#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, num, rev;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	num = abs(n); rev = 0;
	while (num > 0)
	{
		rev = rev*10 + num%10;
		num = num/10;
	}
	if (n > 0)
		printf("Reversed Number: %d\n", rev);
	else
		printf("Reversed Number: %d\n", rev*-1);
	return 0;
}