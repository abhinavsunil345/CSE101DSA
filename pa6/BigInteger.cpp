/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#6
* BigInteger.cpp
* BigInteger ADT cpp file
*********************************************************************************/
#include<iostream>
#include<string>
#include "BigInteger.h"

// Class Constructors & Destructors ----------------------------------------
// BigInteger()
// Constructor that creates a new BigInteger in the zero state: 
// signum=0, digits=().
		
const long base = 1000000000;
const int power = 9;
//const long base = 100;
//const int power = 2;
void negateList(List &L){
	//std::cout << "Before Negate L " << L << std::endl;
	L.moveFront();
	while (L.position() < L.length()){
		L.setAfter(L.peekNext() * -1);
		L.moveNext();
	}
	//std::cout << "Negate L " << L << std::endl;
}

void sumList(List& S, List A, List B, int sgn) {
	S.clear();
	int smaller = 0;
	int larg = 0;
	long sum = 0;
	A.moveBack();
	B.moveBack();
	if (sgn == -1) {
		negateList(B);
	}
	if (A.length() > B.length()){
		smaller = B.length();
		larg = 1;
	}
	else {
		//std::cout << "Yes" << std::endl;
		smaller = A.length();
	}
	for (int i = 0; i < smaller; i++){
		sum = A.peekPrev() + B.peekPrev();
		S.insertAfter(sum);
		A.movePrev();
		B.movePrev();
	}
	//std::cout << "S1 : " << S << std::endl;
	if (larg == 0){
		while (B.position() > 0) {
			S.insertAfter(B.peekPrev());
			B.movePrev();
			//std::cout << "S2 : " << S << std::endl;
		}
	}
	if (larg == 1){
		while (A.position() > 0) {
			S.insertAfter(A.peekPrev());
			A.movePrev();
		}
	}
	S.moveFront();
	while (S.peekNext() == 0) {
		if (S.length() <= 1){
			break;
		}
		S.eraseAfter();
	}
	//std::cout << "S : " << S << std::endl;
	//std::cout << "S : " << S << std::endl;
}

bool numString(std::string &s, int max){
	std::string j = s;
	for (int i = 0; i < max; i++){
		if (isdigit(j[i]) == false) {
			if (j[i] != '+' && j[i] != '-'){
			//	std::cout << "Here " << j[i] << std::endl;
			return false;
			}
			if (max == 1) {
				return false;
			}
			if (i != 0){
				return false;
			}
		}
	}
	return true;
}

int normalizeList(List &L){
	//std::cout << "L1 Before: " << L << std::endl;
	int sign = 75;
	int carry = 0;
	L.moveBack();
	while (L.position() > 0){
		L.setBefore(L.peekPrev() + carry);
		if ((L.peekPrev()) >= base ) {
			carry = L.peekPrev() / base;
			L.setBefore(L.peekPrev() % base);
			//std::cout << "carry : " << carry << std::endl;
			//std::cout << "L : " << L << std::endl;
		}
		else if ((L.peekPrev()) < 0) {
				if (L.position() > 1){
				L.setBefore(L.peekPrev() + base);
				}
			carry = -1;
		}
		else {
			carry = 0;
		}
		L.movePrev();
	}	
	if (carry > 0) {
			L.insertAfter(carry);
		}
	if (carry == -1) {
			negateList(L);
			//std::cout << "Negate L : " << L << std::endl;
			normalizeList(L);
			sign = -1;
			return sign;
	}
	L.moveFront();
	while (L.position() < L.length()){
		if (L.peekNext() != 0){
			break;
		}
		sign = 0;
		return sign;
	}
	 
		sign = 1;
	//std::cout << "L : " << L << std::endl;
	return sign;
}

void shiftList(List& L, int p) {
	L.moveBack();
	for (int i = 0 ; i < p; i++){
		L.insertBefore(0);
	}
}

void scalarMultList(List& L, ListElement m){
	L.moveBack();
	while (L.position() > 0){
		L.setBefore(L.peekPrev() * m);
		L.movePrev();
	}
}
		
BigInteger::BigInteger(){
	signum = 0;
	
}

// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s){
	int x = 0;
	std::string lead = "";
	if (s.empty() == true){
		throw std::invalid_argument("BigInteger: Constructor: empty string");
	}
	
	if (numString(s, s.length()) == false){
		throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
	}
	signum = 1;
	if (s.front() == '-') {
		signum = -1;
		s.erase(s.begin(), s.begin() + 1);
	//	std::cout << s << std::endl;
	}
	
	if (s.front() == '+') {
		s.erase(s.begin(), s.begin() + 1);
	//	std::cout << s << std::endl;
	}
//	std::cout << s.length() << std::endl;
	int rem = s.length() % power;
	if (rem != 0) {
		rem = power - rem;
	}
	//std::cout << "Rem: " << rem << std::endl;
	for (int i = 0; i < rem; i++){
		lead += "0";
	}
	s = lead + s;
	int div = s.length() / power;
	/*for (int i = 0; i < rem; i++){
		lead += "0";
	}
	s = lead + s;
	std::cout << s << std::endl*/
	std::string t;
	int r = x;
	for (int i = x; i < div; i++){
		t = s.substr(r,power);
		//std::cout << t << std::endl;
		digits.insertBefore(stol(t));
		r += power;
}
//std::cout << "Digits: " << digits << std::endl;
	digits.moveFront();
	while (digits.peekNext() == 0) {
		if (digits.length() <= 1){
			break;
		}
		digits.eraseAfter();
	}
	

 //std::cout << digits;

}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N){
	//std::cout << "Hello" << std::endl;
	this->signum = N.signum;
	this->digits = N.digits;
	
	
}

// Optional Destuctor
// ~BigInteger()
// ~BigInteger();


// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is positive, 
// negative or 0, respectively.
int BigInteger::sign() const {
	return signum;
	
	
}

// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const{
	if (this->signum > N.signum){
		return 1;
	}
	
	if (this->signum < N.signum) {
		return -1;
	}
	
	if (this->digits.length() > N.digits.length()) {
		return 1;
	}
	
	if (this->digits.length() < N.digits.length()) {
		return -1;
	}
	List a  = this->digits;
	List b = N.digits;
	a.moveFront();
	b.moveFront();
	while (a.position() < a.length()){
		if (a.peekNext() > b.peekNext()) {
			return 1;
		}
		
		if (a.peekNext() < b.peekNext()) {
			return -1;
		}
		a.moveNext();
		b.moveNext();
	}
	return 0;

	
	
}


// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero(){
	this->signum = 0;
	this->digits.clear();
	
	
	
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of 
// this BigInteger positive <--> negative. 
void BigInteger::negate(){
	if (this->digits.length() == 1) {
		if (this->digits.front() == 0) {
			return;
		}
	}
	this->signum = this->signum * -1;
	
	
}


// BigInteger Arithmetic operations ----------------------------------------

// add()
// Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& N) const {
	int sign = 1;
	BigInteger t;
	List a  = this->digits;
	//std::cout << "signum " << this->signum << std::endl;
	if (this->signum == -1) {
	//	std::cout << "List A :" << a << std::endl;
		negateList(a);
	}
//	std::cout << "List A :" << a << std::endl;
	if (N.signum == -1) {
		sign = -1;
	}
	List b = N.digits;
	sumList(t.digits, a, b, sign);
	t.signum = normalizeList(t.digits);
	if (t.signum == 0) {
		//std::cout << "0" << std::endl;
		t.digits.clear();
		t.digits.insertAfter(0);
	}
	return t;
	
}

// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const{
	int sign = -1;
	BigInteger t;
	List a  = this->digits;
//	std::cout << "signum " << this->sum << std::endl;
	if (this->signum == -1) {
	//	std::cout << "List A :" << a << std::endl;
		negateList(a);
	}
//	std::cout << "List A :" << a << std::endl;
	if (N.signum == -1) {
		sign = 1;
	}
	List b = N.digits;
	sumList(t.digits, a, b, sign);
	t.signum = normalizeList(t.digits);
	if (t.signum == 0) {
		t.digits.clear();
		t.digits.insertAfter(0);
	}
	return t;
	
}

