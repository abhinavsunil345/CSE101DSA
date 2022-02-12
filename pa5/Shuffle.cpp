/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#5
* Shuffle.c
* Takes input n and shuffles 1 to n cards finding how many shuffles until original is shuffle is reached
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include <cstdlib>
#include <iomanip>
#include"List.h"
using namespace std;

void shuffle(List &D) {
	List a;
	D.moveFront();
	for (int i = 0; i < D.length()/2; i++){
		a.insertBefore(D.peekNext());
		D.moveNext();
	}
	D.moveFront();
	int n = D.length()/2;
	for (int i = 0; i < n; i++){
		D.eraseAfter();
	}
	a.moveFront();
	D.moveFront();
	while (a.position() < a.length()){
		D.moveNext();
		D.insertBefore(a.peekNext());
		a.moveNext();
	}
}
int main(int argc, char*argv[]){
	if( argc != 2 ){
      cerr << "Usage: " << argv[0] << " <input n> <output file>" << endl;
      return(EXIT_FAILURE);
   }
   
	int n = atoi(argv[1]);
	List a, b;
	int counter = 0;
	int z = 0;
	cout << "deck size " << setw(20) << "shuffle count" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < n; i++){
		b.moveBack();
		a.moveBack();
		a.insertAfter(i);
		b.insertAfter(i);
		while (z == 0){
		shuffle(a);
		if (a == b) {
			z++;
		}
		counter++;
		}
		cout << setw(2) <<  i+1 << setw(17) << counter << endl;
		counter = 0;
		z = 0;
	}
};