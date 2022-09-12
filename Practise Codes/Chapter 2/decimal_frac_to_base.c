#include<stdio.h>

int main()
{
	float base, digit, dec_num, base_num, factor, n;
	printf("Enter the fractional decimal number: ");
	scanf("%f", &dec_num);
	printf("Enter the base(< 10): ");
	scanf("%f", &base);
	n = dec_num; factor = 0.1; base_num = 0;
	while (n < 1 && n > 0)
	{
		n = n * base;
		digit = (int)n;
		base_num = digit*factor + base_num;
		factor = factor * 0.1;
		if (n > 1)
			n = n - digit;
	}
	printf("The base %.0f equivalent of %f is %f\n", base, dec_num, base_num);
	return 0;
}