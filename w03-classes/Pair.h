#ifndef PAIR_H
#define PAIR_H

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
        int getFirst();
        int getSecond();
        // setters -> 
        // methods to modify my private attributes first and second
        void setFirst(int f);
        void setSecond(int s);
    private:
        int first;
        int second;
};

#endif