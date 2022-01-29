/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#1
* FindComponents.c
* Takes input file parses to create graph then parses to run DFS to find strongly connected components then outputs results to output file
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Graph.h"

int main(int argc, char* argv[]){
	FILE* in;
FILE* out;
char word[256];
int n = 0;
int u = -1;
int v = -1;
if (argc != 3){
		printf("Wrong number of inputs");
		exit(EXIT_FAILURE);
		}
	in = fopen(argv[1], "r");
		if ( in==NULL ) {
			printf("Unable to read %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	out = fopen(argv[2], "w");
	
	if ( out==NULL ) {
			printf("Unable to write %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		fgets(word, 256, in);
		n = atoi(word);
		Graph G = newGraph(n);
		Graph T = NULL;
		List L = newList();
		while (fgets(word, 256, in) != NULL) {
			sscanf(word, "%d %d", &u, &v);
			if (u == 0 && v == 0){
				//printf("End now printing paths\n");
				break;
			}
			addArc(G,u,v);
			
			}
			for(int i=1; i<=n; i++) append(L, i);
			DFS(G,L);
			fprintf(out, "Adjacency list representation of G:\n");
			printGraph(out,G);
			T = transpose(G);
			DFS(T,L);
			int count = 0;
			int q = 0;
			int SCCs = 0;
			List S = newList();
			for (int i = 1; i <= getOrder(G); i++){
				if (getParent(T,i) == 0){
					SCCs++;
				}
			}
		//	printList(stdout,L);
			fprintf(out, "G contains %d strongly connected components:", SCCs);
			for (moveBack(L); index(L) >= 0; movePrev(L)){
				q = get(L);
				prepend(S,q);
				if (getParent(T,q) == 0){
					count++;
					fprintf(out, "\nComponent %d: ", count);
					printList(out,S);
					clear(S);
				}
				
			//printList(stdout, L);
   }
   
   freeGraph(&G);
   freeGraph(&T);
   freeList(&S);
   freeList(&L);
   
   fclose(in);
	fclose(out);

return(EXIT_SUCCESS);
	

	
}