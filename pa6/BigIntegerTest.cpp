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
	 
	try{
      BigInteger J = BigInteger("");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   } 
   
   try{
      BigInteger J = BigInteger("+");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   
	string extest = "138";
	string extest2 = "-138";
	string leadingz = "-00000000000000000000000000000000000003456789";
	string s1 = "355797";
	string s2 = "149082";
	string s8 = "999";
	string s9 = "1000";
	string s3 = "9128734667000004389234563456345619187236478";
	string s4 = "9876545439000000000000000200000000000006543654365346534";
   BigInteger A = BigInteger(extest);
   BigInteger B = BigInteger(leadingz);
   
	BigInteger ZZ = A * B;
	cout << "ZZ: " << ZZ << endl;
   cout << endl;
   ZZ.negate();
   cout << "ZZ Negate: " << ZZ << endl;
   ZZ.makeZero();
   cout << "ZZ zero : " << ZZ << endl;

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
   
   /*
   
   string s1 = "9128734667000004389234563456345619187236478";
   //string s2 = "-330293847502398475";
   string s3 = "9876545439000000000000000200000000000006543654365346534";
   //string s4 = "9876545439000000000000000100000000000006543654365346534";
   //string s5 = "98765454390000000000000000000000000000065436543";
   //string s6 = "9876545439000000000000000000000000000006543";

   //BigInteger N;
   BigInteger A = BigInteger(s1);
   BigInteger B = BigInteger(s3);

   cout << endl;

   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
   cout << endl;

   BigInteger C = A+B;
   BigInteger D = B+A;
   BigInteger E = A-A;
   BigInteger F = B-A;
   BigInteger G = A*B;
   BigInteger H = B*A;
   BigInteger I = C*E;

   cout << "(A==B) = " << ((A==B)?"True":"False") << endl;
   cout << "(A<B)  = " << ((A<B)? "True":"False") << endl;
   cout << "(A<=B) = " << ((A<=B)?"True":"False") << endl;
   cout << "(A>B)  = " << ((A>B)? "True":"False") << endl;
   cout << "(A>=B) = " << ((A>=B)?"True":"False") << endl << endl;

   cout << "C = " << C << endl;
   cout << "D = " << D << endl;
   cout << "(C==D) = " << ((C==D)?"True":"False") << endl;
   cout << "E = " << E << endl;
   cout << "F = " << F << endl;
   cout << "G = " << G << endl;
   cout << "H = " << H << endl;
   cout << "(G==H) = " << ((G==H)?"True":"False") << endl;
   cout << "I = " << I << endl << endl;

   cout << endl;

   A += B;
   B -= C;
   C *= D;
   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
   cout << "C = " << C << endl;
   cout << endl;

   cout << A*B*C*D*F*G*H << endl << endl;

   cout << endl;

   // test exceptions
   try{
      BigInteger J = BigInteger("");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   } 
   try{
      BigInteger J = BigInteger("+");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("12329837492387492837492$4982379487293847");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("5298374902837409+82734098729287349827398");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
   */
   
  
  
}