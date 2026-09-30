#include "PyList.h"

// default constructor
PyList::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

// Append
void PyList::append(Item it) {
    if (mySize == myCapacity) {
        // adjusting the new lenght of the array using myCapacity
        myCapacity = (myCapacity == 0) ? 1 : myCapacity * 2;
        // does exactly what is below:
        // if(myCapacity == 0){
        //     myCapacity = 1;
        // }
        // else {
        //     myCapacity *= 2;
        // }

        Item* bigger = new Item[myCapacity];

        for (int i = 0; i < mySize; i++) {
            bigger[i] = myArray[i];
        }
        delete [] myArray;
        myArray = bigger;
    }
    myArray[mySize] = it;
    mySize++;

}

// getters

int PyList::getSize() const {
    return mySize;
}

int PyList::getCapacity() const {
    return myCapacity;
}

Item PyList::getIndex(int ix) const {
    return myArray[ix];
}