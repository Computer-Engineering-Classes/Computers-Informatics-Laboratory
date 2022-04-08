#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	
	printf("\n n = ");
	scanf("%d", &n);
	
	printf("\n N.o de digitos de n = %d", ndigit(n));
	printf("\n Primeiro digito de n = %d", prim_d(n));
	printf("\n Ultimo digito de n = %d", ult_d(n));
	printf("\n n encolhido = %d", encolhe(n));

	return 0;
}

int ndigit(int n)
{
	
	int k;
	k=1;
	
	while (n/pow(10, k)>=1)
	{
		k++;
	}
	
	return k;
}

int prim_d(int n)
{
	return (int)floor(n/pow(10, ndigit(n)-1));
}

int ult_d(int n)
{
	return n%10;		
}

int encolhe(int n)
{
	n = n-prim_d(n)*pow(10, ndigit(n)-1);
	return floor(n/10);
}
