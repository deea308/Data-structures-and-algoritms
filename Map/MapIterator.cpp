#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation
    ///We initialize the current element with the first element of the array of pairs
    this->currentE=0;
    ///We search for the first element of the array of pairs that is not NULL_TVALUE
    while (this->currentE < this->map.n && this->map.e[this->currentE].second == NULL_TVALUE)
        this->currentE++;
    this->firstE = this->currentE;
}


void MapIterator::first() {
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation
    ///We initialize the current element with the first element of the array of pairs
    this->currentE = 0;
    ///We search for the first element of the array of pairs that is not NULL_TVALUE
    while (this->currentE < this->map.n && this->map.e[this->currentE].second == NULL_TVALUE)
        this->currentE++;
    this->firstE = this->currentE;
}


void MapIterator::next() {
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation
    if(!valid()){
        throw exception();
    }
    else{
        ///We increment the current element while it is valid
        this->currentE++;
        while (this->currentE < this->map.n && this->map.e[this->currentE].second == NULL_TVALUE)
            this->currentE++;
    }
}


TElem MapIterator::getCurrent(){
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)

	//TODO - Implementation
    ///We return the current element if it is valid
	if(this->currentE >= this->map.n){
        throw exception();
    }
    else{
        return this->map.e[this->currentE];
    }
}


bool MapIterator::valid() const {
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)

	//TODO - Implementation
    ///We check if the current element is valid i.e. if it is smaller than the number of elements in the array of pairs
    return (this->currentE < this->map.n);
}



