/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#1
* FindPath.c
* Takes input file parses to create graph then parses to run BFS to find shortest path then outputs results to output file
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
		List L = newList();
		//printf("%d\n", n);
		while (fgets(word, 256, in) != NULL) {
			sscanf(word, "%d %d", &u, &v);
			if (u == 0 && v == 0){
				//printf("End now printing paths\n");
				break;
			}
			addEdge(G,u,v);
			
			}
			
			printGraph(out,G);
		while (fgets(word, 256, in) != NULL) {
			sscanf(word, "%d %d", &u, &v);
			if (u == 0 && v == 0){
				//printf("End of printing paths\n");
				break;
			}
			
			BFS(G,u);
			int distance = getDist(G,v);
			getPath(L,G,v);
			if (distance == INF){
			fprintf(out, "The distance from %d to %d is infinity\n", u, v);
			}
			else {
			fprintf(out, "The distance from %d to %d is %d\n", u, v, distance);
			}
			
			if (front(L) == NIL){
				//fprintf(out,"%s\n", ptr[get(L)]);
			fprintf(out, "No %d-%d path exists", u, v);
			}
			else {
				fprintf(out, "A shortest %d-%d path is: ", u, v);
				printList(out,L);
			}
			fprintf(out,"\n\n");
			clear(L);				
		}
		
		freeList(&L);
		freeGraph(&G);
			
			
			
		
			



fclose(in);
	fclose(out);

return(EXIT_SUCCESS);

}