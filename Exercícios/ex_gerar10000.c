#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, f1=1, f2=1, arr[20], n;
	
	srand(time(NULL));
	
	for (i=0; i<20; i++)
	{
		arr[i] = rand() % 10 + 1;
		
		printf("%d  ", arr[i]);
		
		if (arr[i]==arr[i-1])
		{
			f2++;
		}
		else if(f2>f1)
		{
			f1=f2;
			f2=0;
			n = arr[i-1];
		}
	}\
	
	printf("\nO numero que foi gerado mais vezes consecutivamente foi %d e a sua frequencia foi %d.\n", n, f1);
	
	return 0;
}

