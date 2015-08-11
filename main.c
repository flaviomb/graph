#include<stdio.h>
#include<stdlib.h>
#include"adjmatrix.h"
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
			
	while(opt != 0)
	{
		printf("\n==== Options ===== \n");
		printf("\nOption 1: insert an arc. \n");
		printf("\nOption 2: remove an arc.\n");
		printf("\nOption 3: show the digraph\n");
		printf("\nOption 4: quit\n");		
		printf("\nEnter the option: "); 
		scanf("%d",&opt);	
		
		if(opt == 1)
		{
			printf("\n==== Option 1 selected (insert an arc) ====\n");
			printf("\nEnter the initial vertex v and the final vertex w of the arc: ");
			scanf("%d %d", &v, &w);
			DIGRAPHinsertA(G,v,w);	
		}
		else if (opt == 2)
		{
			printf("\n==== Option 2 selected (remove an arc) ====\n");
			printf("\nEnter the initial vertex v and the final vertex w of the arc: ");
			scanf("%d %d", &v, &w);
			DIGRAPHremoveA(G,v,w);
		}
		else if (opt == 3)
		{
			printf("\n==== Option 3 selected (show the digraph) ====\n");
			DIGRAPHshow(G);
		}
	}
return 0;
}
