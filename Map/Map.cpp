#include "Map.h"
#include "MapIterator.h"

Map::Map() {
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)
	//TODO - Implementation
    ///Initial capacity
    this->cp = 1;

    ///We allocate memory space for the array of pairs
    e = new TElem[cp];

    ///We initialize the number of elements
    this->n = 0;

}

Map::~Map() {
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)
	//TODO - Implementation
    ///We deallocate the memory space for the array of pairs
    delete[] e;
}

///Added by me
void Map::resize() {
    //BC: Theta(n)  WC: Theta(n)
    //Overall complexity: O(n)

    ///We allocate memory space for the new array of pairs and copy the elements from the old array
    TElem *eNou = new std::pair<int, int>[2*cp];
    for (int i=0; i<n; i++)
        eNou[i] = e[i];
    ///We update the capacity
    cp = 2 * cp;
    ///We deallocate the memory space for the old array of pairs
    delete[] e;
    ///We update the array
    e = eNou;
}

TValue Map::add(TKey c, TValue v){
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation
    ///We search for the key in the array of pairs
    for (int i = 0; i < n; i++) {
        if (this->e[i].first == c) {
            ///If the key is found, we update the value and return the old value
            TValue oldVal = this->e[i].second;
            this->e[i].second = v;
            return oldVal;
        }
    }
    ///If the key is not found, we add the pair to the array of pairs
    if (n == cp)
        resize();
    ///We increment the number of elements
    this->e[n++] = std::make_pair(c, v);
    return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation
    ///We search for the key in the array of pairs
    for(int i=0; i<n; i++){
        if(this->e[i].first == c)
            return this->e[i].second;
    }
    return NULL_TVALUE;
}

TValue Map::remove(TKey c){
    //BC: Theta(1)  WC: Theta(n)
    //Overall complexity: O(n)

	//TODO - Implementation

    TValue removedValue;
    bool found = false;
    int i = 0;

    ///We search for the key in the array of pairs
    while(i<this->n && !found){
        if (this->e[i].first == c){
            found = true;
            ///If the key is found, we remove the pair from the array of pairs
            removedValue = this->e[i].second;
            for (int j=i; j<n-1; j++)
                this->e[j] = this->e[j+1];
            this->n--;
        }
        else{
            ///If the key is not found, we increment the index
            i++;
        }
    }
    if(found)
        return removedValue;
    return NULL_TVALUE;
}


int Map::size() const {
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)

	//TODO - Implementation
    ///Retrieves the length/size
    return this->n;
}

bool Map::isEmpty() const{
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)

	//TODO - Implementation
    ///Checks if the map is empty
    return (n==0);
}

MapIterator Map::iterator() const {
    //BC: Theta(1)  WC: Theta(1)
    //Overall complexity: O(1)

    ///Returns an iterator for the map
	return MapIterator(*this);
}
