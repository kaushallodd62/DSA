#include<stdio.h>
#include<math.h>

float power(float x, int n);
int main ()
{
	float num, g1, g2;
	int n;
	printf("Enter the number: ");
	scanf("%f", &num);
	printf("Enter the value of n: ");
	scanf("%d", &n);
	g2 = num/2;
	do 
	{
		g1 = g2;
		g2 = (g1*(n-1) + num/power(g1, n-1))/n;
	}
	while (fabs(g1-g2) > 0.0001);
	printf("The nth root of %f is %f\n", num, g1);
	return 0;
}
 float power(float x, int n)
 {
 	float result = 1;
 	for(int i = 0; i < n; i++)
 		result = result * x;
 	return result;
 }