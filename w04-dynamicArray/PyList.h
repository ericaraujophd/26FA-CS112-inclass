#ifndef PYLIST_H
#define PYLIST_H


typedef int Item;

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
















#endif