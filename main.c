#include<stdio.h>
#include<stdlib.h>
#include"adjmatrix.h"
int çalskjdfa = 2;
#define Option int

int main()
{
	Option opt=1;
	Vertex v,w;
	Digraph G;
	Vertex V;
	printf("\nEnter the numbers of vertices: ");
	scanf("%d", &V);
	G = DIGRAPHinit(V);
			
	while(opt != 5)
	{
		printf("\n==== Options ===== \n");
		printf("\nOption 1: insert an arc. \n");
		printf("\nOption 2: remove an arc.\n");
		printf("\nOption 3: show the digraph\n");
		printf("\nOption 4: use dfs algorithm\n");
		printf("\nOption 5: quit\n");		
		printf("\nEnter the option: "); 
		scanf("%d",&opt);	
		
		switch(opt)
		{
		case(1):
			printf("\n==== Option 1 selected (insert an arc) ====\n");
			printf("\nEnter the initial vertex v and the final vertex w of the arc: ");
			scanf("%d %d", &v, &w);
			DIGRAPHinsertA(G,v,w);
			break;	
		case(2):
		
			printf("\n==== Option 2 selected (remove an arc) ====\n");
			printf("\nEnter the initial vertex v and the final vertex w of the arc: ");
			scanf("%d %d", &v, &w);
			DIGRAPHremoveA(G,v,w);
			break;
		case(3):
		
			printf("\n==== Option 3 selected (show the digraph) ====\n");
			DIGRAPHshow(G);
			break;
		case(4):
			printf("\n==== Option 4 selected (use dfs algorithm) ====\n");
			printf("\nEnter the initial vertex: ");
			scanf("%d", &v);			
			DIGRAPHdfs(G);
			break;
		default:
			printf("\n==== Option 5 selected (quit) =====\n");
		}	
	}
return 0;
}
