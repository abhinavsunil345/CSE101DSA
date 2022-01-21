/*********************************************************************************
* Abhinav Sunil, aksunil
* 2022 Winter CSE101 PA#2
* List.h
* List ADT Header file
* same as the one in PA1 description
*********************************************************************************/
#ifndef LIST_HINCLUDE
#define LIST_HINCLUDE


#include<stdbool.h>

typedef struct ListObj* List;

// Constructors-Destructors ---------------------------------------------------
List newList(void); // Creates and returns a new empty List.
void freeList(List* pL); // Frees all heap memory associated with *pL, and sets
 // *pL to NULL.
// Access functions -----------------------------------------------------------
int length(List a); // Returns the number of elements in L.
int index(List a); // Returns index of cursor element if defined, -1 otherwise.
int front(List a); // Returns front element of L. Pre: length()>0
int back(List a); // Returns back element of L. Pre: length()>0
int get(List a); // Returns cursor element of L. Pre: length()>0, index()>=0
bool equals(List A, List B); // Returns true iff Lists A and B are in same
 // state, and returns false otherwise.
// Manipulation procedures ----------------------------------------------------
void clear(List a); // Resets L to its original empty state.
void set(List a, int x); // Overwrites the cursor element’s data with x.
 // Pre: length()>0, index()>=0
void moveFront(List a); // If L is non-empty, sets cursor under the front element,
 // otherwise does nothing.
void moveBack(List a); // If L is non-empty, sets cursor under the back element,
 // otherwise does nothing.
void movePrev(List a); // If cursor is defined and not at front, move cursor one
 // step toward the front of L; if cursor is defined and at
 // front, cursor becomes undefined; if cursor is undefined
 // do nothing
void moveNext(List a); // If cursor is defined and not at back, move cursor one
 // step toward the back of L; if cursor is defined and at
 // back, cursor becomes undefined; if cursor is undefined
 // do nothing

void prepend(List a, int x); // Insert new element into L. If L is non-empty,
 // insertion takes place before front element.
void append(List a, int x); // Insert new element into L. If L is non-empty,
 // insertion takes place after back element.
void insertBefore(List a, int x); // Insert new element before cursor.
 // Pre: length()>0, index()>=0
void insertAfter(List a, int x); // Insert new element after cursor.
 // Pre: length()>0, index()>=0
void deleteFront(List a); // Delete the front element. Pre: length()>0
void deleteBack(List a); // Delete the back element. Pre: length()>0
void delete(List a); // Delete cursor element, making cursor undefined.
 // Pre: length()>0, index()>=0
// Other operations -----------------------------------------------------------
void printList(FILE *out, List a);
List copyList(List L);
//void printList(FILE* out, List a); // Prints to the file pointed to by out, a
 // string representation of L consisting
 // of a space separated sequence of integers,
// with front on left.

#endif