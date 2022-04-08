#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int a, b;

int main()
{
	srand(time(NULL));
	int k, dim, vetor[20], s[20];
	
	for(k=0; k<20; k++)
	{
		vetor[k]=rand()%10+1;
		printf("\n v[%d] = %d", k+1, vetor[k]);
	}
	dim = sizeof(vetor)/sizeof(int);
	a=3;
	b=12;
//	printf("\n a = %d\n b = %d", a, b);
//	printf("\n O maior numero e %d.", maior(a,b));
//	troca(&a,&b); // troca por referencia
//	printf("\n a = %d\n b = %d", a, b);
//	trocaAB(); // aqui não há args pois eles são globais
//	printf("\n a = %d\n b = %d", a, b);
	binario(vetor, s, 10, dim);
	for(k=0; k<20; k++)
	{
		printf("\n saida[%d] = %d", k+1, s[k]);
	}
	return 0;
}

trocaAB()
{
	int aux;
	
	aux=a;
	a=b;
	b=aux;
}

binario(int orig[], int saida[], int num, int dim)
{
	int k;
	
	for(k=0; k<dim; k++)
	{
		if(orig[k]==num)
			saida[k]=1;
		else
			saida[k]=0;
	}
}
