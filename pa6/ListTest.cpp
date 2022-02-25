/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#6
* ListTest.c
* Tester for List C file
*********************************************************************************/
//-----------------------------------------------------------------------------
// ListTest.cpp
// A test client for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

int main(){
	List A;
	A.insertAfter(1);
	A.insertAfter(1);
	A.insertAfter(1);
	A.moveFront();
	while (A.peekNext() == 1) {
		A.eraseAfter();
		if (A.length() == 1) {
			break;
		}
	}
	A.peekNext();
	cout << A << endl;
	
}