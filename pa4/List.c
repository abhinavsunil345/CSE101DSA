/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#4
* List.c
* List ADT C file
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "List.h"

typedef struct NodeObj* Node;


typedef struct NodeObj{
	ListElement data;
	Node next;
	Node prev;
} NodeObj;

typedef struct ListObj{
	 Node head;
	 Node tail;
	Node cursor;
	int l;
	int i;
}ListObj;

Node newNode(ListElement data){
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->next = NULL;
	N->prev = NULL;
	return(N);
	}
	
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}


List newList(void){
	List a;
	a = malloc(sizeof(ListObj));
	a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
	return a;
}

bool isEmpty(List a) {
	//printf("%d\n", a->l);
	if (a->l == 0){
		
		//printf("Hello\n");
		return true;
	}
	return false;
	//return(a->l==0);
}

	void freeList(List* d){
	if(d != NULL && *(d)!=NULL){
		clear((*d));
		}
		//clear(*(d));
		free(*d);
		*d = NULL;
	}
	
	



// Acess Functions

int length(List a){
	return a->l;
}


int index(List a){
	if(a == NULL){
	printf("List is NULL\n");
	exit(EXIT_FAILURE);
	}
	if(isEmpty(a)){
	////printf("List is empty\n");
	//exit(EXIT_FAILURE);
	}
	if (a->cursor == NULL){
		a->i = -1;
	}
	return a->i;
	}
	
ListElement front(List a){
	if(a == NULL){
	printf("List is NULL\n");
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	//return -9999999999999;
	exit(EXIT_FAILURE);
	}
	return a->head->data;
	}

ListElement back(List a){
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	//return;
	exit(EXIT_FAILURE);
	}
	return a->tail->data;
	}
	
ListElement get(List a){
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	//return;
	exit(EXIT_FAILURE);
	}
	if (a->i < 0){
		printf("Cursor has not been set\n");
		//return;
		exit(EXIT_FAILURE);
	}
	return a->cursor->data;
	}

// Manipulation Procedures

void clear(List a){
	if ( a->l == 1){
		Node tt = a->head;
		freeNode(&tt);
		a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
	return;
	}
	while (a->l > 2){
	moveBack(a);
	movePrev(a);
	delete(a);
	}
	Node temp = a->head;
	Node temp2 = a->tail;
	freeNode(&temp);
	freeNode(&temp2);
	a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
}
	

void set(List a, ListElement x){
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	} 
	if (a->i < 0){
		printf("Cursor has not been set\n");
		return;
		//exit(EXIT_FAILURE);
	}
		
	
	a->cursor->data = x;
}

void moveFront(List a){
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	} 
	
	a->cursor = a->head;
	a->i = 0;
//	printf("%d\n", a->cursor->data);
}

void moveBack(List a){
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	exit(EXIT_FAILURE);
	} 
	
	a->cursor = a->tail;
	a->i = (a->l-1);
}

