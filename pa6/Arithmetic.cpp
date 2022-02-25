/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#6
* Shuffle.c
* Takes input file and runs operations 𝐴, 𝐵, 𝐴 + 𝐵, 𝐴 − 𝐵, 𝐴 − 𝐴, 3𝐴 − 2𝐵, 𝐴𝐵, 𝐴^2, 𝐵^2, 9𝐴^4 + 16𝐵^5 and outputs to output file
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include <cstdlib>
#include <iomanip>
#include"BigInteger.h"

using namespace std;


int main(int argc, char*argv[]){
	
   ifstream in;
   ofstream out;
   string line;
   
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
   getline(in,line);
   BigInteger A(line);
   getline(in,line);
   getline(in,line);
   BigInteger B(line);
   out << A << endl << endl;
   out << B << endl << endl;
   out << (A + B) << endl << endl;
   out << (A - B) << endl << endl;
   out << (A - A) << endl << endl;
   BigInteger C("3");
   BigInteger D("2");
    BigInteger E("9");
   BigInteger F("16");
   out << ((C * A) - (D * B)) << endl << endl;
   out << (A * B) << endl << endl;
   out << (A * A) << endl << endl;
   out << (B * B) << endl << endl;
   out << ((E * (A * A * A * A)) + (F * (B * B * B * B * B))) << endl << endl;
   in.close();
   out.close();

   return(EXIT_SUCCESS);
	
}