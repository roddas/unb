#ifndef STACK_H
#define STACK_H

typedef struct node
{
	int dadum;
	struct node *next;
}node;

int empty(node *);
node *init(void);
node *new_node(int);
node *push(node *,int);
node *pop(node *,int *);
void error(void);

#endif
