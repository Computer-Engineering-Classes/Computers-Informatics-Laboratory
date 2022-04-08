#include <stdio.h>
#include <math.h>

int main()
{
	float a=3, b=11, c=2, d=1;
	
	float res, res2;
	
	res = a/b + 1;
	printf("\na/b + 1 = %f\n", res);

	res = (a+b)/(c-d);
	printf("\n(a+b)/(c-d) = %f\n", res);
	
	res = (a+b/c)/(d-b/c);
	printf("\n(a+b/c)/(d-b/c) = %f\n", res);

	res = a+b/(c-d);
	printf("\na+b/(c-d) = %f\n", res);
	
	res = (a+b)*(c/d);
	printf("\n(a+b)c/d = %f\n", res);
	
	res = pow(pow((a+b), c), d);
	printf("\n((a+b)^c)^d = %f\n", res);
	
	res = (-b+sqrt(pow(b, 2)-4*a*c))/(2*a);
	res2 = (-b-sqrt(pow(b, 2)-4*a*c))/(2*a);
	
	printf("\n (-b+-sqrt(b^2-4ac)/2a = %f ou %f\n", res, res2);
	
	return 0;
}
