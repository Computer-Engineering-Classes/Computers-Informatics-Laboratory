#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x, k, i=0;
	
	while (x<1 || x>10)
	{
		printf("\nInsira um valor inteiro de 1 a 10: ");
		scanf("%d", &x);
	}
	srand(time(NULL));
	
	printf("\n");
	do
	{
		k = rand() % 10 + 1;
		printf("%d  ", k);
		i++;
	} while (k != x);
	
	printf("\n\nForam necessarias %d tentativas para gerar %d.\n", i, x);

	return 0;
}
