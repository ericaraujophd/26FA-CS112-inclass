#ifndef PYLIST_H
#define PYLIST_H

#include <iostream>

using namespace std;

template<typename Item>
class PyList{
    public:
        PyList(); // default constructor
        PyList(const PyList &orig); // copy constructor
        ~PyList(); // destructor
        void append(Item it);
        // getters
        int getSize() const;
        int getCapacity() const;
        Item& getIndex(int ix) const;

        Item& operator[](int ix);

    private:
        Item *myArray;
        int mySize; // how many items I appended to the array
        int myCapacity; // how many items my array holds

};

template<typename Item>
PyList<Item>::PyList() {
    mySize = 0;
    myCapacity = 0;
    myArray = nullptr;
}

// copy constructor
template<typename Item>
PyList<Item>::PyList(const PyList &orig){
    mySize = orig.mySize;
    myCapacity = orig.myCapacity;

    myArray = new Item[myCapacity];
    for(int i=0; i < mySize; i++){
        myArray[i] = orig.myArray[i];
    }
}

// destructor
template<typename Item>
PyList<Item>::~PyList(){
    mySize = 0;
    myCapacity = 0;
    delete [] myArray;
}

// Append
template<typename Item>
void PyList<Item>::append(Item it) {
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
template<typename Item>
int PyList<Item>::getSize() const {
    return mySize;
}

template<typename Item>
int PyList<Item>::getCapacity() const {
    return myCapacity;
}

template<typename Item>
Item& PyList<Item>::getIndex(int ix) const {
    if((ix < 0) || (ix > mySize-1)) throw invalid_argument("No negative indexes, you fool!\n");
    return myArray[ix];
}

template<typename Item>
Item& PyList<Item>::operator[](int ix){
    return getIndex(ix);
}


// template<typename Item>
// ostream & operator<<(ostream &out, PyList<Item> p){
//     for(unsigned i= 0; i < p.getSize(); i++){
//         out << p[i] << " ";
//     }
//     out << endl;
//     return out;
// }







#endif