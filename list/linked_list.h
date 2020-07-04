#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node 
{
	int dadum;
	struct node *next;
}node;

node *new_node(int );
node *init(void);
node *insert_begin(node *,int);
node *insert_tail(node *,int);
node *find(node *,int);
node *remove_element(node *,int);
void erase(node *);
void error(void);
void view(node *);

#endif
