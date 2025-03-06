#include "SortedSetIterator.h"

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m) {
    currentIndex = 0;
    auto setIterator = m.iterator(); // Get the iterator from the SortedSet
    while (setIterator.valid()) {
        elements.push_back(setIterator.getCurrent()); // Add elements to the vector
        setIterator.next();
    }
    bubbleSort(elements, m.relation); // Sort the elements
}

void SortedSetIterator::first() {
    currentIndex = 0;

}

void SortedSetIterator::next() {
    currentIndex++;
}

TElem SortedSetIterator::getCurrent() {
    if (!valid()) // If the iterator is not valid, throw exception or return some default value
        throw std::exception();

    return elements[currentIndex];
}

bool SortedSetIterator::valid() const {
    return currentIndex >=0 && currentIndex< elements.size();
}


