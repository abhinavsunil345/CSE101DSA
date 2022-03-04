/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#7
* Dictionary.cpp
* Dictionary ADT C++ file
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include "Dictionary.h"


Dictionary::Node::Node(keyType k, valType v){
	key = k;
	val = v;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	
}

 

// Helper Functions (Optional) ---------------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
	if (R != nil) {
		inOrderString(s, R->left);
		s +=  (R->key + " : " + std::to_string(R->val) + "\n");
		inOrderString(s,R->right);
	}
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
	if (R != nil) {
		s +=  (R->key + "\n");
		preOrderString(s, R->left);
		preOrderString(s, R->right);
	}
	
	
}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
	if (R != N) {
		this->setValue(R->key, R->val);
		preOrderCopy(R->left, N);
		preOrderCopy(R->right, N);
	}
	
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R, sets R to nil.
void Dictionary::postOrderDelete(Node* R){
	if (R != nil) {
		postOrderDelete(R->left);
		postOrderDelete(R->right);
		delete(R);
	}
//	R = nil;
}

// search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
	if (R == nil || k == R->key) {
		return R;
	}
	else if (k < R->key) {
		return search(R->left, k);
	}
	else {
		return search(R->right, k);
	}
			
}

// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R) {
	while (R->left != nil) {
		R = R->left;
	}
	return R;
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
	while (R->right != nil) {
		R = R->right;
	}
	return R;
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N) {
	if (N->right != nil) {
		return findMin(N->right);
	}
	Node* Y = N->parent;
	while (Y != nil && N == Y->right){
		N = Y;
		Y = Y->parent;
	}
	return Y;
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N) {
	if (N->left != nil) {
		return findMax(N->left);
	}
	Node* Y = N->parent;
	while (Y != nil && N == Y->left){
		N = Y;
		Y = Y->parent;
	}
	return Y;
}

void Dictionary::transplant(Node* u, Node* v){
	if (u->parent == nil) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if (v != nil) {
		v->parent = u->parent;
	}
}

Dictionary::Dictionary() {
	nil = new Node("NIL", -1);
	root = nil;
	current = nil;
	num_pairs = 0;
	
	
}

// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
	nil = new Node("\000", -1);
	root = nil;
	current = nil;
	num_pairs = 0;
	//std::cout << "Copy " << std::endl;
	this->preOrderCopy(D.root, D.nil);
	//int x = num_pairs;
	//D.num_pairs = x;
}

// Destructor
Dictionary::~Dictionary() {
	this->postOrderDelete(this->root);
	delete nil;
	
}


// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const {
	return num_pairs;
	
	
}

// contains()
// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const {
	if (search(root,k) == nil) {
		return false;
	}
	return true;
	
	
}

// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const {
	if (this->contains(k) == false) {
		throw std::logic_error("Dictionary: getValue(): key \"" + k + "\" does not exist");
	}
	Node* result = search(root,k);
	return result->val;
	
	
		
	
	
}

// hasCurrent()
// Returns true if the current iterator is defined, and returns false 
// otherwise.
bool Dictionary::hasCurrent() const {
	if (current == nil) {
		return false;
	}
	return true;
	
	
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent() 
keyType Dictionary::currentKey() const {
	if (hasCurrent() == false) {
		throw std::logic_error("Dictionary: currentKey(): current undefined");
	}
	return current->key;
	
	
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const {
	if (hasCurrent() == false) {
		throw std::logic_error("Dictionary: currentVal(): current undefined");
	}
	return current->val;
	
}


// Manipulation procedures -------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear() {
	this->postOrderDelete(this->root);
	root = nil;
	current = nil;
	num_pairs = 0;
	
}

// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v, 
// otherwise inserts the new pair (k, v).
void Dictionary::setValue(keyType k, valType v) {
	Node* y = nil;
	Node* x = root;
	Node* z = new Node(k, v);
	z->left = nil;
	z->right = nil;
	//std::cout << x->key << std::endl;
	while (x != nil){
		//std::cout << "Hello" << std::endl;
		y = x;
		if (z->key == x->key) {
			x->val = z->val;
			delete z;
			return;
		}
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == nil) {
		this->root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
	
	this->num_pairs++;
	
}

// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k) {
	if (contains(k) == false) {
		throw std::logic_error("Dictionary: remove(): key \"" + k + "\" does not exist");
	}
	Node* z = search(root, k);
	if (z->left == nil) {
		transplant(z, z->right);
	}
	else if (z->right == nil) {
		transplant(z, z->left);
	}
	else {
		Node* y = findMin(z->right);
		if (y->parent != z) {
			transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
	if (z == current) {
		current = nil;
	}
	num_pairs--;	
	delete z;
}

// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::begin() {
	if (num_pairs == 0) {
		return;
	}
	current = findMin(root);
	
}

// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::end() {
	if (num_pairs == 0) {
		return;
	}
	current = findMax(root);
	
}

// next()
// If the current iterator is not at the last pair, advances current 
// to the next pair (as defined by the order operator < on keys). If 
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next() {
	if (hasCurrent() == false) {
		throw std::logic_error("Dictionary: next(): current not defined");
	}
	if (current == findMax(root)) {
		current = nil;
		return;
	}
	current = findNext(current);
	
}

// prev()
// If the current iterator is not at the first pair, moves current to  
// the previous pair (as defined by the order operator < on keys). If 
// the current iterator is at the first pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::prev() {
	if (hasCurrent() == false) {
		throw std::logic_error("Dictionary: prev(): current not defined");
	}
	if (current == findMin(root)) {
		current = nil;
		return;
	}
	current = findPrev(current);
	
}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value 
// are separated by the sequence space-colon-space " : ". The pairs are arranged 
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const {
	std::string s = "";
	this->inOrderString(s,this->root);
	return s;
	
	
}

// pre_string()
// Returns a string consisting of all keys in this Dictionary. Consecutive
// keys are separated by newline "\n" characters. The key order is given
// by a pre-order tree walk.
std::string Dictionary::pre_string() const {
	std::string s = "";
	this->preOrderString(s,this->root);
	return s;
	
}

// equals()
// Returns true if and only if this Dictionary contains the same (key, value)
// pairs as Dictionary D.
bool Dictionary::equals(const Dictionary& D) const {
	if (num_pairs != D.num_pairs) {
		return false;
	}
	//std::cout << D.to_string() << "\n" << to_string() << std::endl;
	if (D.to_string() != to_string()) {
		return false;
	}
	return true;
		
	
	
}


// Overloaded Operators ----------------------------------------------------

// operator<<()
// Inserts string representation of Dictionary D into stream, as defined by
// member function to_string().
std::ostream& operator<<( std::ostream& stream, Dictionary& D ) {
	return stream << D.Dictionary::to_string();

}
// operator==()
// Returns true if and only if Dictionary A equals Dictionary B, as defined
// by member function equals(). 
bool operator==( const Dictionary& A, const Dictionary& B ) {
	return A.Dictionary::equals(B);
}
// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ) {
	if (this != &D) {
		Dictionary temp = D;
		std::swap(nil, temp.nil);
		std::swap(root, temp.root);
		std::swap(current, temp.current);
		std::swap(num_pairs, temp.num_pairs);
	}
		return *this;
	
	
}