/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#7
* Order.cpp
* Takes input file and and outputs Dictionary in order and pre order to output file
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include <cstdlib>
#include <iomanip>
#include"Dictionary.h"

using namespace std;


int main(int argc, char*argv[]){
	ifstream in;
   ofstream out;
   string line;
   Dictionary A;
  int linecount = 1;
   
    if( argc != 3 ){
    cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
    return(EXIT_FAILURE);
   }
   
   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }
   while (getline(in, line)) {
	   A.setValue(line, linecount);
	   linecount++;
   }
   out << A << endl;
   out << A.pre_string() << endl;
   
   in.close();
   out.close();

   return(EXIT_SUCCESS);
	
	
	
}