#include<stdio.h>
#include<stdlib.h>
#include"adjmatrix.h"


//Cria a matriz de adjacências (utilizando a técnica de vetor de ponteiros)
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
