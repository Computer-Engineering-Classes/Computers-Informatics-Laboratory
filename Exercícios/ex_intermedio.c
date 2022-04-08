#include <stdio.h>

int main()
{
	float a, b, c;
	
	printf("\nInsira 3 valores: ");
	scanf("%f %f %f", &a, &b, &c);
	
	if ((a<=b && a>=c)||(a>=b && a<=c))
		printf("\nO valor intermedio e' %f.\n", a);
	
	else if ((b<=a && b>=c)||(b>=a && b<=c))
		printf("\nO valor intermedio e' %f.\n", b);
	
	else
		printf("\nO valor intermedio e' %f.\n", c);
	
	return 0;
}
