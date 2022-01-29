/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#3
* Graph.c
* Graph ADT C file
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"


typedef struct GraphObj{
	 List* adj;
	 int *color;
	// int *distance;
	 int *parent;
	 int order;
	 int size;
	// int source;
	 int *finish;
	 int *discover;
	 
}GraphObj;


Graph newGraph(int n){
	Graph a;
	a = malloc(sizeof(GraphObj));
	a->order = n;
	a->color = (int*)malloc((n + 1) * sizeof(int));
	//a->distance = (int*)malloc((n + 1) * sizeof(int));
	a->parent = (int*)malloc((n + 1) * sizeof(int));
	a->finish = (int*)malloc((n + 1) * sizeof(int));
	a->discover = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 0; i < n + 1; i++){
		a->finish[i] = UNDEF;
		a->discover[i] = UNDEF;
		a->parent[i] = NIL;
	}
	a->adj = (List*)malloc((n + 1) * sizeof(List));
	for (int i = 0; i < n + 1; i++){
		a->adj[i] = newList();
	}
	a->size = 0;
//	a->source = NIL;
	return a;
	
}

void freeGraph(Graph* pG) {
	if(pG != NULL && *(pG)!=NULL){
		for (int i = 0; i < (*pG)->order + 1; i++){
			freeList(&(*pG)->adj[i]);
		}
		free((*pG)->adj);
		free((*pG)->color);
		free((*pG)->discover);
		free((*pG)->finish);
		free((*pG)->parent);
		free(*pG);
		*pG = NULL;
	}
}
/*** Access functions ***/
int getOrder(Graph G) {
	return G->order;
}
int getSize(Graph G) {
	return G->size;
}
/*int getSource(Graph G) {
	return G->source;
}*/

int getDiscover(Graph G, int u) {
	if ( u > getOrder(G) || u < 1){
		printf("input not in range\n");
		return UNDEF;
	}
	return G->discover[u];
}

int getFinish(Graph G, int u) {
	if ( u > getOrder(G) || u < 1){
		printf("input not in range\n");
		return UNDEF;
	}
	return G->finish[u];
}
	
int getParent(Graph G, int u) {
	if ( u > getOrder(G) || u < 1){
		printf("input not in range\n");
		return NIL;
	}
	
	return G->parent[u];
}
/*int getDist(Graph G, int u) {
	if ( u > getOrder(G) || u < 1){
		printf("input not in range\n");
		exit(EXIT_FAILURE);
	}
	if (G->source == NIL){
		return INF;
	}
	return G->distance[u];
}*/
/*void getPath(List L, Graph G, int u){
	if ( u > getOrder(G) || u < 1){
		printf("input not in range\n");
		return;
	}
	if (G->source == NIL){
		printf("Source not set, run BFS/n");
		return;
	}
	if ( u == G->source){
		append(L,G->source);
		return;
	}
	if (G->parent[u] == NIL){
		clear(L);
		append(L,NIL);
		return;
	}
	getPath(L,G,G->parent[u]);
	append(L,u);
	
}*/
/*** Manipulation procedures ***/
/*void makeNull(Graph G) {
	List tmp;
	int* tmp2;
	int* tmp3;
	int* tmp4;
	for (int i = 0; i < (G)->order + 1; i++){
		tmp = (G)->adj[i];
		G->adj[i] = NULL;
			freeList(&tmp);
		}
		tmp2 =  (G->color);
		G->color = NULL;
	G->color = (int*)malloc((G->order + 1) * sizeof(int));
		free(tmp2);
	
		tmp3 = G->distance;
		G->distance = NULL;
	G->distance = (int*)malloc((G->order + 1) * sizeof(int));
		free(tmp3);
	
		tmp4 = G->parent;
		G->parent = NULL;
	G->parent = (int*)malloc((G->order + 1) * sizeof(int));
		free(tmp4);
	
	G->order = 0;
	G->size = 0;
	
	G->source = NIL;
	
}*/
void addEdge(Graph G, int u, int v) {
		//printf("The order is %d \n", getOrder(G));
	if ( u > getOrder(G) || u < 1){
		printf("u not in range\n");
		return;
	}
	
	if ( v > getOrder(G) || v < 1){
		printf("v not in range\n");
		return;
	}
	
	if (length(G->adj[u]) > 0) {
		//printf("length is greater u\n");
		//printf("index adj[%d] %d \n", u, index(G->adj[u]) );
	for (moveFront(G->adj[u]); index(G->adj[u]) >= 0; moveNext(G->adj[u])){
		//printf("in loop u\n");
	if (v <= get(G->adj[u]) ){
				//printf("insert before in adj[%d]\n", u);
						insertBefore(G->adj[u],v);
						break;
					}
					
				}
				if (index(G->adj[u]) < 0){
					 //printf("append after in adj[%d]\n", u);
						append(G->adj[u],v);
					}
				
	}
	
	if (length(G->adj[u]) <= 0){
		//printf("append first u\n");
		append(G->adj[u],v);
		//printf("length after %d u\n", length(G->adj[u]));
	}
	
	if (length(G->adj[v]) > 0) {
	for (moveFront(G->adj[v]); index(G->adj[v]) >= 0; moveNext(G->adj[v])){
	if (u <= get(G->adj[v]) ){
		//printf("insert before v\n");
						insertBefore(G->adj[v],u);
						break;
					}
				}
				if (index(G->adj[v]) < 0){
					//printf("append after v\n");
						append(G->adj[v],u);
					}
	}
	
	if (length(G->adj[v]) == 0){
		//printf("append first v\n");
		append(G->adj[v],u);
	}
	G->size++;
}


