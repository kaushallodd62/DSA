#include<stdio.h>

int main()
{
	unsigned int base_num, dec_num, base, factor, n;
	printf("Enter the base(< 10): ");
	scanf("%d", &base);
	printf("Enter the base number: ");
	scanf("%d", &base_num);
	n = base_num; factor = 1; dec_num = 0;
	while (n > 0)
	{
		dec_num = dec_num + (n%10)*factor;
		factor = factor * base;
		n = n / 10;
	}
	printf("The decimal equivalent of %d is %d\n", base_num, dec_num);
	return 0;
}