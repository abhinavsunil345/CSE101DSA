// DictionaryClient.cpp
// A test client for the Dictionary ADT
//-----------------------------------------------------------------------------
/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#8
* DictionaryTest.cpp
* Test Client for Dictionary ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){
	
string S[] =   { // words to insert
                     "plaices",
                     "ambusher",
                     "crosby",
                     "wattles",
                     "pardoner",
                     "pythons",
                     "second",
                     "forms",
                     "impales",
                     "pic",
                     "verticals",
                     "recriminator",
                     "depressants",
                     "cul",
                     "potables",
                     "norm",
                     "reinsurer",
                     "deschooler",
                     "recoining",
                     "dissocialised",
                     "cohabit",
                     "hemiolia",
                     "cantling",
                     "glamorized",
                     "millesimal",
                     "glagolitic",
					 "Frams"
                  };
   string T[] =   { // words to delete
                     "second",
                     "forms",
                     "impales",
                     "pic",
                     "verticals",
                     "recriminator",
                     "depressants",
                     "cul",
                     "potables",
                     "norm",
                     "reinsurer",
                     "deschooler",
                     "recoining",      
                  };

   Dictionary A;
   Dictionary B;

   cout << endl;

   // insert some pairs into A
   for(int i=0; i<26; i++){
      A.setValue(S[i], i+1);
   }
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "A.pre_string() = "  << A.pre_string() << endl;
   B = A;
   
   cout << A << endl;
   cout << A.pre_string() << endl;
   
   cout << "A.size() = " << A.size() << endl  << A << endl;
  Dictionary C = B;
   A.remove("pythons");
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
   
}