#include "graph.h"



/**********************************************
*
*Funções relativas às operações com grafos em matriz de adjacências
*
*
**********************************************/

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

/**********************************************
*
*dfsR: Algoritmo de procura de Tremaux
*
*
**********************************************/

	void dfsR(Graph *G, Edge *e)
	{
	  int t, w = e->w;
	  pre[w] = cnt++;
	  for (t = 0; t < G->V; t++)
	    if (G->adj[w][t] != 0)
	    if (pre[t] == -1)
	      dfsR(G, EDGE(w, t));
	}

/**********************************************
*
*GRAPHsearch: ADT para procura
*             Inicializa pre a -1 e cnt a 0, chama função search
*
**********************************************/

	void GRAPHsearch(Graph *G)
	{
	  int v;
	  cnt = 0;
	  for (v = 0; v < G->V; v++)
	    pre[v] = -1;
	  for (v = 0; v < G->V; v++)
	    if (pre[v] == -1)
	      search(G, EDGE(v, v));
	}



