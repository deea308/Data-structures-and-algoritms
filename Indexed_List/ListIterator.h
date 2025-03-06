#pragma once
#include "IndexedList.h"

class ListIterator {
private:
    const IndexedList& list;
    int current;

public:
    ListIterator(const IndexedList& list);

    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};
