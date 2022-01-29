/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#3
* Graph.h
* Graph ADT Header file
* same as the one in PA2 description
*********************************************************************************/


#ifndef GRAPH_HINCLUDE
#define GRAPH_HINCLUDE
//#include<stdio.h>
#include"List.h"
#define NIL 0
#define UNDEF -1


typedef struct GraphObj* Graph;

/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph* pG);
/*** Access functions ***/
int getOrder(Graph G);
int getSize(Graph G);
//int getSource(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);
//int getDist(Graph G, int u);
//void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
//void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
//void BFS(Graph G, int s);
void DFS(Graph G, List S);
/*** Other operations ***/
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out, Graph G);

#endif