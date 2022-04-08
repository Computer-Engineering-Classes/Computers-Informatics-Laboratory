#include <stdio.h>

int main()
{
	int deck[5]=[0,0,0,0];
	int i=0, j=0;
	//for(i=0; i<5; i++)
//	{
		for(j=0; j<5; j++)
		{
		//	deck/*[i]*/[j]=0;
			printf("%d", &deck/*[i]*/[j]);
		}
//	}
}
