#include<stdio.h>
#include<math.h>

int main()
{
	float num, prod = 1, g1, g2, mean;
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the n numbers:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &num);
		prod = prod * num;
	}
	g2 = prod/2;
	do 
	{
		g1 = g2;
		g2 = (g1*(n-1) + prod/pow(g1, n-1))/n;
	}
	while (fabs(g1-g2) > 0.0001);
	mean = g1;
	printf("The geometric mean is %f\n", mean);
	return 0;
}