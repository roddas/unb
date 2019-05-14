#include<stdio.h>
#include<stdlib.h>

int fibonacci(int);

int main(void)
{
	int numero,contador, i = 0;
	
	printf("Insira um número : ");
	scanf("%d",&numero);
	
	for(contador = 1; contador <= numero;contador++)
	{
		printf("%d ",fibonacci(i));
		i++;
	}
	return 0;
}

int fibonacci(int numero)
{
	if(numero == 0)
		return 0;
	else if(numero == 1 || numero == 2)
		return 1;
	else return (fibonacci(numero-1) + fibonacci(numero-2));
}
