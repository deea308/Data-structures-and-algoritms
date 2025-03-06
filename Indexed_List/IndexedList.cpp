#include "IndexedList.h"
#include "ListIterator.h"
#include <exception>

IndexedList::IndexedList() {
    //the list is empty
    first = -1;
    //we initialize the list of free space
    for (int i = 0; i < cp - 1; i++) {
        nextLink[i] = i + 1;
    }
    nextLink[cp - 1] = -1;
    //we set the first empty position
    firstEmpty = 0;
}
//Theta(cp)

int IndexedList::allocate() {
    //we delete the first empty slot from the list of empty slots
    int i = firstEmpty;
    firstEmpty = nextLink[firstEmpty];
    return i;
}
//Theta(1)

void IndexedList::deallocate(int index) {
    //we add the slot at index i at the beginning of the list of empty spaces
    nextLink[index] = firstEmpty;
    firstEmpty = index;
}
//Theta(1)

int IndexedList::createNode(TElem e) {
    int i = allocate();
    if (i != -1) {
        this->e[i] = e;
        nextLink[i] = -1;
    }
    return i;
}
//Theta(1)

int IndexedList::size() const //This function returns the number of elements currently stored in the indexed list.
{
    int n = 0;
    int current = this->first;
    while (current != -1) {
        n++;
        current = this->nextLink[current];
    }
    return n;
}
//BC=theta(1)-when the list is empty
//WC-O(N) - when the function iterates through the entire list to count the number of elements.
//overall- O(n)

bool IndexedList::isEmpty() const {
    return (first == -1);
}
//Theta(1)

TElem IndexedList::getElement(int pos) const
{
    // Check if the given position is within the valid range of the list
    if (pos < 0 || pos >= size())
        throw std::exception();

    int current = first;
    for (int i = 0; i < pos; i++)
        current = nextLink[current];

    return e[current];
}
//BC=theta(1)-when the element to retrieve is the first element of the list
//WC-O(N) - when the element to retrieve is at the end of the list or requires iterating through the entire list to find the position
//overall- O(n)

TElem IndexedList::setElement(int pos, TElem e)
{
    // Check if the given position is within the valid range of the list
    if (pos < 0 || pos >= size())
        throw std::exception();

    int current = first;
    for (int i = 0; i < pos; i++)
        current = nextLink[current];
    // Store the old element
    TElem oldElem = this->e[current];
    // Set the new element
    this->e[current] = e;
    return oldElem;// Return the old element
}
//BC=theta(1)-when the element to be updated is the first element of the list.
//WC-O(N) - when the element to be updated is at the end of the list or requires iterating through the entire list to find the position
//overall- O(n)

void IndexedList::addToEnd(TElem e)
{
    //This function adds the specified element e at the end of the indexed list.
    int newNode = createNode(e);
    if (first == -1)
        first = newNode;
    else {
        int current = first;
        while (nextLink[current] != -1)
            current = nextLink[current];
        // Update the last node's link to point to the new node
        nextLink[current] = newNode;
    }
}
//BC-theta(1) -the best-case scenario occurs when the list is empty.
//WC-O(N) -when the element is added at the end of the list, and it requires traversing through the entire list to find the end
//overall- O(n)

void IndexedList::addToPosition(int pos, TElem e)
{
    //This function adds the specified element e at the given position pos in the indexed list.
    if (pos < 0 || pos > size())
        throw std::exception();

    if (pos == 0) //if pos is the first one we add first
    {
        int newNode = createNode(e);// Create a new node for the element
        nextLink[newNode] = first;// Update the links to include the new node
        first = newNode;// Update the first index
    }
    else {
        int current = first;
        for (int i = 1; i < pos; i++)
            current = nextLink[current];// Traverse the list to find the position 'pos'
        int newNode = createNode(e);
        nextLink[newNode] = nextLink[current];// Update the links to include the new node at the correct position
        nextLink[current] = newNode;
    }
}
//BC-theta(1) -when the element is added at the beginning of the list
//WC-O(N) -when the element is added at the end of the list, or it requires iterating through the entire list to find the position.
//overall- O(n)

TElem IndexedList::remove(int pos)
{
    //This function removes the element at the specified position pos from the indexed list and returns the removed element.
    if (pos < 0 || pos >= size())
        throw std::exception();

    int removedElement;
    if (pos == 0) //we move every elem if the pos is the first one
    {
        removedElement = e[first];
        int temp = first;
        first = nextLink[first];
        deallocate(temp);
    }
    else //we still search for the element
    {
        int current = first;
        int prev = -1;
        for (int i = 0; i < pos; i++) {
            prev = current;
            current = nextLink[current];//keep the current link
        }
        removedElement = e[current];
        nextLink[prev] = nextLink[current];
        deallocate(current);
    }
    return removedElement;
}
//BC-theta(1) -the best-case scenario occurs when the removal happens at the beginning of the list
//WC-O(N) -the removal happens at the end of the list, or it requires iterating through the entire list to find the position.
//overall- O(n)

int IndexedList::search(TElem e) const {
    int current = first;
    int pos = 0;
    while (current != -1 && this->e[current] != e) //verifies not to be at final and e is current
    {
        current = nextLink[current];
        pos++;
    }
    if (current == -1)
        return -1;
    else
        return pos;
}
//BC-theta(1) - e is found at the beginning of the list or when the list is empty.
//WC-O(N) -e is not in the list or when it's at the end of the list.
//overall- O(n)

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}
//Theta(1)

IndexedList::~IndexedList() {

}
//Theta(1)