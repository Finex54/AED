#include <stdlib.h>

#define maxV 100
#define dfsR search

static int cnt, pre[maxV];


struct graph {int V; int E; int **adj;};
struct edge {int v; int w;};


typedef struct edge Edge;
typedef struct graph Graph;


Graph *GRAPHinit(int);
void GRAPHinsertE(Graph *G, Edge*);
void GRAPHremoveE(Graph *G, Edge*);
int GRAPHedges(Edge a[], Graph *G);
void dfsR(Graph *G, Edge *e);
void GRAPHsearch(Graph *G);