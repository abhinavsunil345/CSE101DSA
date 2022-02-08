/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#4
* Sparse.c
* Takes input file parses to create Matix A and B parses then runs,(1.5)𝐴, 𝐴 + 𝐵,𝐴 + 𝐴, 𝐵 − 𝐴, 𝐴 − 𝐴, 𝐴𝑇, 𝐴𝐵 and 𝐵2 on Matrices and outputs the result.
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Matrix.h"

int main(int argc, char* argv[]){
	FILE* in;
FILE* out;
int n = 0;
int a = 0;
int b = 0;
int row = 0;
int col = 0;
double val = 0.0;
Matrix A,B,C,D,E,F,G,H,I,J;

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

	fscanf(in, "%d %d %d", &n, &a, &b);
	//fscanf(in, "");
	//printf("%d %d %d\n", n, a, b);
	A = newMatrix(n);
	B = newMatrix(n);
	//printf("\n");
	for (int i = 0; i < a; i++) {
		fscanf(in, "%d %d %lf", &row, &col, &val);
		//printf("%d %d %f\n", row, col, val);
		changeEntry(A, row, col, val);
		
	}
	//printMatrix(stdout, A);
	for (int i = 0; i < b; i++) {
		fscanf(in, "%d %d %lf", &row, &col, &val);
		//printf("%d %d %f\n", row, col, val);
		changeEntry(B, row, col, val);
		
	}
	fprintf(out, "A has %d non-zero entries:\n", NNZ(A));
	printMatrix(out, A);
	fprintf(out,"\n");
	
	fprintf(out,"B has %d non-zero entries:\n", NNZ(B));
	printMatrix(out, B);
	fprintf(out,"\n");
	
	fprintf(out,"(1.5)*A =\n");
	C = scalarMult(1.5, A);
	printMatrix(out, C);
	fprintf(out,"\n");
	
	fprintf(out,"A+B =\n");
	D = sum(A, B);
	printMatrix(out, D);
	fprintf(out,"\n");
	
	
	fprintf(out,"A+A =\n");
	E = sum(A, A);
	printMatrix(out, E);
	fprintf(out,"\n");
	
	fprintf(out,"B-A =\n");
	F = diff(B, A);
	printMatrix(out, F);
	fprintf(out,"\n");
	
	fprintf(out,"A-A =\n");
	G = diff(A, A);
	printMatrix(out, G);
	fprintf(out,"\n");
	
	fprintf(out,"Transpose(A) =\n");
	H = transpose(A);
	printMatrix(out, H);
	fprintf(out,"\n");
	
	fprintf(out,"A*B =\n");
	I = product(A, B);
	printMatrix(out, I);
	fprintf(out,"\n");
	
	fprintf(out,"B*B =\n");
	J = product(B, B);
	printMatrix(out, J);
	fprintf(out,"\n");
	
	
   freeMatrix(&A);
   freeMatrix(&B);
  freeMatrix(&C);
 freeMatrix(&D);
 freeMatrix(&E);
 freeMatrix(&F);
  freeMatrix(&G);
  freeMatrix(&H);
  freeMatrix(&I);
  freeMatrix(&J); 
   
   
	fclose(in);
	fclose(out);

return(EXIT_SUCCESS);
	
	
	
	
	
	
	
	
}