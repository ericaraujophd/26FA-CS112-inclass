#include "PyList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// default constructor
PyList::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

// copy constructor
PyList::PyList(const PyList &orig){
    mySize = orig.mySize;
    myCapacity = orig.myCapacity;

    myArray = new Item[myCapacity];
    for(int i=0; i < mySize; i++){
        myArray[i] = orig.myArray[i];
    }
}

// destructor
PyList::~PyList(){
    mySize = 0;
    myCapacity = 0;
    delete [] myArray;
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

Item& PyList::getIndex(int ix) const {
    if((ix < 0) || (ix > mySize-1)) throw invalid_argument("No negative indexes, you fool!\n");
    return myArray[ix];
}

Item& PyList::operator[](int ix){
    return getIndex(ix);
}