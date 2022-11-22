#include<stdio.h>
#include<stdlib.h>

typedef int typekey;

typedef struct node
{
	typekey dadum;
	struct node *first_child;
	struct node *next_brother;
	
}node;

node *new_node(int);
void error(void);
node *init(typekey);
void insert_node(node *,typekey,node *);
node *search(node *,typekey);
void view(node *);
void join_node(node *,node *);

int main(void)
{
	node *root = init(0);
	node *odd = init(1);
	node *even = init(2);	
	
	for(int a = 3; a<= 10;a++)
		if(a&1)
			insert_node(odd,a,odd);
		else
			insert_node(even,a,even);
			
	join_node(root,odd);
	join_node(root,even);
	view(root);
	return EXIT_SUCCESS;
}
node *new_node(typekey value)
{
	node *new = (node *)malloc(sizeof(node));
	new->first_child = new->next_brother = NULL;
	new->dadum = value;
	return new;
}
void error(void)
{
	perror("");
	printf("Insira qualquer tecla para sair ..");
	scanf("%*c");
	exit(EXIT_FAILURE);
}
node *init(typekey value)
{
	return new_node(value);
}
void insert_node(node *root,typekey value,node *father)
{
	node *son = new_node(value);
	node *ptr = father->first_child;
	if(!ptr)
		father->first_child = son;
	else
	{
		while(ptr->next_brother)
			ptr = ptr->next_brother;
		ptr->next_brother = son;
	}
}	
node *search(node *root,typekey value)
{
	if(!root)
		return NULL;
	if(root->dadum == value)
		return root;
	node *ptr = root->first_child;
	while(ptr)
	{
		node *response = search(ptr,value);
		if(response)
			return response;
		ptr = ptr->next_brother;
	}
	return NULL;
}
void view(node *root)
{
	if(!root)
		return;
	printf("%d(",root->dadum);
	node *ptr = root->first_child;
	while(ptr)
	{
		view(ptr);
		ptr = ptr->next_brother;
	}
	printf(")");
}
void join_node(node *root,node *branch)
{
	node *ptr = root->first_child;
	if(!ptr)
		root->first_child = branch;
	else
	{
		while(ptr->next_brother)
			ptr = ptr->next_brother;
		ptr->next_brother = branch;
	}
}
