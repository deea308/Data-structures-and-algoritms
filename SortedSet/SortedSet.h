#pragma once
#include<cmath>
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
    TElem* elements;
    int* next;
    int (*h)(TElem, int){}; // Funcția de hash

    static int hashFunction(TElem elem, int size) {
        return abs(elem % size);
    }

public:
    // Constructor
    SortedSet(Relation r);

    // Destructor
    ~SortedSet();

    // Adaugă un element în set
    bool add(TComp e);

    // Elimină un element din set
    bool remove(TComp e);

    // Verifică dacă un element este în set
    bool search(TElem elem) const;

    // Returnează numărul de elemente din set
    int size() const;

    // Verifică dacă setul este gol
    bool isEmpty() const;

    // Returnează un iterator pentru set
    SortedSetIterator iterator() const;

    // Sortează elementele setului
    //void sort();
};
