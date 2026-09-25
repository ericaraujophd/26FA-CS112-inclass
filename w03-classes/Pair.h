#ifndef PAIR_H
#define PAIR_H

#include<iostream>
using namespace std;

typedef int Item;

// Class Pair
class Pair{
    public:
        // constructor
        // default constructor
        // Pair p;
        Pair();
        // explicit-value constructor
        // Pair p(1,3);
        // Pair p2(1); // no such a constructor created. ERROR.
        Pair(Item f, Item s);
        // getters ->
        // methods to read my private attributes first and second
        // Pair p3(5,6);
        // int x = p3.getFirst();
        // cout << p3.getFirst() << endl;
        Item getFirst() const;
        Item getSecond() const;
        void add(Pair &p2);

        // setters -> 
        // methods to modify my private attributes first and second
        void setFirst(Item f);
        void setSecond(Item s);

        // overload the operator =
        Pair& operator=(const Pair &p);
    private:
        Item first;
        Item second;
};

// important! it is outside of the class!
ostream& operator<<(ostream &out, const Pair &p);

#endif