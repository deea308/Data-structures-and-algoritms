#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>
using namespace std;
ListIterator::ListIterator(const IndexedList& list) : list(list) {
    this->current = this->list.first;
}
//Theta(1)
void ListIterator::first() {
    this->current = this->list.first;
}
//Theta(1)
void ListIterator::next() {
    if (!valid())
        throw exception();
    this->current = this->list.nextLink[this->current];
}
//Theta(1)
bool ListIterator::valid() const {
    return current != -1;
}
//Theta(1)
TElem ListIterator::getCurrent() const {
    if (!valid())
        throw exception();
    return this->list.e[this->current];
}
//Theta(1)