#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

int main(void)
{
	/*
	node *list = init();
	for(int a = 1; a  <= 10;a++)
		list = insert_begin(list,a);
	view(list);
	int value = 6;
	printf("%s\n",(find(list,value) ? "Encontrado" : "Não encontrado"));
	list = remove_element(list,value);
	erase(list);
	*/
	
	return EXIT_SUCCESS;
}
node *init(void)
{
	return new_node(0);
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
node *insert_tail(node *root,int value)
{
	if(!root->next)
	{
		root->next = new_node(value);
		return root;
	}
	
	node *ptr = root->next;
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new_node(value);
	return root;
}
node *insert_begin(node *root,int value)
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
node *find(node *root,int value)
{
	node *ptr = root->next;
	while(ptr->next)
	{
		if(ptr-> dadum == value)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}
void view(node *root)
{
	node *ptr = root->next;
	while(ptr)
	{
		printf("%d ",ptr->dadum);
		ptr = ptr->next;
	}
	printf("\n");
}
node *remove_element(node *root,int value)
{
	node *ptr = root->next;
	node *previous = NULL;
	while(ptr && ptr->dadum != value)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	if(!ptr)
		return NULL;
	if(!previous)
		root = ptr->next;
	else
		previous->next = ptr->next;
	free(ptr);
	return root;
}
void erase(node *root)
{
	node *ptr = root;
	while(ptr->next)
	{
		free(ptr);
		ptr = ptr->next;
	}
}
