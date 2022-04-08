#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	
	printf("\n a = ");
	scanf("%d", &a);
	
	printf("\n b = ");
	scanf("%d", &b);

	printf("\n mdc(%d,%d) = %d\n", a, b, MDC(a,b));
	printf("\n mmc(%d,%d) = %d\n", a, b, MMC(a, b));	
	
	return 0;
}

int MDC(int x, int y)
{
	int k, max_div, aux;
	
	if(y<x)
	{
		aux=x;
		x=y;
		y=aux;
	}

	max_div=1;
	
	for(k=2; k<=x; k++)
	{
		if(x%k==0&&y%k==0)
		max_div=k;
	}
	return max_div;
}

int MMC(int x, int y)
{
	return (x*y)/MDC(x,y);
}
