/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#4
* Matrix.c
* Matrix ADT C file
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "Matrix.h"



typedef struct EntryObj* Entry;

typedef struct EntryObj{
	double value;
	int column;
} EntryObj;


typedef struct MatrixObj{
	List* rows;
	int size;
	int NNZ;
}MatrixObj;

Entry newEntry(int column, double value){
	Entry E = malloc(sizeof(EntryObj));
	E->column = column;
	E->value = value;
	return(E);
	}
	
void freeEntry(Entry *pN){
if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
   }

Matrix newMatrix(int n){
	Matrix a;
	a = malloc(sizeof(MatrixObj));
	a->size = n;
	a->rows = (List*)malloc((n + 1) * sizeof(List));
	for (int i = 0; i < n + 1; i++){
		a->rows[i] = newList();
	}
	
	a->NNZ = 0;
	
	return a;
	
}
void freeMatrix(Matrix* pM) {
	if(pM != NULL && *(pM)!=NULL){
		
		for (int i = 0; i < (*pM)->size + 1; i++){
			if (length((*pM)->rows[i]) > 0){
					for (moveFront((*pM)->rows[i]); index((*pM)->rows[i]) >= 0; moveNext((*pM)->rows[i])){
						Entry t = ((Entry)get((*pM)->rows[i]));
						freeEntry(&t);
					}
				}
				freeList(&(*pM)->rows[i]);
		}
		free((*pM)->rows);
		free(*pM);
		*pM = NULL;
	}
	

	
	/*if(pM != NULL && *(pM)!=NULL){
		for (int i = 0; i < (*pM)->size + 1; i++){
				if (length((*pM)->rows[i]) > 0){
					for (moveFront((*pM)->rows[i]); index((*pM)->rows[i]) >= 0; moveNext((*pM)->rows[i])){
						t = (Entry)(get(*pM)->rows[i]);
						freeEntry(&t);
					}
				}
				freeList(&(*pM)->rows[i]);
			
		}
	}*/
}
int size(Matrix M) {
	
	return M->size;
}
int NNZ(Matrix M) {
	/*int NNZ = 0;
	for (int i = 1; i < M->size; i++){
		if (length(M->rows[i]) > 0){
			NNZ += length(M->rows[i]);
		}
	}*/
	return M->NNZ;		
}
int equals(Matrix A, Matrix B) {
	if (size(A) != size(B)){
	//	printf("Not same size \n");
		return 0;
	}
	
	if (NNZ(A) != NNZ(B)){
	//	printf("Not same NNZ \n");
		return 0;
	}
	for(int i = 0; i < size(A); i++){
		if (length(A->rows[i]) != (length(B->rows[i]))){
		//	printf("Not same lenght \n");
			return 0;
		}
		if (length(A->rows[i]) > 0){
		moveFront(A->rows[i]);
		moveFront(B->rows[i]);
		while (index(A->rows[i]) >= 0 && index(B->rows[i]) >= 0){
			if (((Entry)get((A)->rows[i]))->column != ((Entry)get((B)->rows[i]))->column) {
			//	printf("Not same Column \n");
				return 0;
			}
			if (((Entry)get((A)->rows[i]))->value != ((Entry)get((B)->rows[i]))->value) {
			//	printf("Not same Value \n");
				return 0;
			}
			moveNext(A->rows[i]);
			moveNext(B->rows[i]);
		}
		}
	}
	
	return 1;
		
	
}

void makeZero(Matrix M) {
	for (int i = 1; i < M->size; i++){
		if (length(M->rows[i]) > 0){
			for (moveFront((M)->rows[i]); index((M)->rows[i]) >= 0; moveNext((M)->rows[i])){
						Entry t = ((Entry)get((M)->rows[i]));
						freeEntry(&t);
					}
			clear(M->rows[i]);
		}	
	}
	M->NNZ = 0;
}

void changeEntry(Matrix M, int i, int j, double x){
	if (i < 1 || i > size(M)) {
		 printf("i is out of range \n");
		 return;
	}
	
	if (j < 1 || j > size(M)) {
		 printf("j is out of range \n");
		 return;
	}
	/*if (x == 0){
	//printf("x is zero");
	return;
	}*/
	//printf("Row: %d Column: %d Value: %f", i, j, x);
	Entry t = newEntry(j,x);
	//printf("Row: %d Column: %d Value: %f", i, t->column, t->value);
	
	for (moveFront(M->rows[i]); index(M->rows[i]) >= 0; moveNext(M->rows[i])){
	if (j < ((Entry)get(M->rows[i]))->column){
		
		if (x == 0) {
			freeEntry(&t);
			return;
		}
			insertBefore(M->rows[i],t);
			M->NNZ++;
			break;
		}
					
					
	if (j == ((Entry)get(M->rows[i]))->column){
		if (x == 0){
			Entry x = ((Entry)get((M)->rows[i]));
			freeEntry(&x);
			freeEntry(&t);
			delete(M->rows[i]);
			M->NNZ--;
			return;
		}
		Entry x = ((Entry)get((M)->rows[i]));
		freeEntry(&x);
		set(M->rows[i],t);
		break;	
		}
		
	
				}
				if (index(M->rows[i]) < 0){
					if (x == 0) {
						freeEntry(&t);
						return;
					}
						append(M->rows[i],t);
						M->NNZ++;
						
					}
					
//	moveFront(M->rows[1]);
//	printf("column:  %d \n", (Entry)get(M->rows[1])->column);
//	printf("value:  %f \n", (Entry)get(M->rows[1])->value);
	
	
	
}

