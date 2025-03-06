#pragma once
#include <vector>
#include <iostream> // For debugging purposes
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;


class SortedSet {
	friend class SortedSetIterator;
protected:
    int capacity;
    int numElements;
    Relation relation;
    TElem * elements;
    int* next;
    int firstEmpty;
    int (*h)(TElem , int);

    int hashFunction(TElem elem, int size) const {
        return elem % size;
    }
    //void bubbleSort(std::vector<TElem>& arr, Relation relation);
public:
	//constructor
	SortedSet(Relation r);

    // Sorts the elements of the sorted set
    void sort();

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TElem elem) const;


	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	// destructor
	~SortedSet();


};
