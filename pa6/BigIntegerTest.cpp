/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#6
* BigIntegerTest.c
* Tester for BigInteger C file
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){
	string extest = "138";
	string extest2 = "-138";
	string leadingz = "00000000000000000000000000000000000003456789";
	string s1 = "355797";
	string s2 = "149082";
	string s8 = "999";
	string s9 = "1000";
	string s3 = "9128734667000004389234563456345619187236478";
	string s4 = "9876545439000000000000000200000000000006543654365346534";
 //  BigInteger A = BigInteger(extest);
   BigInteger B = BigInteger(leadingz);

   cout << endl;

//   cout << "A = " << A << endl;
   BigInteger Z = B - B;
   cout << "B = " << B << endl;
   cout << endl;
  
 /*  
  BigInteger C = A + B;
   A += B;
   B -= C;
   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
  BigInteger D = B + A;
  BigInteger G = A - B;

  
  //B -= A-B;
  cout << "G = " << G << endl;
  A -= C;
  cout << "A = " << A << endl;
  
  BigInteger Prod = A * B;
  cout << "A * B = " << Prod << endl;
  //cout << "D = "<< D << endl;
 
  string s5 = "101512";
  string s6 = "101010";
  
   BigInteger E = BigInteger(s5);
   BigInteger F = BigInteger(s6);
   E *= F;
   cout << "E = " << E << endl;*/
   
   
   
  
  
}