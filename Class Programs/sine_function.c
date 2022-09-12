#include<stdio.h>
#include<math.h>
#define PI 3.14159

int main()
{
	int i;
	float x, x_rad, x2, term, error, sine;
	printf("Enter the value of x in degrees: ");
	scanf("%f", &x);
	x_rad = x*PI/180;
	i = 1; sine = x_rad; x2 = x_rad*x_rad; term = x_rad; error = 0.000001;
	while (fabs(term) > error)
	{
		i = i+2;
		term = -term * x2/(i*(i-1));
		sine = sine + term;
	}
	printf("sin(%.2f) = %f\n", x, sine);
	return 0;
}