#pragma once
#include<vector>
#include "SortedSet.h"

class SortedSetIterator
{
    friend class SortedSet;
protected:
    const SortedSet& set;
    int current;
    std::vector<TElem> elements;
    SortedSetIterator(const SortedSet& s);
    static void bubbleSort(std::vector<TElem> &arr, Relation relation);
public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
};