// mult()
// Returns a BigInteger representing the product of this and N. 
BigInteger BigInteger::mult(const BigInteger& N) const {
	BigInteger t;
	List product;
	product.insertAfter(0);
	List a  = this->digits;
	List c;
	List b = N.digits;
	int shift = 1;
	t.signum = N.signum * this->signum;
	if (t.signum == 0){
		t.digits.insertAfter(0);
		return t;
	}
	if (a.length() >= b.length()){
		c = a;
		b.moveBack();
		while(b.position() > 0){
			scalarMultList(c,b.peekPrev());
			//std::cout << "scalar mult before Norm Result: " << c << std::endl;
			normalizeList(c);
			//std::cout << "scalar mult Result: " << c << std::endl;
		    sumList(product,product,c,1);
			c = a;
			shiftList(c,shift);
			shift++;
			b.movePrev();
		}
	}
	
	if (a.length() < b.length()){
		c = b;
		a.moveBack();
		while(a.position() > 0){
			scalarMultList(c,a.peekPrev());
			normalizeList(c);
		    sumList(product,product,c,1);
			c = b;
			shiftList(c,shift);
			shift++;
			a.movePrev();
		}
	}
	normalizeList(product);
	t.digits = product;
	//std::cout << "Mult Result: " << product << std::endl;
	
	return t;
}
	



// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string 
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string() {
	//std::cout << "NN " << std::endl;
	//std::cout <<  "digits: " << digits << std::endl;
	std::string ret = "";
	std::string lead = "";
	int rem = 0;
	
	if (signum == -1){
		ret += "-";
	}
	digits.moveFront();
	//std::cout << digits.peekNext() << std::endl;
	
	while(digits.position() < digits.length()){
		//std::cout << "Digits : " << digits << std::endl;
		lead = std::to_string(digits.peekNext());
		//std::cout << "lead: " << lead << std::endl;
		rem = power - lead.length();
		//std::cout << "rem: " << rem << std::endl;
		if (digits.position() != 0) {
			for (int i = 0; i < rem; i++){
			//std::cout << "lead: " << lead << std::endl;
			//std::cout << ret << std::endl;
			ret += "0";
			}
			}
		digits.moveNext();
		ret += lead;
	}
	
	return ret;
	

	
}


// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ){
	
	return stream << N.BigInteger::to_string();
	
	
}

// operator==()
// Returns true if and only if A equals B. 
bool operator==( const BigInteger& A, const BigInteger& B ){
	int a = A.BigInteger::compare(B);
	if (a == 0) {
		return true;
	}
	return false;
	
}

// operator<()
// Returns true if and only if A is less than B. 
bool operator<( const BigInteger& A, const BigInteger& B ){
	int a = A.BigInteger::compare(B);
	if (a == -1) {
		return true;
	}
	return false;
	
	
	
}

// operator<=()
// Returns true if and only if A is less than or equal to B. 
bool operator<=( const BigInteger& A, const BigInteger& B ){
	int a = A.BigInteger::compare(B);
	if (a == 1) {
		return false;
	}
	
	return true;
	
	
}

// operator>()
// Returns true if and only if A is greater than B. 
bool operator>( const BigInteger& A, const BigInteger& B ){
	int a = A.BigInteger::compare(B);
	if (a == 1) {
		return true;
	}
	return false;
	
	
}

// operator>=()
// Returns true if and only if A is greater than or equal to B. 
bool operator>=( const BigInteger& A, const BigInteger& B ){
	int a = A.BigInteger::compare(B);
	if (a == -1) {
		return false;
	}
	
	return true;
	
	
}

// operator+()
// Returns the sum A+B. 
BigInteger operator+( const BigInteger& A, const BigInteger& B ){
	return A.BigInteger::add(B);
	
	
	
}

// operator+=()
// Overwrites A with the sum A+B. 
BigInteger operator+=( BigInteger& A, const BigInteger& B ){
	A = A.BigInteger::add(B);
	return A;
	
	
}

// operator-()
// Returns the difference A-B. 
BigInteger operator-( const BigInteger& A, const BigInteger& B ){
	return A.BigInteger::sub(B);
	
	
}

// operator-=()
// Overwrites A with the difference A-B. 
BigInteger operator-=( BigInteger& A, const BigInteger& B ){
	A = A.BigInteger::sub(B);
	return A;
	
	
}

// operator*()
// Returns the product A*B. 
BigInteger operator*( const BigInteger& A, const BigInteger& B ){
	return A.BigInteger::mult(B);
	
	
}

// operator*=()
// Overwrites A with the product A*B. 
BigInteger operator*=( BigInteger& A, const BigInteger& B ){
	A = A.BigInteger::mult(B);
	return A;
	
	
	
}
