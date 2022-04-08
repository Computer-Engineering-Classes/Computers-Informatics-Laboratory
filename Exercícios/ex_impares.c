#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, aux;
	int k;
	
	printf("\nInsira dois valores reais: ");
	scanf("%f %f", &a, &b);
	
	printf("\n");
	
	if(a>b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	
	a = ceil(a);
	
	if((int) a % 2 == 0)
	{
		a++;
	}
	
	for (k=a; k<=b; k+=2)
	{
		printf("%d  ", k);
	}
	
	printf("\n");
	
	return 0;
}
