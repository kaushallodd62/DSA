#include<stdio.h>
#include<math.h>

int main()
{
	float n, g1, g2;
	printf("Enter the value of n: ");
	scanf("%f", &n);
	g2 = n/2;
	do
	{
		g1 = g2;
		g2 = (g1 + n/g1)/2;
	}
	while (fabs(g1-g2) > 0.0001);
	printf("Square Root of %f is %f\n", n, g1);
	return 0;
}