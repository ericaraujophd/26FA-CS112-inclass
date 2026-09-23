#ifndef PAIR_H
#define PAIR_H

#include<iostream>
using namespace std;
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
        Pair(int f, int s);
        // getters ->
        // methods to read my private attributes first and second
        // Pair p3(5,6);
        // int x = p3.getFirst();
        // cout << p3.getFirst() << endl;
        int getFirst() const;
        int getSecond() const;
        void add(Pair &p2);

        // setters -> 
        // methods to modify my private attributes first and second
        void setFirst(int f);
        void setSecond(int s);

        // overload the operator =
        const Pair& operator=(Pair &p, Pair &q);
    private:
        int first;
        int second;
};

// important! it is outside of the class!
ostream& operator<<(ostream &out, const Pair &p);

#endif