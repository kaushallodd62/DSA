#include<stdio.h>

int main()
{
	unsigned int base, factor, dec_num, base_num, n;
	printf("Enter the decimal number: ");
	scanf("%d", &dec_num);
	printf("Enter the base(< 10): ");
	scanf("%d", &base);
	n = dec_num; factor = 1; base_num = 0;
	while (n > 0)
	{
		base_num += (n%base)*factor;
		factor *= 10;
		n /= base;
	}
	printf("The base %d equivalent of %d is %d\n", base, dec_num, base_num);
	return 0;
}