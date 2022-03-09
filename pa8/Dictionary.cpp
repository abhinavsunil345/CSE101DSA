/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#8
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
	color = 0;
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
		//s +=  (R->key + " : " + std::to_string(R->val) + "\n");
		s.append(R->key).append(" : ").append(std::to_string(R->val)).append("\n");
		/*s += R->key;
		s += " : ";
		s += (std::to_string(R->val));
		s += "\n";
		*/
		
		inOrderString(s,R->right);
	}
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
	if (R != nil) {
		//s +=  (R->key + "\n");
		s.append(R->key).append("\n");
		/*s += R->key;
		s += "\n";
		*/
		preOrderString(s, R->left);
		preOrderString(s, R->right);
	}
	
	
}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
	//std::cout << "This Far " << R->key << R->val << std::endl;
	if (R != N) {
	//	std::cout << "Past check " << R->key << R->val << std::endl
		this->setValue(R->key, R->val);
	//	std::cout << "Past set " << R->key << R->val << std::endl;
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


 // LeftRotate()
   void Dictionary::LeftRotate(Node* N) {
	   Node* Y = N->right;
	   N->right = Y->left;
	   if (Y->left != nil){
		Y->left->parent = N;
	   }
	   
	   Y->parent = N->parent;
	   if (N->parent == nil){
		   root = Y;
	   }
	   else if (N == N->parent->left) {
		   N->parent->left = Y;
	   }
	   else {
		   N->parent->right = Y;
	   }
	   
	   Y->left = N;
	   N->parent = Y;
	   
   }

   // RightRotate()
   void Dictionary::RightRotate(Node* N) {
	  // std::cout << "This Far RRotate " << N->key << N->val << std::endl;
	   Node* Y = N->left;
	   
	   // turn y's right subtree into x's left subtree
	   N->left = Y->right;
	   
	   if (Y->right != nil){
		Y->right->parent = N;
	   }
	   
	   Y->parent = N->parent;
	   if (N->parent == nil){
		   root = Y;
	   }
	   else if (N == N->parent->right) {
		   N->parent->right = Y;
	   }
	   else {
		   N->parent->left = Y;
	   }
	   
	   Y->right = N;
	   N->parent = Y;
	   
	   
	   
    }

   // RB_InsertFixUP()
   void Dictionary::RB_InsertFixUp(Node* N){
	   Node* y;
	while (N->parent->color == 1) {
		if (N->parent == N->parent->parent->left){
			y = N->parent->parent->right;
			if (y->color == 1) {
				N->parent->color = 0;
				y->color = 0;
				N->parent->parent->color = 1;
				N = N->parent->parent;
			}
			else {
				if (N == N->parent->right) {
					N = N->parent;
					LeftRotate(N);
				}
				N->parent->color = 0;
				N->parent->parent->color = 1;
				RightRotate(N->parent->parent);
			}
		}
		else {
			y = N->parent->parent->left;
			if (y->color == 1) {
				N->parent->color = 0;
				y->color = 0;
				N->parent->parent->color = 1;
				N = N->parent->parent;
			}
			else {
				if (N == N->parent->left) {
					N = N->parent;
					//std::cout << "This Far " << N->key << N->val << std::endl;
					RightRotate(N);
				}
				N->parent->color = 0;
				N->parent->parent->color = 1;
				LeftRotate(N->parent->parent);
			}
		}
	}
			root->color = 0;
   }
		
		
			
	   
	   

   // RB_Transplant()
   void Dictionary::RB_Transplant(Node* u, Node* v){
	if (u->parent == nil) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
	   
   }

   // RB_DeleteFixUp()
   void Dictionary::RB_DeleteFixUp(Node* N){
	   Node * w;
	   while ( N != root && N->color == 0){
		   if (N == N->parent->left){
			   w = N->parent->right;
			   if (w->color == 1){
				   w->color = 0;
				   N->parent->color = 1;
				   LeftRotate(N->parent);
				   w = N->parent->right;
			   }
			   if (w->left->color == 0 && w->right->color == 0) {
				   w->color = 1;
				   N = N->parent;
			   }
			   else {
				   if (w->right->color == 0){
					   w->left->color = 0;
					   w->color = 1;
					   RightRotate(w);
					   w = N->parent->right;
				   }
				w->color = N->parent->color;
				N->parent->color = 0;
				w->right->color = 0;
				LeftRotate(N->parent);
				N = root;
			   }
		   }
			else {
				w = N->parent->left;
			   if (w->color == 1){
				   w->color = 0;
				   N->parent->color = 1;
				   RightRotate(N->parent);
				   w = N->parent->left;
			   }
			   if (w->right->color == 0 && w->left->color == 0) {
				   w->color = 1;
				   N = N->parent;
			   }
			   else {
				   if (w->left->color == 0){
					   w->right->color = 0;
					   w->color = 1;
					   LeftRotate(w);
					   w = N->parent->left;
				   }
				w->color = N->parent->color;
				N->parent->color = 0;
				w->left->color = 0;
				RightRotate(N->parent);
				N = root;
			   }
			}
	   }
		N->color = 0;
			
			   
	   
   }

   // RB_Delete()
   void Dictionary::RB_Delete(Node* N){
	   Node* y = N;
	   Node *x;
	   int ocolor = y->color;
	   if (N->left == nil){
		   x = N->right;
		   RB_Transplant(N,N->right);
	   }
	   else if (N->right == nil){
		   x = N->left;
		   RB_Transplant(N,N->left);
	   }
	   else {
	    y = findMin(N->right);
		ocolor = y->color;
		x = y->right;
		if (y->parent == N){
			x->parent = y;
		}
		else {
			RB_Transplant(y,y->right);
			y->right = N->right;
			y->right->parent = y;
		}
		RB_Transplant(N,y);
		y->left = N->left;
		y->left->parent = y;
		y->color = N->color;
	}
	if (ocolor == 0){
		RB_DeleteFixUp(x);
	}		   
   }

Dictionary::Dictionary() {
	nil = new Node("\000", -1);
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
		if (k < x->key) {
			x = x->left;
		}
		else if (k > x->key) {
			x = x->right;
		}
		else  {
			x->val = v;
			delete z;
			return;
		}
	}
	z->parent = y;
	if (y == nil) {
		this->root = z;
		this->num_pairs++;
		return;
	}
	if (k < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
	//z->left = nil;
	//z->right = nil;
	z->color = 1;
	RB_InsertFixUp(z);
	
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
	RB_Delete(z);
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
		throw std::logic_error("Dictionary: next(): current undefined");
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
		throw std::logic_error("Dictionary: prev(): current undefined");
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