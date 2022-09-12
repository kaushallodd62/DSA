#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, c, d;
	printf("Enter four numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a > b)
		if (a > c)
			if (a > d)
				printf("%d is the largest number\n", a);
			else 
				printf("%d is the largest number\n", d);
		else 
			if (c > d)
				printf("%d is the largest number\n", c);
			else 
				printf("%d is the largest number\n", d);
	else
		if (b > c)
			if (b > d)
				printf("%d is the largest number\n", b);
			else 
				printf("%d is the largest number\n", d);
		else 
			if (c > d)
				printf("%d is the largest number\n", c);
			else 
				printf("%d is the largest number\n", d);
	return 0;
} 