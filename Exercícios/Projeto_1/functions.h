#include <stdio.h>
#include <stdlib.h>

int maior(int x, int y)
{
	if(x>y)
	{
		return x;	
	}
	else
	return y;
}

troca(int *x, int *y)
{
	int aux;
	
	aux=*x;
	*x=*y;
	*y=aux;
}
