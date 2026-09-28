#ifndef PYLIST_H
#define PYLIST_H


typedef int Item;

class PyList{
    public:
        PyList();
        void append(Item it);
        // getters
        int getSize() const;
        int getCapacity() const;
        Item getIndex(int ix) const;

    private:
        Item *myArray;
        int mySize; // how many items I appended to the array
        int myCapacity; // how many items my array holds

};
















#endif