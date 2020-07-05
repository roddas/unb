#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main(void)
{
	/*
	node *stack = init();
	for(int a = 1; a <= 10;a++)
		stack = push(stack,a);
	while(!empty(stack))
	{
		int value;
		stack = pop(stack,&value);
		printf("%d ",value);
	}
	* */
	return EXIT_SUCCESS;
}
node *init(void)
{
	return new_node(0);
}
void error(void)
{
	perror("");
	printf("Press any key to exit ..\n");
	scanf("%*c");
	exit(EXIT_FAILURE);
}
node *new_node(int value)
{
	node *cel = (node *)malloc(sizeof(node));
	if(!cel)
		error();
	cel->dadum = value;
	cel->next = NULL;
	return cel;
}
node *push(node *root,int value)
{
	if(!root->next)
	{
		root->next = new_node(value);
		return root;
	}
	node *cel = new_node(value);
	node *ptr = root;
	cel->next = ptr->next;
	ptr->next = cel;
	return root; 
}
node *pop(node *root,int *ret)
{
	node *trash = root->next;
	*ret = trash->dadum;
	root->next = trash->next;
	free(trash);
	return root;
}
int empty(node *root)
{
	return !root->next;
}
