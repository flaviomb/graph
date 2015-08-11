#define Vertex int
struct digraph {
   int V;
   int A;
   int **adj;
};

typedef struct digraph *Digraph;

Digraph DIGRAPHinit(int V);
int **MATRIXint(int r, int c, int val);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
