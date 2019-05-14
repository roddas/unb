#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct d
{
	int linha;
	int coluna;
}pixel;

void print_matrix(pixel,int **);
void fill_matrix(pixel,int **,int);
void free_matrix(int,int **);

int main(void)
{
	pixel dimensao;
	 
	printf("Insira o número de linhas :");
	scanf("%d",&dimensao.linha);
	printf("Insira o número de colunas :");
	scanf("%d",&dimensao.coluna);
	
	int **matriz = (int **)calloc(dimensao.coluna,sizeof(int *));
	if(!matriz)
	{
		perror("Erro :");
		exit(1);
	}
	int contador;
	
	for(contador = 0 ; contador < dimensao.coluna;contador++)
	{
		matriz[contador] = (int *)calloc(dimensao.linha,sizeof(int));
		if(!matriz[contador])
		{
			perror("Erro :");
			exit(1);
		}
	}
	
	fill_matrix(dimensao,matriz,2);
	print_matrix(dimensao,matriz);
	free_matrix(dimensao.coluna,matriz);
	return 0;
}

void print_matrix(pixel limite,int **matriz)
{
	int linha,coluna;
	for(linha = 0 ;linha < limite.linha;linha++)
	{
		for(coluna = 0 ; coluna < limite.coluna;coluna++)
		{
			printf("%d ",matriz[linha][coluna]);
		}
		puts("");
	}
}

void fill_matrix(pixel limite,int **matriz,int value)
{
	
	int linha,coluna;
	for(linha = 0 ;linha < limite.linha;linha++)
	{
		for(coluna = 0 ; coluna < limite.coluna;coluna++)
		{
			matriz[linha][coluna] = value;
		}
		puts("");
	}	
}

void free_matrix(int n_colunas,int **matriz)
{
	int contador;
	
	for(contador = 0 ; contador < n_colunas;contador++)
		free(matriz[contador]);
	free(matriz);
}
