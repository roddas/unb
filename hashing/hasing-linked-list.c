#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 429496
#define hash_function(v,M) (v%M)
#define INSERTED -2
#define NOT_INSERTED -1

/* list definitions */
typedef struct list
{
	int element;
	struct list *next;
}list;

static int HASH_SIZE;
static list **hash_table;

list *list_init(int);
void delete(int );
list *list_insert(list * ,int );
list *new_node(int );
int is_empty(list *);
void list_view(list* );
list *list_search(list * ,int );

void hash_init(int );
void hash_insert(int );
list *hash_search(int );
void hash_destroy(void);


int main(void)
{
	int n;
	hash_init(SIZE);
	
	printf("Insira um número (-1 para sair):\n");
	while(1)
	{
		scanf("%d",&n);
		if(n == -1)
			break;
		hash_insert(n);
	}
	printf("Insira \"i [numero]\" para pesquisar, \"d [numero]\" para apagar e \"s -1\" para sair : \n");
	while(1)
	{
		char str[2];
		scanf("%s%d",str,&n);
		
		if(str[0] == 'i')
			printf("%d %s\n",n,(hash_search(n) ? "encontrado" : "não encontrado"));
		else if(str[0] == 'd')
			delete(n);
		else if(str[0] == 's' && n == -1)
			break;
	}
		
	return EXIT_SUCCESS;
}
void hash_init(int max_elements)
{
	HASH_SIZE = max_elements * 2;
	hash_table = (list **)malloc(HASH_SIZE * sizeof(list *));
	
	for(int a = 0; a < HASH_SIZE;a++)
		hash_table[a] = list_init(NOT_INSERTED);
}
list *new_node(int value)
{
	list *new_list = (list *)malloc(sizeof(list));
	new_list->element = value;
	new_list->next = NULL;
	return new_list;
}
list *list_init(int value)
{
	return new_node(value);
}
list *list_insert(list * li,int value)
{
	list *node;
	if(!li)
	{
		li = list_init(value);
	}else
	{
		node = new_node(value);
		node->next = li;
	}
	return node;
}
void list_view(list* li)
{
	list *ptr = li;
	while(ptr)
	{
		printf("%d%s",ptr->element,(ptr->next) ? " " : "\n");
		ptr = ptr->next;
	}
}
int is_empty(list *li)
{
	return li->next == NULL;
}
list *list_search(list *li,int value)
{
	list *ptr = li;
	while(ptr)
	{
		if(ptr->element == value)
			return ptr;
			
		ptr = ptr->next;
	}
	return NULL;
}

/* HASHING */

void hash_insert(int value)
{
	int index  = hash_function(value,HASH_SIZE);
	
	// Se ñ tiver nenhum elemento, insira
	if(hash_table[index]->element == NOT_INSERTED)
		hash_table[index]->element = INSERTED;
			
	hash_table[index] = list_insert(hash_table[index],value);
}
list *hash_search(int value) 
{
	int index = hash_function(value,HASH_SIZE);
	return list_search(hash_table[index],value);
}

void delete(int value)
{
	int i = hash_function(value,HASH_SIZE);
	list *ptr = list_search(hash_table[i],value);
	list *previous = NULL;
	while(ptr && ptr->element != value)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	if(!ptr)
	{
		printf("%d não encontrado\n",value);
		return;
	}
	if(!previous)
		hash_table[i] = ptr->next;
	else
		previous->next = ptr->next;
	free(ptr);
	printf("Elemento %d eliminado com sucesso ..\n",value);
}