Matrix copy(Matrix A) {
	int c;
	double v;
	Matrix M = newMatrix(size(A));
			for (int i = 1; i <= M->size; i++){
				if (length(A->rows[i]) > 0){
					for (moveFront(A->rows[i]); index(A->rows[i]) >= 0; moveNext(A->rows[i])){
						c = ((Entry)get(A->rows[i]))->column;
						v = ((Entry)get(A->rows[i]))->value;
						changeEntry(M,i,c,v);
				
					}
				}
			}
	return M;
}

Matrix transpose(Matrix A) {
	int c;
	double v;
	Matrix M = newMatrix(size(A));
			for (int i = 1; i <= M->size; i++){
				if (length(A->rows[i]) > 0){
					for (moveFront(A->rows[i]); index(A->rows[i]) >= 0; moveNext(A->rows[i])){
						c = ((Entry)get(A->rows[i]))->column;
						v = ((Entry)get(A->rows[i]))->value;
						changeEntry(M,c,i,v);
				
					}
				}
			}
	return M;
}

Matrix scalarMult(double x, Matrix A){
	int c;
	double v;
	Matrix M = newMatrix(size(A));
	for (int i = 1; i <= M->size; i++){
		if (length(A->rows[i]) > 0){
			for (moveFront(A->rows[i]); index(A->rows[i]) >= 0; moveNext(A->rows[i])){
				c = ((Entry)get(A->rows[i]))->column;
				v = x * ((Entry)get(A->rows[i]))->value;
				changeEntry(M,i,c,v);
				
			}
		}
	}
	return M;
	
}

List addList(List L, List M, int *c){
	
	int columnL = 0;
	int columnM = 0;
	double csum = 0.0;
	List A = newList();
	moveFront(L);
	moveFront(M);
	Entry t;
	while (index(L) >= 0 && index(M) >= 0){
			
		columnL = ((Entry)get(L))->column;
		columnM = ((Entry)get(M))->column;
		if (columnL == columnM) {
			csum = (((Entry)get(L))->value + ((Entry)get(M))->value);
			if (csum != 0){
			t = newEntry(columnL, csum);
			append(A,t);
			(*c)++;
			}
			moveNext(L);
			moveNext(M);
		}
		if (columnL > columnM) {
			csum = ((Entry)get(M))->value;
			t = newEntry(columnM, csum);
			append(A,t);
			(*c)++;
			moveNext(M);
			
		}
		if (columnL < columnM) {
			csum = ((Entry)get(L))->value;
			t = newEntry(columnL, csum);
			append(A,t);
			(*c)++;
			moveNext(L);
		}
	}
		
	while(index(L) >= 0) {
		columnL = ((Entry)get(L))->column;
		csum = ((Entry)get(L))->value;
		t = newEntry(columnL, csum);
		append(A,t);
		(*c)++;
		moveNext(L);	
	}
		
	while(index(M) >= 0) {
		columnM = ((Entry)get(M))->column;
		csum = ((Entry)get(M))->value;
		t = newEntry(columnM, csum);
		append(A,t);
		(*c)++;
		moveNext(M);	
		}
				
	
	return A;
}

Matrix sum(Matrix A, Matrix B) {
	if (size(A) != size(B)){
		printf("Matrices not same size\n");
		exit(EXIT_FAILURE);
	}
	Matrix M;
	if ( A == B){
		M = scalarMult(2, A);
		return M;
	}
	M = newMatrix(size(A));
	int z = 0;
	List Q;
	/*for (int i = 1; i <= size(M); i++) {
		//printf("i %d\n", i);
		if (length(A->rows[i]) > 0 && length(B->rows[i]) > 0){
		//printf("1: %d\n", i);
		Q = addList(A->rows[i], B->rows[i], &z);
		freeList(&M->rows[i]);
		M->rows[i] = Q;	
		}
		if (length(A->rows[i]) > 0 && length(B->rows[i]) <= 0) {
		//	printf("2: %d\n", i);
			//Q = (A->rows[i]);
			Q = addList(A->rows[i], B->rows[i], &z);
			z += length(A->rows[i]);
			freeList(&M->rows[i]);
			M->rows[i] = Q;	
		}
		if (length(B->rows[i]) > 0 && length(A->rows[i]) <= 0) {
		//	printf("3: %d\n", i);
			Q = (B->rows[i]);
			z += length(A->rows[i]);
			freeList(&M->rows[i]);
			M->rows[i] = Q;	
		}
		
	}*/
	for (int i = 1; i <= size(M); i++) {
		//printf("i %d\n", i);
		Q = addList(A->rows[i], B->rows[i], &z);
		freeList(&M->rows[i]);
		M->rows[i] = Q;
	}
	
	M->NNZ = z;
	return M;
}

