#include<stdio.h>
#include<stdlib.h>

#define SIZE 5001

void offset(char *,unsigned int);

int main(int argc, char *argv[])
{
	char string[SIZE] = {0};
	unsigned int offset_value;
	
	printf("Insira uma string: ");
	scanf("%s",string);
	printf("Insira o valor de deslocamento: ");
	scanf("%u",&offset_value);
	
	offset(string,offset_value);
	puts(string);
	
	return EXIT_SUCCESS;
}

void offset(char *str, unsigned int position)
{
	while(*str++)
	{
		str += position;
	}
}
