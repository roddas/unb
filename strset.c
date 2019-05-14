#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int quantidade;
	printf("Insira a quantidade de caracteres: ");
	scanf("%d",&quantidade);
	
	char *string = (char *)calloc(quantidade,sizeof(char));
	
	strset(string,' ');
	
	return EXIT_SUCCESS;
}
