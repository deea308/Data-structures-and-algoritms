#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
protected:
	const SortedSet& multime;
    int currentIndex;
    std::vector<TElem> elements;
	SortedSetIterator(const SortedSet& m);

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;

    //void bubbleSort(std::vector<TElem> &arr, Relation relation);
    void bubbleSort(std::vector<TElem> &arr, Relation relation);
};

