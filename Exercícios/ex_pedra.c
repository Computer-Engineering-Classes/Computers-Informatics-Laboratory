#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	char jjog[7], jcpu[7], res[9];
	int jog;
	
	srand(time(NULL)); // define a semente do algoritmo de aleatorios como o instante em que corre o programa //
	int cpu=rand()%3+1; // resto da divisao inteira de um numero aleatorio mais 1 //
	
	printf("\nEscolha a sua jogada: pedra(1), papel(2) ou tesoura(3): ");
	scanf("%d", &jog);
	
	if(jog==cpu)
		{
		strcpy(res, "empataste");
		}
	
	else if((jog==1 && cpu==2)||(jog==2 && cpu==3)||(jog==3 && cpu==1))
		{
		strcpy(res, "perdeste");
		}
	
	else
		{
		strcpy(res, "ganhaste");
		}
		
	switch (jog)
	{
		case 1:
		strcpy(jjog, "pedra");
		break;
		
		case 2:
		strcpy(jjog, "papel");
		break;
		
		case 3:
		strcpy(jjog, "tesoura");
		break;
	}
	
	switch (cpu)
	{
		case 1:
		strcpy(jcpu, "pedra");
		break;
		
		case 2:
		strcpy(jcpu, "papel");
		break;
		
		case 3:
		strcpy(jcpu, "tesoura");
		break;
	
	}
	printf("\nTu jogaste %s e a CPU jogou %s, logo %s.\n", jjog, jcpu, res);
	
	return 0;
}
