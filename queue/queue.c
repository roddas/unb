#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int elemento;
	struct node *proximo;
}node;

node *fileira;

node *new_node(int );
void error(void);
void init(void);
void push(int );
int pop(void);
short int empty(void);
void release(void);

int main(void)
{	
	int n;
	
	init();
	while(scanf("%d",&n) != EOF)
		push(n);
	
	while(!empty())
		printf("%d ",pop());
		
	release();
	return EXIT_SUCCESS;
}
void init(void)
{
	fileira = new_node(-1);
	fileira->proximo = fileira;
}
node *new_node(int elemento)
{
	node *novo = (node *)malloc(sizeof(node));
	novo->elemento = elemento;
	novo->proximo = NULL;
	return novo;
}
void push(int elemento)
{
	node *novo = new_node(elemento);
	
	if(!novo)
		error();
	
	novo->proximo = fileira->proximo;
	fileira->proximo = novo;
	fileira->elemento = elemento;
	fileira = novo;
}
void error(void)
{
	perror("");
	printf("Insira qualquer tecla para sair ..\n");
	scanf("%*c");
	exit(EXIT_FAILURE);
}
int pop(void)
{
	node *lixo = fileira->proximo;
	fileira->proximo = lixo->proximo;
	int ret = lixo->elemento;
	free(lixo);
	return ret;
}
short int empty(void)
{
	return fileira->proximo == fileira;
}
void release(void)
{
	free(fileira);
}
