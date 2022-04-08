#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
	int num1, num2, n, i;
	
	printf("\n n = ");
	scanf("%d", &num1);
	
	n = ndigit(num1);
	int arr[n];
	num2 = num1;
	
	for(i=n-1; i>=0; i--)
	{
		arr[i] = num1%10;
		num1=floor(num1/10.0);
	}
	
	for(i=0; i<n; i++)
	{
		if(arr[i]!=arr[n-1-i])
		{
			printf("\n O numero %d nao e' uma capicua.\n", num2);
			break;
		}
		else if(i==n-1)
			printf("\n O numero %d e' uma capicua.\n", num2);
	}
	
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
