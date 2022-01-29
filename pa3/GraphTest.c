/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#3
* GraphTest.c
* Tester for Graph C file
*********************************************************************************/

#include<stdio.h>
#include "Graph.h"
	
int main(int argc, char* argv[]){
	

int i, n=8;
   List S = newList();
   Graph G = newGraph(n);
   Graph T=NULL;
   Graph C=NULL;

   for(i=1; i<=n; i++) append(S, i);
   
   for (i = 1; i <= 100; i++)
          if (getDiscover(G, i) != UNDEF) {
			  printf("%d Fail\n", getDiscover(G, i));
		  }
		  else {
			  printf("Pass\n");
		  }

   addArc(G, 1,2);
   addArc(G, 1,5);
   addArc(G, 2,5);
   addArc(G, 2,6);
   addArc(G, 3,2);
   addArc(G, 3,4);
   addArc(G, 3,6);
   addArc(G, 3,7);
   addArc(G, 3,8);
   addArc(G, 6,5);
   addArc(G, 6,7);
   addArc(G, 8,4);
   addArc(G, 8,7);
   printGraph(stdout, G);

   DFS(G, S);
   fprintf(stdout, "\n");
   fprintf(stdout, "x:  d  f  p\n");
   for(i=1; i<=n; i++){
      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
   }
   fprintf(stdout, "\n");
   printList(stdout, S);
   fprintf(stdout, "\n");
  T = transpose(G);
   C = copyGraph(G);
   fprintf(stdout, "\n");
   printGraph(stdout, C);
   fprintf(stdout, "\n");
   printGraph(stdout, T);
   fprintf(stdout, "\n");
   
    DFS(T, S);
   fprintf(stdout, "\n");
   fprintf(stdout, "x:  d  f  p\n");
   for(i=1; i<=n; i++){
      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
   }
   fprintf(stdout, "\n");
   printList(stdout, S);
   fprintf(stdout, "\n");
   
  freeGraph(&G);
  freeGraph(&C);
   freeGraph(&T);
   freeList(&S);
   

}