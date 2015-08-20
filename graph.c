#include<stdio.h>
#include<stdlib.h>
#include"test2.h"
#define maxV 10000

Stack *s1;
Stack *s2;

static int count, pre[maxV],lbl[maxV];

struct digraph {
 int V; 
 int A;
 int **adj;
};

//Cria a matriz de adjacÃªncias (utilizando a tÃ©cnica de vetor de ponteiros)
int **MATRIXint( int r, int c, int val) {
  Vertex i,j;
  int **m = malloc(r*sizeof(int*));
  for (i = 0; i < r; i++)
       m[i] = malloc(c*sizeof(int));
  for (i = 0; i < r; i++)
       for (j = 0; j < c; j++)
           m[i][j] = val;
  return m;
}


//Cria o digrafo com V vertices e V arcos
Digraph DIGRAPHinit(int V){
   Digraph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint(V,V,0);
   return G;
}

//Insere o arco entre v e w
void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w) {
  if (G->adj[v][w] == 0)
      {
	G->adj[v][w] = 1;
  	G->A++;
	}
}

//Remove o arco entre v e w
void DIGRAPHremoveA( Digraph G, Vertex v, Vertex w){
  if (G->adj[v][w] == 1){
    G->adj[v][w] = 0;
    G->A--;
  }
}

void DIGRAPHshow(Digraph G){
   Vertex v,w;
   for (v = 0; v < G->V; v++){
     printf("%2d:", v);
      for (w = 0; w < G->V; w++)
         if (G->adj[v][w] == 1)
            printf(" %2d", w);
      printf("\n");
  }

}

void DIGRAPHdfs( Digraph G) {
Vertex v;
count = 0;
s1=init();
s2=init();

for (v = 0; v < G->V; v++)
     pre[v] = -1;
for (v = 0; v < G->V; v++)
     if(pre[v] == -1)
         dfsR(G,v);
for (v = 0; v< G->V;v++)
     printf("%d ",pre[v]);
printf("\n");

printf("\n\n====Topological Sorting====\n\n ");
print_stack(s2);


}


void dfsR(Digraph G, Vertex v) {
Vertex w;
int temp;
pre[v] = count++;
push(v,s1);
printf("\n\ndfsR (s1)\n\n");
print_stack(s1);
for(w = 0; w < G->V; w++){
     if(G->adj[v][w] != 0 && pre[w] == -1)
          dfsR(G,w);
}
	temp = pop(s1);
	printf("\n\ndfsR (s1)\n\n");
	print_stack(s1);
	push(temp,s2);
	printf("\n\ndfsR (s2)\n\n");
	print_stack(s2);	
}

int DIGRAPHreach(Digraph G, Vertex s, Vertex t) {
Vertex w;
for (w = 0; w< G->V; w++)
     lbl[w] = 0;
reachR(G,s);
if (lbl[t] == 0) return 0;
else return 1;
}

void reachR (Digraph G, Vertex v) {

Vertex w;
lbl[v] = 1;
for (w = 0; w < G->V; w++)
  if(G->adj[v][w] == 1 && lbl[w] == 0)
	reachR(G,w);
}
