/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#1
* Lex.c
* Indirect Sorting for Linked List
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"
#include <string.h>

int main(int argc, char* argv[]){

FILE* in;
FILE* out;
char word[256];
int s = 0;
//List L = newList();


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
	//out = fopen(argv[2], "w");
	List L = newList();
		if ( out==NULL ) {
			printf("Unable to write %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		
			while (fgets(word, 256, in) != NULL) { 
		//printf("%s\n", word);
		s++;
		}
		

		char **ptr = (char**)malloc(sizeof(char**) * s);
		int i = 0;
		rewind(in);
	 while (fgets(word, 256, in) != NULL) {
		 if ((i+1) != s){
		 word[strlen(word) - 1] = '\0';
		 }
//	while (fscanf(in, "%[^\n]s", word) != EOF) {
		//printf("%d\n", i);
	//	printf("%s\n", i);
		ptr[i] = (char*)malloc(sizeof(char) * (strlen(word)+1));
		strcpy(ptr[i], word);
	//	fprintf(out, "%s\n", word);
		i++;
		}
		for (int i = 0; i < s; i++){
			//printf("%s\n", ptr[i]);
		}
		
		prepend(L,0);
		
			for (int i = 1;  i < s; i++){
				for (moveFront(L); index(L) >= 0; moveNext(L)){
				//fprintf(out, "List Element: %d %s Index: %d Length: %d\n", get(L), ptr[i], index(L), length(L));
				if (strcmp(ptr[i], ptr[get(L)]) <= 0){
						insertBefore(L,i);
						break;
					}
				}
				if (index(L) < 0){
						append(L,i);
					}
			}
			
			moveFront(L);
			for (int i = 0; i < length(L); i++){
			fprintf(out,"%s\n", ptr[get(L)]);
			moveNext(L);
			}
			
			for (int i = 0; i < s; i++){
				free(ptr[i]);
			}
		
	fclose(in);
	fclose(out);
	free(ptr);
	freeList(&L);
	return(EXIT_SUCCESS);
	}
	