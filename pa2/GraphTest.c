/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#2
* GraphTest.c
* Tester for Graph C file
*********************************************************************************/

#include<stdio.h>
#include "Graph.h"
	
int main(int argc, char* argv[]){
	

//1 4
//1 5
//4 5
//2 3
//2 6
//3 7
//6 7

Graph G = newGraph(7);
addEdge(G,1,4);
addEdge(G,1,5);
addEdge(G,4,5);
addEdge(G,2,3);
addEdge(G,2,6);
addEdge(G,3,7);
addEdge(G,6,7);

printGraph(stdout, G);
makeNull(G);
printGraph(stdout, G);
printf("Size: %d\n", getSize(G));
printf("Source: %d\n", getSource(G));
//printf("Parent: %d\n", getParent(G,0));
//printf("Distance: %d\n", getDist(G,0));
freeGraph(&G);
/*

Graph A = newGraph(100);
List C = newList();
List L = newList();
addArc(A, 64, 4);
        addArc(A, 64, 3);
        addArc(A, 42, 2);
        addArc(A, 2, 64);
        addArc(A, 4, 2);
        addArc(A, 3, 42);
        BFS(A, 3);
        getPath(L, A, 64);
        append(C, 3);
        append(C, 42);
        append(C, 2);
        append(C, 64);
        if (!equals(L, C)) {
			printf("Failed test 1/n");
		}
        moveFront(L);
        BFS(A, 2);
        getPath(L, A, 2);
        append(C, 2);
		printList(stdout,L);
		printf("\n");
		printList(stdout,C);
		printf("\n");
        if (!equals(L, C)) {
			printf("Failed test 2\n");
		}
        getPath(L, A, 99);
        if (equals(L, C)) {
			printf("Failed test 3/n");
		}
        clear(L);
        clear(C);
        append(C, NIL);
        BFS(A, 99);
        getPath(L, A, 2);
        if (!equals(C, L)) {
			printf("Failed test 4/n");
		}
		
		*/
		/*
		if (getSize(A) != 0) {
			printf("Failed test 1\n");
		}
        addEdge(A, 54, 1);
        addEdge(A, 54, 2);
        addEdge(A, 54, 3);
        addEdge(A, 1, 55);
			printf("Size %d\n", getSize(A) );
        if (getSize(A) != 4) {
			printf("Failed test 2\n");
		}
        BFS(A, 67);
        if (getSize(A) != 4) {
			printf("Failed test 3\n");
		}
        addEdge(A, 55, 2);
        if (getSize(A) != 5) {
			printf("Failed test 4\n");
		}
		*/
      
        return 0;


}