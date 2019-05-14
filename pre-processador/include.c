#include<stdio.h>
#include<stdlib.h>

#define maior(a,b) ((a>b) ? a: b)
#define produto(a,b) (a*b)
#define diferenca(a,b)(a-b)
#define divisao(a,b) (a/b)


int main(void)
{
	int a = 3;
	int b = 60;
	printf("%d",produto(a,b));
	
	return EXIT_SUCCESS;
}
