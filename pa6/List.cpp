/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#6
* List.c
* List ADT C++ file
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include "List.h"

// Private Constructor 

// Node constructor

List::Node::Node(ListElement x){
	data = x;
	next = nullptr;
	prev = nullptr;
}

// Class Constructors and Destructors

// default empty state constructor
List::List() {
   frontDummy = new Node(-1);
   backDummy = new Node(-2);
   backDummy->prev = frontDummy;
   frontDummy->next = backDummy;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0;
}

// copy constructor

List::List(const List& L){
	//std::cout << "Copy" << std::endl;
    frontDummy = new Node(-1);
   backDummy = new Node(-2);
   backDummy->prev = frontDummy;
   frontDummy->next = backDummy;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0;
   
   
   Node* N = L.frontDummy->next;
   
   while (N!= L.backDummy){
	   this->insertBefore(N->data);
	   N = N->next;
   }
   pos_cursor = 0;
  // std::cout << "Copy " << L.pos_cursor;
}

List::~List(){
	this->clear();	
	delete frontDummy;
	delete backDummy;
	
}

// Acess functions

int List::length() const{
	return num_elements;
}

ListElement List::front() const{
	if (num_elements == 0){
		throw std::length_error("List: front(): empty list");
	}
	return (frontDummy->next->data);
}

ListElement List::back() const{
	if (num_elements == 0){
		throw std::length_error("List: back(): empty list");
	}
	return (backDummy->prev->data);
}

int List::position() const {
	return pos_cursor;
}

ListElement List::peekNext() const{
	if (pos_cursor >= num_elements){
		throw std::range_error("List: peekNext(): cursor at back");
	}
	return (afterCursor->data);
}

ListElement List::peekPrev() const{
	if (pos_cursor <= 0){
		throw std::range_error("List: peekPrev(): cursor at front");
	}
	return (beforeCursor->data);
}

// Manipulation Procedures

void List::clear() {
	this->moveFront();
	//std::cout << num_elements << std::endl;
	while (num_elements > 0){
		eraseAfter();
	}
}

void List::moveFront() {
	pos_cursor = 0;
	beforeCursor = frontDummy;
	afterCursor = frontDummy->next;
}

