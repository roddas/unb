#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	struct no *filho;
	struct no *irmao;
	int chave;
	int numero_filhos;
}no;

typedef no* ponteiro;

ponteiro inicializar(int);
ponteiro nova_chave(int);
ponteiro procurar(ponteiro,int);
void inserir(ponteiro,int,int);
void visualizar(ponteiro);
void pad(char,int);
void juntar(ponteiro ,ponteiro );

int main(void)
{
	ponteiro master = inicializar(0);
	ponteiro arvore_par = inicializar(2);
	ponteiro arvore_impar = inicializar(1);
	
	for(int a = 3; a <= 10; a++)
		if(a&1)
			inserir(arvore_impar,a,arvore_impar->chave);
		else
			inserir(arvore_par,a,arvore_par->chave);
	
	visualizar(arvore_impar);
	printf("\nNumero de filhos da árvore de números ímpares : %d\n\n",arvore_impar->numero_filhos);
	
	visualizar(arvore_par);
	printf("\nNumero de filhos da árvore de números pares : %d\n",arvore_par->numero_filhos);
	
	juntar(master,arvore_par);
	juntar(master,arvore_impar);
	
	printf("\nA junção de todas as árvores:\n");
	visualizar(master);
	
	return EXIT_SUCCESS;
}
ponteiro inicializar(int chave)
{
	return nova_chave(chave);
}
ponteiro nova_chave(int chave)
{
	ponteiro novo = (ponteiro)malloc(sizeof(no));
	novo->irmao = novo->filho = NULL;
	novo->numero_filhos = 0;
	novo->chave = chave;
	return novo;
}
void inserir(ponteiro raiz,int chave,int chave_pai)
{
	ponteiro pai = procurar(raiz,chave_pai);
	if(!pai)
		return;
	ponteiro bebe = nova_chave(chave);
	ponteiro ptr = pai->filho;
	if(!ptr)
	{
		pai->filho = bebe;
		pai->numero_filhos++;
	}
	else
	{
		while(ptr->irmao)
			ptr = ptr->irmao;
		ptr->irmao = bebe;
		pai->numero_filhos++;
	}
}
void visualizar(ponteiro raiz)
{
	if(!raiz)
		return;
	printf("%d(",raiz->chave);
	ponteiro ptr = raiz->filho;
	while(ptr)
	{
		printf("\n\t");
		visualizar(ptr);
		ptr = ptr->irmao;
	}
	printf(")");
}
ponteiro procurar(ponteiro raiz,int valor)
{
	if(!raiz)
		return NULL;
	if(raiz->chave == valor)
		return raiz;
	ponteiro ptr = raiz->filho;
	while(ptr)
	{
		ponteiro resposta = procurar(ptr,valor);
		if(resposta)
			return resposta;
		ptr = ptr->irmao;
	}
	return NULL;
}
void pad(char  ch,int nivel)
{
	for(int a = 0; a < nivel;a++)
		printf("%c",ch);
}
void juntar(ponteiro root,ponteiro branch)
{
	ponteiro ptr = root->filho;
	if(!ptr)
		root->filho = branch;
	else
	{
		while(ptr->irmao)
			ptr = ptr->irmao;
		ptr->irmao = branch;
	}
}
