#include "SortedSetIterator.h"


SortedSetIterator::SortedSetIterator(const SortedSet& s) : set(s), current(0) {
    for (int i = 0; i < set.capacity; ++i) {
        if (set.elements[i] != NULL_TELEM) {
            elements.push_back(set.elements[i]);
        }
    }
    bubbleSort(elements, set.relation);
}

void SortedSetIterator::first() {
    current = 0;
}
//Theta(1)

void SortedSetIterator::next() {
    if (!valid())
        throw std::exception();

    current++;
}
//Theta(1)

TElem SortedSetIterator::getCurrent() const {
    if (!valid())
        throw std::exception();

    return elements[current];
}
//Theta(1)

bool SortedSetIterator::valid() const {
    return current < elements.size();
}
//Theta(1)

void SortedSetIterator::bubbleSort(std::vector<TElem>& arr, Relation relation) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!relation(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
//Theta(n)
