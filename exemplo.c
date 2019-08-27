#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#include"ntyamba.h"

int main(void)
{
	//char *vector = "Roddas Cabral";
	//leftRotation(vector,strlen(vector));
	int numero;
	printf("Insira um número : ");
	scanf("%d",&numero);
	printf("%d possui %d dígitos ..\n",numero,number_digits(numero));
	int *vector = split_number(numero);
	printArray(vector,number_digits(numero),sizeof(int));
	free(vector);
	
	return EXIT_SUCCESS;
}