void List::moveBack() {
	pos_cursor = num_elements;
	beforeCursor = backDummy->prev;
	afterCursor = backDummy;
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<length() 
ListElement List::moveNext(){
	if (pos_cursor >= num_elements){
		throw std::range_error("List: moveNext(): cursor at back");
	}
	ListElement x;
	x = afterCursor->data;
	pos_cursor++;
	beforeCursor = beforeCursor->next;
	afterCursor = afterCursor->next;
	return x;
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
ListElement List::movePrev(){
	if (pos_cursor <= 0){
		throw std::range_error("List: movePrev(): cursor at front");
	}
	//std::cout << "Cursor " << pos_cursor << std::endl;
	ListElement x;
	x = beforeCursor->data;
	pos_cursor--;
	beforeCursor = beforeCursor->prev;
	afterCursor = afterCursor->prev;
	//std::cout << "MP " << x << std::endl;
	return x;
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x){
	Node *n = new Node(x);
	n->prev = beforeCursor;
	n->next = afterCursor;
	afterCursor->prev = n;
	beforeCursor->next = n;
	afterCursor = n;
	num_elements++;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x){
	Node *n = new Node(x);
	n->prev = beforeCursor;
	n->next = afterCursor;
	afterCursor->prev = n;
	beforeCursor->next = n;
	beforeCursor = n;
	num_elements++;
	pos_cursor++;
}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x){
	if (pos_cursor >= num_elements){
		throw std::range_error("List: setAfter(): cursor at back");
	}
		
	afterCursor->data = x;
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x){
	if (pos_cursor <= 0){
		throw std::range_error("List: setBefore(): cursor at front");
	}
	beforeCursor->data = x;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<length()
void List::eraseAfter(){
	if (pos_cursor >= num_elements){
		throw std::range_error("List: eraseAfter(): cursor at back");
	}
	Node* n = afterCursor;
	afterCursor = n->next;
	//std::cout << n->data << std::endl;
	beforeCursor->next = afterCursor;
	afterCursor->prev = beforeCursor;
	num_elements--;
	delete n;
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore(){
	if (pos_cursor <= 0){
		throw std::range_error("List: eraseBefore(): cursor at front");
	}
	Node* n = beforeCursor;
	beforeCursor = n->prev;
	beforeCursor->next = afterCursor;
	afterCursor->prev = beforeCursor;
	num_elements--;
	pos_cursor--;
	delete n;
}


// Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of element x. If x
// is found, places the cursor immediately after the found element, then 
// returns the final cursor position. If x is not found, places the cursor 
// at position length(), and returns -1. 
int List::findNext(ListElement x){
	while (pos_cursor < num_elements){
		if (this->moveNext() == x){
			return pos_cursor;
		}
	}
	return -1;
	
	
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of element x. If x
// is found, places the cursor immediately before the found element, then
// returns the final cursor position. If x is not found, places the cursor 
// at position 0, and returns -1. 
int List::findPrev(ListElement x){
	while (pos_cursor > 0){
		if (this->movePrev() == x){
			return pos_cursor;
		}
		
	}
	return -1;
	
	
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost 
// occurrance of each element, and removing all other occurances. The cursor 
// is not moved with respect to the retained elements, i.e. it lies between 
// the same two retained elements that it did before cleanup() was called.
void List::cleanup(){
	int counter = 0;
	int counter2 = 1;
	Node *T = frontDummy->next;
	Node *N;
	ListElement x;
	while (T != backDummy){
		x = T->data;
		N = T->next;
		while (N != backDummy) {
			if (N->data == x) {
				if (N == beforeCursor) {
					beforeCursor = beforeCursor->prev;
				}
				if (N == afterCursor) {
					afterCursor = afterCursor->next;
				}
				//std::cout << x << " " << N->data << std::endl;
				//std::cout << "Y " << counter << " + " << counter2 << " " << pos_cursor << std::endl;
				N->next->prev = N->prev;
				N->prev->next = N->next;
				num_elements--;
				Node* temp = N;
				N = N->next;
				delete temp;
				if ((counter + counter2) < pos_cursor) {
				//	std::cout << "Y " << counter + counter2 << " " << pos_cursor << std::endl;
					pos_cursor--;
					counter2--;
				}
			}
			else {
				//std::cout << "Out of Loop" << std::endl;
				N = N->next;
			}
			//std::cout << N->data << std::endl;
		counter2++;
		}
		counter2 = 1;
		T = T->next;
		counter++;
	}
		
	
}
 
// concat()
// Returns a new List consisting of the elements of this List, followed by
// the elements of L. The cursor in the returned List will be at postion 0.
List List::concat(const List& L) const{
	List A = *this;
	Node* N = L.frontDummy->next;
	while (N != L.backDummy){
		A.insertBefore(N->data);
		N = N->next;
	}
	A.moveFront();
	//std::cout << A.position() << std::endl;
	return A;
}

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() const {
	Node *N = nullptr;
	std::string s = "";
	s += "(";
	for(N=frontDummy->next; N!=backDummy; N=N->next){
		s += std::to_string(N->data) + ", ";
	}
	s.erase(s.end()-2, s.end());
	s += ")";
	return s;
	
}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) const {
	
	Node* N = nullptr;
    Node* M = nullptr;
	if (this->num_elements != R.num_elements){
		return false;
	}
	N = this->frontDummy->next;
	M = R.frontDummy->next;
	
	while ( N!= this->backDummy){
		if (N->data != M->data){
			return false;
		}
		N = N->next;
		M = M->next;
	}
	return true;
}
	


// Overriden Operators -----------------------------------------------------
   
// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ){
		return stream << L.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged.
bool operator==( const List& A, const List& B ){
		return A.List::equals(B);
	
	
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ){
	if (this != &L) {
		List temp = L;
		//std::cout << "=: " << temp.pos_cursor << std::endl;
		std::swap(frontDummy, temp.frontDummy);
		std::swap(backDummy, temp.backDummy);
		std::swap(beforeCursor, temp.beforeCursor);
		std::swap(afterCursor, temp.afterCursor);
		std::swap(num_elements, temp.num_elements);
		//std::cout << "CCT: " << pos_cursor << std::endl;
		std::swap(pos_cursor, temp.pos_cursor);
	}
	
	return *this;
}


