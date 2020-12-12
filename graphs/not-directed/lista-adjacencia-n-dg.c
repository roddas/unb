#include<stdio.h>
#include<stdlib.h>

#define vertex int
#define INIT -1
#define SIZE 1000

vertex *pre = NULL;
vertex cnt;

typedef struct node
{
	vertex w;
	struct node *next;
}*link;

typedef struct graph
{
	int V;
	int A;
	link *adj;
}*Graph;

typedef struct Edge
{
	vertex v,w;
}Edge;

link NEWnode(vertex ,link );
Graph GRAPHInit(int );
Edge EDGE(vertex,vertex);
void GRAPHInsert(Graph,Edge);
void dfsR(Graph ,vertex);
void GRAPHdfs(Graph );
void GRAPHShow(Graph);
void init_pre(vertex );
void bfs(Graph ,Edge );
void print_array(Graph );
int GRAPHSearch(Graph );


int inicializar(void);
int enfileirar(Edge);
Edge desenfileirar(void);
int fila_vazia(void);
void imprime(void);

typedef struct celula
{
	Edge conteudo;
	struct celula *proximo;
}celula;
celula *fila = NULL;


int main(void)
{
	int n;
	scanf("%d",&n);
	init_pre(n);
	inicializar();
	Graph G = GRAPHInit(n);
	while(1)
	{
		Edge e;
		scanf("%d%d",&e.v,&e.w);
		GRAPHInsert(G,e);
		if(e.w == 0 && e.w == 0)
			break;
	}
	GRAPHShow(G);
	printf("%d grafos conexos\n\n",GRAPHSearch(G));
	///print_array(G);
	
	return EXIT_SUCCESS;
}
link NEWnode(vertex w,link next )
{
	link a = malloc(sizeof(*a));
	a->w = w;
	a->next = next;
	return a;
}
Graph GRAPHInit(int V)
{
	Graph G = malloc(sizeof(*G));
	G->V = V;
	G->A = 0;
	G->adj = calloc(V,sizeof(link));
	return G;
}
void GRAPHInsert(Graph G,Edge e)
{
	vertex v = e.v;
	vertex w = e.w;
	
	for(link a = G->adj[v];a;a = a->next)
		if(a->w == w)
			return;
	G->adj[v] = NEWnode(w,G->adj[v]);
	G->A++;
}
void GRAPHdfs(Graph G)
{
	for(vertex x = 0; x < G->V;x++)
		if(pre[x] == INIT)
			dfsR(G,x);
}
void dfsR(Graph G,vertex v)
{
	pre[v] = cnt++;
	for(link i = G->adj[v];i;i = i->next)
	{
		vertex w = i->w;
		if(pre[w] == INIT)
			dfsR(G,w);
	}
}
Edge EDGE(vertex v,vertex w)
{
	Edge edge = {v,w};
	return edge;
}
void init_pre(vertex V)
{
	cnt = 0;
	pre = malloc(sizeof(*pre) * V);
	for(vertex x = 0;x < V;x++)
		pre[x] = INIT;
}
void GRAPHShow(Graph G)
{
	for(int j = 1;j <= G->V;j++)
	{
		link k = G->adj[j];
		printf("%d : ",j);
			for(;k;k = k->next)
			printf(" %d ->",k->w);
		printf("\n");
	}
}
void print_array(Graph G)
{
	for(vertex a = 0; a < G->V;a++)
		printf("%d : %d\n",a,pre[a]);
	printf("\n");
}
int GRAPHSearch(Graph G)
{
	int conexos = 0;
	vertex v;
	cnt = 0;
	
	for(v = 0;v < G->V;v++)
		pre[v] = INIT;
		
	for(v = 0;v < G->V;v++)
	{
		if(pre[v] == INIT)
		{
			bfs(G,EDGE(0,v));
			//dfsR(G,v);
			conexos++;
		}
	}
	return conexos-1;
}
void bfs(Graph G,Edge e)
{
	vertex w;
	enfileirar(e);
	pre[e.w] = cnt++;
	while(!fila_vazia())
	{
		e = desenfileirar();
		w = e.w;
		for(link a = G->adj[w];a; a = a->next)
		{
			vertex t = a->w;
			if(pre[t] == INIT)
			{
				pre[t] = cnt++;
				enfileirar(EDGE(w,t));
			}
		}
	}
}
// bfs com fila


int inicializar(void)
{
	fila = malloc(sizeof(celula));
	if(!fila)
		return 0;
	fila->proximo = fila;
	return 1;
}
int enfileirar(Edge elemento)
{
	celula *nova = (celula *)malloc(sizeof(celula));
	if(!nova)
		return 0;
	nova->proximo = fila->proximo;
	fila->proximo = nova;
	fila->conteudo = elemento;
	fila = nova;
	return 1;
}
Edge desenfileirar(void)
{
	celula *lixo = fila->proximo;
	fila->proximo = lixo->proximo;
	Edge ret = lixo->conteudo;
	free(lixo);
	return ret;
}
int fila_vazia(void)
{
	return fila->proximo == fila;
}
void imprime(void)
{
	for(celula *ptr = fila->proximo;ptr->proximo != fila->proximo;ptr = ptr->proximo)
		printf("(%d,%d)\n",ptr->conteudo.v,ptr->conteudo.w);
}


/*
11
1 2
1 3
1 5
2 1 
2 5
3 1
3 5
3 6
4 5
4 6
5 1
5 2
5 3
5 4
6 3
6 4
7 9
7 11
8 9
8 10
9 7
9 8
10 8
11 7
0 0
 * */
