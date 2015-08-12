#define Vertex int

typedef struct digraph *Digraph;

Digraph DIGRAPHinit(int V);
int **MATRIXint(int r, int c, int val);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
void DIGRAPHdfs( Digraph G);
void dfsR(Digraph G, Vertex v);
