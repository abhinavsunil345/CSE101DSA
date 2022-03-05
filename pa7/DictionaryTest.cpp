//-----------------------------------------------------------------------------
// DictionaryClient.cpp
// A test client for the Dictionary ADT
//-----------------------------------------------------------------------------
/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#7
* DictionaryTest.cpp
* Test Client for Dictionary ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){
	 string y;
   int zs;
   string S[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};

   Dictionary A;
   for(int i=0; i<12; i++){
      A.setValue(S[i], i+1);
   }
   cout << A << endl;
   cout << A.pre_string() << endl;
   
   cout << "A.size() = " << A.size() << endl  << A << endl;
  Dictionary B = A;
  Dictionary C = B;
   A.remove("ten");
   cout << "A.size() = " << A.size() << endl  << A << endl;
   
   
   cout << "B.size() = " << B.size() << endl  << B << endl;
   
   A.begin();
   cout << "A.begin() = " << A.currentKey() << endl;
   
   A.end();
   cout << "A.end() = " << A.currentKey() << endl;
   
   A.prev();
   cout << "A.prev() = " << A.currentKey() << endl;
   
   if (A==C) {
	   cout << "A = C: true" << endl;
   }
   else {
	   cout << "A = C: false" << endl;
   }
    if (C==B) {
	   cout << "C = B: true" << endl;
   }
   else {
	   cout << "C = B: false" << endl;
   }
   A.clear();
   cout << A << endl;
    for(int i=0; i<12; i++){
      A.setValue(S[i], i+1);
   }
	cout << "A.size() = " << A.size() << endl  << A << endl;
	if (A==C) {
	   cout << "A = C: true" << endl;
   }
   else {
	   cout << "A = C: false" << endl;
   }
   
   /*
   string s;
   int x;
   string S[] = {"one", "two", "foo", "bar", "happy", "is", "three", "par"};

   Dictionary A;
   Dictionary B;

   cout << endl;

   // insert some pairs into A
   for(int i=0; i<8; i++){
      A.setValue(S[i], i+1);
   }
   
   // call operator=()
   B = A;

   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;

   B.setValue("bar", 9);

   // call copy constructor
   Dictionary C = B;

   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << "C.size() = " << C.size() << endl  << C << endl;

   // check operator==()
   cout << "A==B is " << (A==B?"true":"false") << endl;
   cout << "B==C is " << (B==C?"true":"false") << endl;
   cout << "C==A is " << (C==A?"true":"false") << endl << endl;

   // perform alterations on A
   cout << A.getValue("happy") << endl;
   A.getValue("happy") *= 10; // change the value associated with "happy"
   cout << A.getValue("happy") << endl << endl;
   A.remove("one");
   A.remove("two");

   // check state of A
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << A.pre_string() << endl;

   // do forward iteration on B
   for(B.begin(); B.hasCurrent(); B.next()){
      s = B.currentKey();
      x = B.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   // do reverse iteration on C
   for(C.end(); C.hasCurrent(); C.prev()){
      s = C.currentKey();
      x = C.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;
   

   // check exceptions
   try{
      A.getValue("blah");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.remove("blah");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentKey();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentVal();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }  
   try{
      A.next();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.prev();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;  
*/
   
   
  
	
}