List subList(List L, List M, int * c){
	int columnL = 0;
	int columnM = 0;
	double csum = 0.0;
	List A = newList();
	moveFront(L);
	moveFront(M);
	Entry t;
	while (index(L) >= 0 && index(M) >= 0){
			
		columnL = ((Entry)get(L))->column;
		columnM = ((Entry)get(M))->column;
		if (columnL == columnM) {
			csum = (((Entry)get(L))->value - ((Entry)get(M))->value);
			if (csum != 0){
			t = newEntry(columnL, csum);
			append(A,t);
			(*c)++;
			}
			moveNext(L);
			moveNext(M);
		}
		if (columnL > columnM) {
			csum = 0 - ((Entry)get(M))->value;
			t = newEntry(columnM, csum);
			append(A,t);
			(*c)++;
			moveNext(M);
			
		}
		if (columnL < columnM) {
			csum = ((Entry)get(L))->value;
			t = newEntry(columnL, csum);
			append(A,t);
			(*c)++;
			moveNext(L);
		}
	}
		
	while(index(L) >= 0) {
		columnL = ((Entry)get(L))->column;
		csum = ((Entry)get(L))->value;
		t = newEntry(columnL, csum);
		append(A,t);
		(*c)++;
		moveNext(L);	
	}
		
	while(index(M) >= 0) {
		columnM = ((Entry)get(M))->column;
		csum = 0 - ((Entry)get(M))->value;
		t = newEntry(columnM, csum);
		append(A,t);
		(*c)++;
		moveNext(M);	
		}
				
	
	return A;
}

Matrix diff(Matrix A, Matrix B){
	if (size(A) != size(B)){
		printf("Matrices not same size\n");
		exit(EXIT_FAILURE);
	}
	Matrix M = newMatrix(size(A));
	if (A == B){
		return M;
	}
	int z = 0;
	List Q;
	
	/*for (int i = 1; i <= size(M); i++) {
		if (length(A->rows[i]) > 0 && length(B->rows[i]) > 0){
		Q = subList(A->rows[i], B->rows[i], &z);
		freeList(&M->rows[i]);
		M->rows[i] = Q;	
		}
		if (length(A->rows[i]) > 0 && length(B->rows[i]) <= 0) {
			Q = (A->rows[i]);
			z += length(A->rows[i]);
			freeList(&M->rows[i]);
			M->rows[i] = Q;	
		}
		if (length(B->rows[i]) > 0 && length(A->rows[i]) <= 0) {
			Q = subList(A->rows[i], B->rows[i], &z);
			freeList(&M->rows[i]);
			M->rows[i] = Q;	
		}
		
	}*/
	
	for (int i = 1; i <= size(M); i++) {
		Q = subList(A->rows[i], B->rows[i], &z);
		freeList(&M->rows[i]);
		M->rows[i] = Q;
	}
	M->NNZ = z;
	return M;
}
double doubledot(List L,List M){
		int columnL = 0;
		int columnM = 0;
		double csum = 0.0;
		moveFront(L);
		moveFront(M);
		while (index(L) >= 0 && index(M) >= 0){
			columnL = ((Entry)get(L))->column;
			columnM = ((Entry)get(M))->column;
			if (columnL == columnM) {
				csum += (((Entry)get(L))->value * ((Entry)get(M))->value);
				moveNext(L);
				moveNext(M);
			}
			if (columnL > columnM) {
				moveNext(M);
			}
			if (columnL < columnM) {
				moveNext(L);
			}
		}
	return csum;
    }
	

Matrix product(Matrix A, Matrix B) {
	if (size(A) != size(B)){
		printf("Matrices not same size\n");
		exit(EXIT_FAILURE);
	}
	double v = 0.0;
	Matrix M = newMatrix(size(A));
	Matrix R = transpose(B);
	for (int i = 1; i <= size(M); i++){
		if (length(A->rows[i]) > 0){
			for (int j = 1; j <= size(R); j++){
				if (length(R->rows[j]) > 0){
				v = doubledot(A->rows[i], R->rows[j]);
					if (v != 0){
					changeEntry(M,i,j,v);
					}
				}
			
			}
		}
	}
	freeMatrix(&R);
	return M;
}
				
		
	

void printMatrix(FILE* out, Matrix M) {
	Entry x;
	for (int i = 1; i <= M->size; i++){
		if (length(M->rows[i]) > 0){
			fprintf(out, "%d: ", i);
			for (moveFront(M->rows[i]); index(M->rows[i]) >= 0; moveNext(M->rows[i])){
				x = (Entry)get(M->rows[i]);
				fprintf(out, "(%d, %.1f) ", x->column, x->value);
		}
		fprintf(out, "\n");
	}
	}
}
		