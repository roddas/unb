#include<stdio.h>
#include<stdlib.h>

#define vertex int
#define INIT -1

typedef struct graph
{
	int V;
	int A;
	int **adj;
}*Graph;

typedef struct Edge
{
	vertex v,w;
}Edge;

vertex *pre = NULL;
vertex cnt;

Graph GRAPHInit(int );
void init_pre(vertex );
int GRAPHSearch(Graph );
void dfsR(Graph ,Edge );
void GRAPHInsert(Graph,Edge);
void GRAPHRemove(Graph,Edge);
vertex **MATRIXinit(int,int,int);
void GRAPHShow(Graph);
Edge EDGE(vertex,vertex);


int main(void)
{
	int n;
	scanf("%d",&n);
	init_pre(n);
	Graph G = GRAPHInit(n);
	while(1)
	{
		Edge e;
		scanf("%d%d",&e.v,&e.w);
		GRAPHInsert(G,e);
		if(e.w == 0 && e.w == 0)
			break;
	}
	//GRAPHShow(G);
	printf("%d grafos conexos\n\n",GRAPHSearch(G));
	return EXIT_SUCCESS;
}

Graph GRAPHInit(int V)
{
	Graph G = malloc(sizeof(*G));
	G->V = V;
	G->A = 0;
	G->adj = MATRIXinit(V,V,0);
	return G;
}
vertex **MATRIXinit(int linha,int coluna,int init_value)
{
	++linha,++coluna;
	vertex **m = calloc(linha ,sizeof(vertex *));
	
	for(vertex i = 0; i < linha;i++)
		m[i] = calloc(coluna , sizeof(vertex));
		
	return m;
}
void GRAPHInsert(Graph G,Edge e)
{
	vertex v = e.v;
	vertex w = e.w;
	
	if(G->adj[v][w] == 0)
	{
		G->adj[v][w] = G->adj[w][v] = 1;
		G->A++;
	}
}
void GRAPHRemove(Graph G,Edge e)
{
	if(G->adj[e.v][e.w] == 1)
	{
		G->adj[e.v][e.w] = G->adj[e.w][e.v] = 0;
		G->A--;
	}
}
void GRAPHShow(Graph G)
{
	for(vertex v = 0;v < G->V;v++)
	{
		printf("%2d:",v);
		for(vertex w = 0;w < G->V;w++)
		{
			if(G->adj[v][w] == 1)
			{
				printf(" %2d:",w);
			}
			printf("\n");
		}
	}
}
Edge EDGE(vertex v,vertex w)
{
	Edge edge = {v,w};
	return edge;
}
void dfsR(Graph G,Edge e)
{
	vertex t,w = e.w;
	pre[w] = cnt++;
	for(t = 0; t < G->V;t++)
		if(G->adj[w][t] != 0)
			if(pre[t] == INIT)
				dfsR(G,EDGE(w,t));
}
int GRAPHSearch(Graph G)
{
	int v,conexos = 0;
	cnt = 0;
	for(v = 0;v < G->V;v++)
		pre[v] = INIT;
		
	for(v = 0;v <  G->V;v++)
	{
		if(pre[v] == INIT)
		{
			dfsR(G, EDGE(v,v));
			conexos++;
		}
	}
	return conexos-1;
}
void init_pre(vertex V)
{
	cnt = 0;
	pre = malloc(sizeof(*pre) * V);
	for(vertex x = 0;x < V;x++)
		pre[x] = INIT;
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
