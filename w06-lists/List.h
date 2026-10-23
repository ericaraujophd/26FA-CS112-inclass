#ifndef LIST_H
#define LIST_H


typedef int Item;

class List{
    public:
        List(); // default constructor
        List(const List &orig); // copy constructor
        ~List(); // destructor
        List& operator=(const List &rhs); // assignment
        List& operator==(const List &rhs); // assignment

        // getters
        unsigned getSize() const;
        bool isEmpty() const;
        Item getFirst() const;
        Item getLast() const;
        Item& getIndex(unsigned ix) const;

        Item& operator[](unsigned ix);

        // adding and removing items
        void append(Item it); // add to the end
        void prepend(Item it); // add to the beginning
        Item removeFirst(); // remove from the beginning and return it
        Item remove(int idx);
        Item removeLast();

    private:
        class Node {
            public:
            Node(Item it, Node *next); // explicit-value constructor
            ~Node();
            Item myItem; // the value stored in this node
            Node *myNext; // the node after this one (nullptr if last)
        };

        Node *myFirst; // first node in the list
        Node *myLast; // last node in the list
        unsigned mySize; // how many nodes are in the list

};

#endif
