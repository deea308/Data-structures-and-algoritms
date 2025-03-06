#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <stdexcept>
using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	this->currentNode=m.head;
}

void SMIterator::first(){
	this->currentNode=this->map.head;
}

void SMIterator::next(){
    if (this->currentNode != nullptr) {
            this->currentNode = this->currentNode->next;
    }else
        throw out_of_range("Iterator is not valid");
}

bool SMIterator::valid() const{
	if(this->currentNode== nullptr)
	    return false;
    else return true;
}

TElem SMIterator::getCurrent() const{
    if (this->currentNode == nullptr)
        throw out_of_range("Iterator is not valid");
    return this->currentNode->e;
}


