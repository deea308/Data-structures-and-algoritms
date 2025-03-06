#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;


SortedMap::SortedMap(Relation r) {
    this->head= nullptr;
    this->tail= nullptr;
    this->r=r;
    this->mapSize=0;
}//Theta(1)

TValue SortedMap::add(TKey k, TValue v) {
    TElem e = TElem(k, v);
    Node* newNod = new Node(e, nullptr, nullptr); // New node without links

    // If map is empty, add as the first element
    if (this->head == nullptr) {
        this->head = this->tail = newNod;
        this->mapSize++;
        return NULL_TVALUE; // No replacement since it's a new entry
    }

    // Check if the key already exists in the map
    Node* currentNode = this->head;
    while (currentNode != nullptr && r(currentNode->e.first, k)) {
        if (currentNode->e.first == k) {
            TValue oldValue = currentNode->e.second;
            currentNode->e.second = v; // Update the value
            delete newNod; // Key already exists, delete the new node
            return oldValue; // Return the old value
        }
        currentNode = currentNode->next;
    }

    // Key does not exist, add the new pair
    if (currentNode == nullptr) {
        newNod->prev = this->tail;
        this->tail->next = newNod;
        this->tail = newNod;
    } else if (currentNode == this->head) { // Insert at the beginning
        newNod->next = this->head;
        this->head->prev = newNod;
        this->head = newNod;
    } else { // Insert in the middle
        newNod->prev = currentNode->prev;
        newNod->next = currentNode;
        currentNode->prev->next = newNod;
        currentNode->prev = newNod;
    }

    this->mapSize++;
    return NULL_TVALUE; // No replacement since it's a new entry
}

//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
TValue SortedMap::search(TKey k) const {
    Node *currentNode = this->head;
    while (currentNode != nullptr && this->r(currentNode->e.first, k)) {
        if (currentNode->e.first == k) {
            return currentNode->e.second; // Return the associated value
        }
        currentNode = currentNode->next;
    }
    return NULL_TVALUE; // Key not found, return NULL_TVALUE
}

TValue SortedMap::remove(TKey k) {
    Node* currentNode = this->head;
    while (currentNode != nullptr && this->r(currentNode->e.first, k)) {
        if (currentNode->e.first == k) {
            // Key found, save the associated value before removal
            TValue valueToRemove = currentNode->e.second;

            // Adjust the pointers to remove the node from the list
            if (currentNode == this->head) {
                this->head = currentNode->next;
                if (this->head != nullptr)
                    this->head->prev = nullptr;
            } else if (currentNode == this->tail) {
                this->tail = currentNode->prev;
                if (this->tail != nullptr)
                    this->tail->next = nullptr;
            } else {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
            }

            // Delete the node
            delete currentNode;

            // Return the value associated with the removed key
            return valueToRemove;
        }
        currentNode = currentNode->next;
    }
    // Key not found, return NULL_TVALUE
    return NULL_TVALUE;
}



int SortedMap::size() const {
    int count=0;
    Node* currentNode=this->head;
    while (currentNode != nullptr)
    {
        count++;
        currentNode= currentNode->next;
    }
    return count;
}

bool SortedMap::isEmpty() const {
    return this->head == nullptr;
}

SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

SortedMap::~SortedMap() {
    Node* currentNode=this->head;
    while(currentNode!=nullptr)
    {
        Node* next = currentNode -> next;
        delete currentNode;
        currentNode= next;
    }
    this->head=this->tail= nullptr;
}
