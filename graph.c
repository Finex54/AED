#include "graph.h"
/*
struct graph {
	int V;
	int E;
	int **adj;
};

struct edge {
	int v;
	 int w;
};


int **MATRIXinit(int V1, int V2, int value)
{
	int i,j;
	int **MATRIX;

	MATRIX = (int**) malloc (V1*sizeof(int*));
		for(i=0; i<V2; i++)
			MATRIX[i]= (int*) malloc (V2*sizeof(int));
	for(i=0; i<V1; i++)
		for(j=0; j<V2; j++)
			MATRIX[i][j]=value;

		return MATRIX;

}


	Graph *GRAPHinit(int V)
	{
		Graph *G = (Graph*) malloc(sizeof(struct graph));    
		G->V = V; G->E = 0;
		G->adj = MATRIXinit(V, V, 0);
		return G;
	}


	void GRAPHinsertE(Graph *G, Edge *e){
		int v = e->v, w = e->w;
		if (G->adj[v][w] == 0) G->E++;
		G->adj[v][w] = 1;
		G->adj[w][v] = 1;
	}
	void GRAPHremoveE(Graph *G, Edge *e)
	{
		int v = e->v, w = e->w;
		if (G->adj[v][w] == 1) G->E--;
		G->adj[v][w] = 0;
		G->adj[w][v] = 0;
	}
*/