void movePrev(List a) {
	if(a == NULL){
	printf("List is NULL\n");
	//return;
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	if (a->cursor == NULL){
		return;
	}
	if (a->cursor == a->head){
		a->cursor = NULL;
		return;
	}
	a->i = a->i - 1;
	a->cursor = a->cursor->prev;
	
}

void moveNext(List a) {
	if(a == NULL){
	printf("List is NULL\n");
	exit(EXIT_FAILURE);
	}
	
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	if (a->cursor == NULL){
		return;
	}
	if (a->cursor == a->tail){
		a->cursor = NULL;
		return;
	}
	
	a->cursor = a->cursor->next;
	a->i = a->i + 1;
	
}





void prepend(List a, ListElement data){
	Node temp = newNode(data);
	if ( isEmpty(a)){
		a->head = temp;
		a->tail = temp;
		a->l = a->l + 1;
		return;
	}
	temp->next = a->head;
	a->head->prev = temp;
	a->head = temp;
	//a->head->next->prev = a->head;
	a->l = a->l + 1;
	a->i = a->i + 1;
}

void append(List a, ListElement data){
	Node temp = newNode(data);
	if ( isEmpty(a)){
		a->head = temp;
		a->tail = temp;
		a->l = a->l + 1;
		return;
	}
	temp->prev = a->tail;
	a->tail->next = temp;
	a->tail = temp;
	a->l = a->l + 1;
	//printf("%d\n", a->head->data);
	//printf("%d\n", a->tail->data);
}

void insertBefore(List a, ListElement data){
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	if (a->i < 0){
		printf("Cursor is NULL\n");
	exit(EXIT_FAILURE);
	}
	if (a->cursor->prev == NULL){
		prepend(a,data);
		return;
	}
	Node temp = newNode(data);
	a->cursor->prev->next = temp;
	temp->prev = a->cursor->prev;
	a->cursor->prev = temp;
	temp->next = a->cursor;
	a->l = a->l + 1;
	a->i = a->i + 1;
}

void insertAfter(List a, ListElement data){
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	if (a->cursor == NULL){
		printf("Cursor is NULL\n");
	exit(EXIT_FAILURE);
	}
	if (a->cursor->next == NULL){
		append(a,data);
		return;
	}
	Node temp = newNode(data);
		
	a->cursor->next->prev = temp;
	temp->next = a->cursor->next;
	temp->prev = a->cursor;
	a->cursor->next = temp;
	a->l = a->l + 1;
}

void deleteFront(List a){
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	Node temp = NULL;
	temp = a->head;
	if (a->l == 1){
		a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
		freeNode(&temp);
		return;
	}
	if (a->head == a->cursor){
		a->cursor = NULL;
	}
	a->head = a->head->next;
	a->head->prev = NULL;
	a->i = a->i - 1;
	a->l = a->l - 1;
	freeNode(&temp);
}
	// Delete the front element. Pre: length()>0
void deleteBack(List a){
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
//	exit(EXIT_FAILURE);
	}
	Node temp = NULL;
	temp = a->tail;
	if (a->l == 1){
		a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
		freeNode(&temp);
		return;
	}
	if (a->tail == a->cursor){
	a->cursor = NULL;
	}
	a->tail = a->tail->prev;
	a->tail->next = NULL;
	a->l = a->l - 1;
	freeNode(&temp);

}	// Delete the back element. Pre: length()>0
void delete(List a){
	if(isEmpty(a)){
	//printf("List is empty\n");
	return;
	//exit(EXIT_FAILURE);
	}
	Node temp3 = NULL;
	temp3 = a->cursor;
	if (a->l == 1){
		a->head = NULL;
	a->tail = NULL;
	a->cursor = NULL;
	a->l = 0;
	a->i = -1;
		freeNode(&temp3);
		return;
	}
	if (a->cursor == a->head){
		deleteFront(a);
		return;
	}
	if (a->cursor == a->tail){
		deleteBack(a);
		return;
	}
	Node temp = a->cursor->next;
	Node temp2 = a->cursor->prev;
	//printf("%d\n", temp->data);
	//printf("%d\n", temp2->data);
	temp = a->cursor->next;
	temp2 = a->cursor->prev;
	temp2->next = temp;
	temp->prev = temp2;
	a->cursor = NULL;
	a->l = a->l - 1;
	freeNode(&temp3);
	
	
}// Delete cursor element, making cursor undefined.


/*void printList(FILE* out, List a){
	int num;
	Node* temp = a->head;
	if ( out==NULL ) {
		printf("Unable to write %s\n", argv[2]);
		exit(EXIT_FAILURE);
		}
	while (temp != NULL) {
		num = temp->data;
		fprintf(out, "%d\n", num);
		temp = temp->next;
		}
	fclose(out);
	
}*/


/*void printList(FILE * out, List a){
	if ( out==NULL ) {
		printf("Unable to write\n");
		return;
		//exit(EXIT_FAILURE);
		}
		
	Node temp = a->head;
	while (temp != NULL) {
		
		//fprintf(out, "%d ", temp->data);
		temp = temp->next;
		}
}*/





	