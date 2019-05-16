#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>


unsigned int fatorial(unsigned int);
void rotacionar(char *,unsigned int);

const int SIZE = 255;

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	char string[SIZE];
	printf("Insira uma string: ");
	fgets(string,SIZE,stdin);
	
	unsigned int tamanho = strlen(string) -1;
	string[tamanho] = 0;
	tamanho = fatorial(tamanho);
	
	printf("A string '%s' possui %u permutações possíveis ..\n",string,tamanho);
	
	int contador;
	for(contador = 0; contador < tamanho;contador++)
	{
		rotacionar(string,tamanho+1);
		printf("Permutação %d : %s\n",contador+1,string);
	}
	
	return 0;
}

void rotacionar(char *string,unsigned int tamanho)
{
	int a;
	char *tmp = (char *)calloc(tamanho,sizeof(char));
	tmp[0] = string[tamanho-2];
	
	for(a = 0;a < tamanho-1;a++)
	{
		tmp[a+1] = string[a];
	}
	
	strcpy(string,tmp);
	free(tmp);
}


unsigned int fatorial(unsigned int valor)
{
	int ret = 1;
	
	int contador;
	for(contador = valor; contador > 0; contador--)
	{
		ret *= contador;
	}
	
	return ret;
}
