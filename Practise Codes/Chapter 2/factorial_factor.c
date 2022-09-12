/*
Design an algorithm which, given some integer n, finds the largest factorial number 
present as a factor in n.
*/

#include<stdio.h>

/*_Bool fact_check(int n)
{
	int i = 2;
	while (n > 1 && n%i == 0)
	{
		n = n/i;
		i++;
	}
	if (n == 1)
		return 1;
	else 
		return 0;
}
int main()
{
	int i, n, flag;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	i = n; flag = 0;
	while (i>0 && flag == 0)
	{
		if(n%i == 0 && fact_check(i))
			flag = 1;
		i = i-1;
	}
	printf("%d\n", i+1);
	return 0;
}*/

int main()
{
	int i, n, fact, ans;
	scanf("%d", &n);
	i = 1; fact = 1;
	while(fact <= n)
	{
		if (n % fact == 0)
			ans = fact;
		i++;
		fact = fact*i;
	}
	printf("%d\n", ans);
	return 0;
}