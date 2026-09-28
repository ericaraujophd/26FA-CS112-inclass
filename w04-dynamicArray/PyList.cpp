#include "PyList.h"

// default constructor
PyList::PyList(){
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

// Append
void PyList::append(Item it){
    if (mySize == 0){
        myArray = new Item[1];
        myCapacity = 1;
        mySize = 1;
        myArray[0] = it;
    }
    // array is not empty!!!!!!
    else{
        myCapacity++;
        mySize++;
        // I've incremented my capacity and size!!!
        Item *tempArray = new Item[myCapacity];

        for(int i=0; i < myCapacity-1; i++){
            tempArray[i] = myArray[i];
        }
        tempArray[myCapacity-1] = it;

        delete []myArray;

        myArray = tempArray;


    }

}

// getters

int PyList::getSize() const{
    return mySize;
}

int PyList::getCapacity() const{
    return myCapacity;
}

Item PyList::getIndex(int ix) const{
    return myArray[ix];
}