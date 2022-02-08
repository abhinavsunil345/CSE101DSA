/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#4
* MatrixTest.c
* Tester for Matrix C file
*********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Matrix.h"
     
int main(){
	 int n=100000;
   Matrix A = newMatrix(n);
   Matrix B = newMatrix(n);
   Matrix C, D, E, F, G, H;

   changeEntry(A, 1,1,1); changeEntry(B, 1,1,1);
   changeEntry(A, 1,2,2); changeEntry(B, 1,2,0);
   changeEntry(A, 1,3,3); changeEntry(B, 1,3,1);
   changeEntry(A, 2,1,4); changeEntry(B, 2,1,0);
   changeEntry(A, 2,2,5); changeEntry(B, 2,2,1);
   changeEntry(A, 2,3,6); changeEntry(B, 2,3,0);
   changeEntry(A, 3,1,7); changeEntry(B, 3,1,1);
   changeEntry(A, 3,2,8); changeEntry(B, 3,2,1);
   changeEntry(A, 3,3,9); changeEntry(B, 3,3,1);

   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);
   printf("\n");

   printf("%d\n", NNZ(B));
   printMatrix(stdout, B);
   printf("\n");

   C = scalarMult(1.5, A);
   printf("%d\n", NNZ(C));
   printMatrix(stdout, C);
   printf("\n");

   D = sum(A, B);
   printf("%d\n", NNZ(D));
   printMatrix(stdout, D);
   printf("\n");

   E = diff(A, A);
   printf("%d\n", NNZ(E));
   printMatrix(stdout, E);
   printf("\n");

   F = transpose(B);
   printf("%d\n", NNZ(F));
   printMatrix(stdout, F);
   printf("\n");

   G = product(B, B);
   printf("%d\n", NNZ(G));
   printMatrix(stdout, G);
   printf("\n");

   H = copy(A);
   printf("%d\n", NNZ(H));
   printMatrix(stdout, H);
   printf("\n");

   printf("%s\n", equals(A, H)?"true":"false" );
   printf("%s\n", equals(A, B)?"true":"false" );
   printf("%s\n", equals(A, A)?"true":"false" );

   makeZero(A);
   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);

   freeMatrix(&A);
   freeMatrix(&B);
   freeMatrix(&C);
   freeMatrix(&D);
   freeMatrix(&E);
   freeMatrix(&F);
   freeMatrix(&G);
   freeMatrix(&H);

   return EXIT_SUCCESS;

/*
Output of this program:
9
1: (1, 1.0) (2, 2.0) (3, 3.0)
2: (1, 4.0) (2, 5.0) (3, 6.0)
3: (1, 7.0) (2, 8.0) (3, 9.0)

6
1: (1, 1.0) (3, 1.0)
2: (2, 1.0)
3: (1, 1.0) (2, 1.0) (3, 1.0)

9
1: (1, 1.5) (2, 3.0) (3, 4.5)
2: (1, 6.0) (2, 7.5) (3, 9.0)
3: (1, 10.5) (2, 12.0) (3, 13.5)

9
1: (1, 2.0) (2, 2.0) (3, 4.0)
2: (1, 4.0) (2, 6.0) (3, 6.0)
3: (1, 8.0) (2, 9.0) (3, 10.0)

0

6
1: (1, 1.0) (3, 1.0)
2: (2, 1.0) (3, 1.0)
3: (1, 1.0) (3, 1.0)

7
1: (1, 2.0) (2, 1.0) (3, 2.0)
2: (2, 1.0)
3: (1, 2.0) (2, 2.0) (3, 2.0)

9
1: (1, 1.0) (2, 2.0) (3, 3.0)
2: (1, 4.0) (2, 5.0) (3, 6.0)
3: (1, 7.0) (2, 8.0) (3, 9.0)

true
false
true
0
*/
/*
  int n=10;
  // freeMatrix();
  Matrix A = newMatrix(n);
  Matrix B = newMatrix(n);
  Matrix C, D, E, F, G, H;
  */
