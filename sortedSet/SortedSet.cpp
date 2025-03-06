#include <algorithm>
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) : capacity(101), numElements(0), relation(r), elements(new TElem[capacity]),
                                   next(new int[capacity]), firstEmpty(0), h(nullptr) {}

bool SortedSet::add(TComp elem) {
    if (search(elem))
    return false; // Element already exists

    int index = hashFunction(elem, capacity);

    if (elements[index] == NULL_TELEM) {
        elements[index] = elem;
        next[index] = -1; // Mark the end of the chain
    } else {
        int current = index;
        while (next[current] != -1) {
            current = next[current];
        }
        int newIndex = firstEmpty;
        firstEmpty = next[firstEmpty]; // Update firstEmpty
        elements[newIndex] = elem;
        next[newIndex] = -1;
        next[current] = newIndex; // Link to the new element
    }

    numElements++;
    return true;
}

bool SortedSet::remove(TComp elem) {
    int index = hashFunction(elem, capacity);
    int prev = -1;

    // Search for the element in the chain
    while (index != -1 && elements[index] != elem) {
        prev = index;
        index = next[index];
    }

    // If the element is found
    if (index != -1) {
        // If the element is the first in the chain
        if (prev == -1) {
            elements[index] = NULL_TELEM;
            next[index] = firstEmpty;
            firstEmpty = index;
        } else {
            next[prev] = next[index];
            elements[index] = NULL_TELEM;
            next[index] = firstEmpty;
            firstEmpty = index;
        }
        numElements--;
        return true;
    }

    return false; // Element not found
}


bool SortedSet::search(TComp elem) const {
    int index = hashFunction(elem, capacity);

    // Search for the element in the chain
    while (index != -1) {
        if (elements[index] == elem) {
            return true; // Element found
        }
        index = next[index];
    }

    return false; // Element not found
}


int SortedSet::size() const {
    return numElements;
}



bool SortedSet::isEmpty() const {
    return numElements == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {

}

void SortedSetIterator::bubbleSort(std::vector<TElem> &arr, Relation relation) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!relation(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

}