void addArc(Graph G, int u, int v){
	if ( u > getOrder(G) || u < 1){
		printf("u not in range\n");
		return;
	}
	
	if ( v > getOrder(G) || v < 1){
		printf("v not in range\n");
		return;
	}
	for (moveFront(G->adj[u]); index(G->adj[u]) >= 0; moveNext(G->adj[u])){
	if (v <= get(G->adj[u]) ){
						insertBefore(G->adj[u],v);
						break;
					}
				}
				if (index(G->adj[u]) < 0){
						append(G->adj[u],v);
					}
					G->size++;
}

void Visit(Graph G, int i, int* time) {
	G->discover[i] = (++(*time));
	G->color[i] = 1;
	
	for (moveFront(G->adj[i]); index(G->adj[i]) >= 0; moveNext(G->adj[i])){
		int y = get(G->adj[i]);
		if (G->color[y] == 0){
			G->parent[y] = i;
			Visit(G, y, time);
		}
	}
		G->color[i] = 2;
		G->finish[i] = (++(*time));
}

void DFS(Graph G, List S){
	if (length(S) != getOrder(G)){
		printf("Length of List is not same as # of vertices on Graph\n");
		return;
	}
	int r = 0;
	int rr = 0;
	int time = 0;
	for (int i = 1; i < G->order + 1; i++){
		G->color[i] = 0;
		G->discover[i] = UNDEF;
		G->finish[i] = UNDEF;
		G->parent[i] = NIL;
	}
		for (moveFront(S); index(S) >= 0; moveNext(S)){
			r = get(S);
			//printf("%d\n", r);
		if (G->color[r] == 0){
			Visit(G, r, &time);

			
		}
	}
	clear(S);
	prepend(S, 1);
		
			for (int i = 2;  i <= getOrder(G); i++){
				for (moveFront(S); index(S) >= 0; moveNext(S)){
					rr = get(S);
				//fprintf(out, "List Element: %d %s Index: %d Length: %d\n", get(L), ptr[i], index(L), length(L));
				if (getFinish(G,i) > getFinish(G,rr)){
			//	if (strcmp(ptr[i], ptr[get(L)]) <= 0){
						insertBefore(S,i);
						break;
					}
				}
				if (index(S) < 0){
						append(S,i);
					}
			}

}


	
/*void BFS(Graph G, int s){
	G->source = s;
	int x = 0;
	int y = 0;
	for (int i = 1; i < G->order + 1; i++){
		G->color[i] = 0;
		G->distance[i] = INF;
		G->parent[i] = NIL;
	}
	G->color[s] = 1;
	G->distance[s] = 0;
	
	List Q = newList();
	append(Q,s);
	while (length(Q) > 0){
		x = front(Q);
		deleteFront(Q);
		for (moveFront(G->adj[x]); index(G->adj[x]) >= 0; moveNext(G->adj[x])){
		y = get(G->adj[x]);
		if (G->color[y] == 0){
			G->color[y] = 1;
			G->distance[y] = G->distance[x] + 1;
			G->parent[y] = x;
			append(Q,y);
			}
		}
	
		G->color[x] = 2;
	}
	
	freeList(&Q);
	return;
}	
		
		*/		
/*** Other operations ***/
void printGraph(FILE* out, Graph G){
	//printf("%d\n", G->order);
	for (int i = 1; i < G->order + 1; i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	
	return;
}

Graph copyGraph(Graph G){
	Graph a = newGraph(G->order);
	/*a = malloc(sizeof(GraphObj));
	a->order = G->order;
	a->color = (int*)malloc((a->order + 1) * sizeof(int));
	a->parent = (int*)malloc((a->order + 1) * sizeof(int));
	a->finish = (int*)malloc((a->order + 1) * sizeof(int));
	a->discover = (int*)malloc((a->order + 1) * sizeof(int));
	a->adj = (List*)malloc((a->order + 1) * sizeof(List));
	for (int i = 0; i < a->order + 1; i++){
		a->adj[i] = newList();
	}
	*/
	for (int i = 1; i < a->order + 1; i++){
		/*a->color[i] = a->color[i];
		a->parent[i] = a->parent[i];
		a->finish[i] = a->finish[i];
		a->discover[i] = a->discover[i];*/
		freeList(&a->adj[i]);
		a->adj[i] = copyList(G->adj[i]);	
	}
	a->size = G->size;
	return a;
	
}

Graph transpose(Graph G){
	
	Graph a = newGraph(G->order);
	
	
	for (int i = 1; i < a->order + 1; i++){
		for (moveFront(G->adj[i]); index(G->adj[i]) >= 0; moveNext(G->adj[i])){
			int y = get(G->adj[i]);
			addArc(a,y,i);
		}
	}
	return a;
}
		
			