/*
	changeEntry(A, 1,2,2); 
   changeEntry(A, 1,3,3); 
   changeEntry(A, 2,1,4); 
   changeEntry(A, 2,2,5); 
   changeEntry(A, 2,3,6); 
   changeEntry(A, 3,1,7); 
   changeEntry(A, 3,2,8); 
   changeEntry(A, 3,3,9);
     printf("%d\n", NNZ(A));
	printMatrix(stdout, A);
	printf("\n");
   freeMatrix(&A);
   */
  /* 
   changeEntry(A, 1,1,1); changeEntry(B, 1,1,1);
   changeEntry(A, 1,2,2); changeEntry(B, 1,2,0);
   changeEntry(A, 1,3,3); changeEntry(B, 1,3,1);
   changeEntry(A, 2,1,4); changeEntry(B, 2,1,0);
   changeEntry(A, 2,2,5); changeEntry(B, 2,2,1);
   changeEntry(A, 2,3,6); changeEntry(B, 2,3,0);
   changeEntry(A, 3,1,7); changeEntry(B, 3,1,1);
   changeEntry(A, 3,2,8); changeEntry(B, 3,2,1);
   changeEntry(A, 3,3,9); changeEntry(B, 3,3,1); 
   

   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);
   printf("\n");


   printf("%d\n", NNZ(B));
   printMatrix(stdout, B);
   printf("\n");
   */
   
   
 /*   C = scalarMult(1.5, A);
   printf("%d\n", NNZ(C));
   printMatrix(stdout, C);
   printf("\n");
   
    D = sum(A, B);
	printf("Sum\n");
   printf("%d\n", NNZ(D));
   printMatrix(stdout, D);
   printf("\n");
   
   E = diff(A, A);
   printf("%d\n", NNZ(E));
   printMatrix(stdout, E);
   printf("\n");
   
   F = transpose(B);
   printf("%d\n", NNZ(F));
   printMatrix(stdout, F);
   printf("\n");
   
   G = product(B, B);
   printf("G\n");
   printf("%d\n", NNZ(G));
   printMatrix(stdout, G);
   printf("\n");
   
   H = copy(A);
   printf("%d\n", NNZ(H));
   printMatrix(stdout, H);
   printf("\n");
   
  printf("%s\n", equals(A, H)?"true":"false" );
   printf("%s\n", equals(A, B)?"true":"false" );
   printf("%s\n", equals(A, A)?"true":"false" );
   */
   
  /* makeZero(A);
   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);
   
   changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
	
	C = scalarMult(-20, A);
	makeZero(A);
    D = scalarMult(-20, A);
	
	 changeEntry(A, 1, 1, 1);
    changeEntry(A, 2, 2, 1);
    changeEntry(A, 3, 3, 1);
   
   printf("%d\n", NNZ(A));
   printMatrix(stdout, A);
   
   
  freeMatrix(&A);
   freeMatrix(&B);
   freeMatrix(&C);
   freeMatrix(&D);
   */
  /* freeMatrix(&E);
   freeMatrix(&F);
   freeMatrix(&G);
   freeMatrix(&H);*/
   
  // A = transpose(A);
 //  printMatrix(stdout, A);
   

/* Matrix A = newMatrix(15);
 Matrix B = newMatrix(15);
 Matrix C, D;

 C = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(C, 1, 1, 1);
    if (equals(A, C)){
      printf("1\n");
	}
    D = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(A, 1, 3, 1);
    changeEntry(B, 1, 1, 1);
    changeEntry(B, 1, 3, 1);
    if (!equals(A, B))
      printf("1\n");
    changeEntry(A, 1, 3, 0);
    if (equals(A, B))
      return 3;
    changeEntry(A, 1, 1, 0);
    makeZero(B);
    changeEntry(A, 10, 10, 10);
    changeEntry(B, 10, 10, 10);
    if (!equals(A, B))
      return 4;

    freeMatrix(&A);
    freeMatrix(&B);*/
   /* A = newMatrix(100);
    B = newMatrix(100);
    int valcount = 1;
    for (int j = 1; j <= 100; j++) {
      for (int k = 1; k <= 100; k++) {
        // hint: this is 1-10000 left-to-right row-by-row
        changeEntry(A, j, k, valcount++);
      }
      changeEntry(B, j, j, 1); // hint: this is the identity matrix
    }
   // freeMatrix(&C);
   // freeMatrix(&D);
    C = scalarMult(2, A);
    D = sum(A, A);
    if (!equals(C, D))
      printf("Fail 5\n");

    freeMatrix(&C);
    freeMatrix(&D);
    C = scalarMult(-2, A);
    Matrix As1 = diff(A, A);
    Matrix As2 = diff(As1, A);
    D = diff(As2, A);
    freeMatrix(&As1);
    freeMatrix(&As2);
	printf("C \n");
	printf("C NNZ %d \n", NNZ(C));
	//printMatrix(stdout, C);
	printf("D \n");
	printf("D NNZ %d \n", NNZ(D));
	//printMatrix(stdout, D);
    if (!equals(C, D))
      printf("Fail 6\n");

    freeMatrix(&C);
    C = product(A, B);
    if (!equals(C, A))
      printf("Fail 7\n");

    return 0;
	*/
  }
 