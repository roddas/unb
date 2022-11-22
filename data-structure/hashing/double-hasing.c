#include<stdio.h>
#include<stdlib.h>

#define hash_function(v,M) (v%M)
#define hash_function_two(v,M) (v%97 + 1)
#define NOT_INSERTED -1
#define INSERTED -2

void hash_init(int );
void hash_insert(int );
int hash_search(int );
void hash_destroy(void);

static int HASH_SIZE;
static int N;
static int *hash_table;

int main(void)
{
	int n;
	printf("Insira a quantidade de elementos : ");
	scanf("%d",&n);
	hash_init(n);
	
	for(int a = 0;a < n;a++)
	{
		int tmp;
		printf("Insira o %d número: ",a+1);
		scanf("%d",&tmp);
		hash_insert(tmp);
	}
	while(1)
	{
		printf("Insira o número que deseja procurar (-1 para sair) : ");
		scanf("%d",&n);
		
		if(n == -1)
			break;
		
		printf("%d %s\n",n,(hash_search(n) ? "encontrado" : "não encontrado"));
	}
	hash_destroy();
	return EXIT_SUCCESS;
}
void hash_init(int max_elements)
{
	HASH_SIZE = max_elements * 2;
	N = 0;
	hash_table = (int *)malloc(HASH_SIZE * sizeof(int));
	
	for(int a = 0; a < HASH_SIZE;a++)
		hash_table[a] = NOT_INSERTED;
}
void hash_insert(int value)
{
	int i = hash_function(value,HASH_SIZE);
	int k = hash_function_two(value,HASH_SIZE);
	
	while(hash_table[i] != NOT_INSERTED)
		i = (i+k) % HASH_SIZE;
		
	hash_table[i] = value; 
	N++;
}
int hash_search(int value)
{
	int i = hash_function(value,HASH_SIZE);
	int k = hash_function_two(value,HASH_SIZE);
	
	while(hash_table[i] != NOT_INSERTED)
		if(hash_table[i] == value)
			return 1;
		else
			i = (i+k) % HASH_SIZE;
	
	return 0;
}
void hash_destroy(void)
{
	free(hash_table);
}
