#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rotacionar(char *,int);

const int SIZE = 255;

int main(void)
{
	char string[SIZE];
	printf("Insira uma string: ");
	fgets(string,SIZE,stdin);
	
	rotacionar(string,strlen(string));
	puts(string);
	
	return 0;
}

void rotacionar(char *string,int tamanho)
{
	int a;
	char *tmp = (char *)calloc(tamanho,sizeof(char));
	tmp[0] = string[tamanho-2];
	
	for(a = 0;a < tamanho-2;a++)
	{
		tmp[a+1] = string[a];
	}
	
	strcpy(string,tmp);
	free(tmp);
}
