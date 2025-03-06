#include <algorithm>
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) : capacity(100000),numElements(0), relation(r) {
    //firstEmpty=-1;
    elements=new TElem [capacity];
    next= new int[capacity];
    for(int i =0;i<capacity; i++){
        next[i]=-1;
        elements[i]= NULL_TELEM;
    }
}
//Theta(capacity)

SortedSet::~SortedSet() {
    delete[] elements;
    delete[] next;
}
//Theta(1)

bool SortedSet::add(TComp elem) {
    int index = hashFunction(elem, capacity);

    // Check if the element is already present
    if (search(elem)) {
        return false;
    }

    // If the current position is empty, place the element there
    if (elements[index] == NULL_TELEM) {
        elements[index] = elem;
        numElements++;
        return true;
    }


    int current = index;
    while (next[current] != -1) {
        current = next[current];
    }

    // Find the next available slot
    int firstEmpty = -1;
    for (int i = 0; i < capacity; ++i) {
        if (elements[i] == NULL_TELEM) {
            firstEmpty = i;
            break;
        }
    }

    if (firstEmpty == -1) {
        return false; // No empty slot found
    }

    elements[firstEmpty] = elem;
    next[current] = firstEmpty;
    numElements++;
    return true;
}
//WC: Theta(n)
//AC: Theta(1)- under SUH assumptions


bool SortedSet::remove(TComp elem) {
    int index = hashFunction(elem, capacity);
    int previous = -1;
    int firstEmpty = -1;

    if (elements[index] == NULL_TELEM) {
        return false;
    }

    while (index != -1 && elements[index] != elem) {
        previous = index;
        index = next[index];
    }

    if (index == -1) {
        return false;
    }

    bool done = false;

    do {
        int p = next[index];
        int pp = index;
        while (p != -1 && hashFunction(elements[p], capacity) != index) {
            pp = p;
            p = next[p];
        }

        if (p == -1) {
            done = true;
        } else {
            elements[index] = elements[p];
            index = p;
            previous = pp;
        }
    } while (!done);

    if (previous == -1) {
        int x = 0;
        while (x < capacity && previous != -1) {
            if (next[x] == index)
                previous = x;
            else
                x++;
           }
    }

    if (previous != -1) {
        next[previous] = next[index];
    }

    elements[index] = NULL_TELEM;
    next[index] = -1;

    if (index < firstEmpty) {
        firstEmpty = index;
    }

    numElements--;
    return true;
}
//BC:Theta(1)
//WC:O(n)
//AC:O(n)


bool SortedSet::search(TElem elem) const {
    // Search for an element in the set
    int index = hashFunction(elem,capacity); // Index of the element in the hash table

    while(index!=-1 && elements[index]!=elem){
        index=next[index];
    }

    if(index==-1){
        return false;
    }else{
        return true;
    }
}
//BC: Theta(1)
//WC:Theta(n)
//AC:Theta(1)-under SUH assumption

int SortedSet::size() const {
    return numElements;
}
//Theta(1)

bool SortedSet::isEmpty() const {
    return numElements == 0;
}
//Theta(1)

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}
//Theta(1)

