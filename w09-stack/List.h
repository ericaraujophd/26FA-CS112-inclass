#ifndef LIST_H
#define LIST_H

#include <stdexcept>

// List is a class template: Item is whatever type the user picks,
// e.g. List<int>, List<double>, List<std::string>.
// Because it is a template, all the method definitions live in this header
// (the compiler needs to see them to build List<int>, List<string>, ...).

template <class Item>
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

// Every definition below starts with template <class Item>
// and uses List<Item>:: instead of List::

// Node constructor
template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
    myItem = it;
    myNext = next;
}

template <class Item>
List<Item>::Node::~Node() {
    // cout << "My Node is dying. So sad! " << myItem << endl;
    delete myNext;
}

// default constructor
template <class Item>
List<Item>::List() {
    myFirst = myLast = nullptr;
    mySize = 0;
}

// copy constructor
template <class Item>
List<Item>::List(const List& orig) {
    // start empty, so append() sees a valid (empty) list
    myFirst = myLast = nullptr;
    mySize = 0;
    for (Node* ptr = orig.myFirst; ptr != nullptr; ptr = ptr->myNext) {
        this->append(ptr->myItem);  // append() updates mySize
    }
}

// destructor
template <class Item>
List<Item>::~List() {
    delete myFirst;
}

// assignment
template <class Item>
List<Item>& List<Item>::operator=(const List& rhs) {
    if (this != &rhs) {  // self-assignment would delete our own nodes
        // throw away our old nodes
        delete myFirst;
        myFirst = myLast = nullptr;
        mySize = 0;
        // copy rhs's items
        for (Node* ptr = rhs.myFirst; ptr != nullptr; ptr = ptr->myNext) {
            this->append(ptr->myItem);
        }
    }
    return *this;  // allows chaining: a = b = c
}

// getters

template <class Item>
unsigned List<Item>::getSize() const {
    return mySize;
}

template <class Item>
bool List<Item>::isEmpty() const {
    return (mySize == 0);
}

template <class Item>
Item List<Item>::getFirst() const {
    if (mySize == 0) {
        throw std::underflow_error("List is empty!");
    }
    return myFirst->myItem;
}

template <class Item>
Item List<Item>::getLast() const {
    if (mySize == 0) {
        throw std::underflow_error("List is empty!");
    }
    return myLast->myItem;
}

template <class Item>
Item& List<Item>::getIndex(unsigned ix) const {
    if (mySize == 0) {
        throw std::invalid_argument("List is empty, nothing to index into\n");
    }
    if(ix > mySize-1){
        throw std::out_of_range("You are going out of limits!\n");
    }
    Node* tmp = myFirst;
    for (unsigned i = 0; i < ix; i++) {
        tmp = tmp->myNext;
    }
    return tmp->myItem;
}

template <class Item>
Item& List<Item>::operator[](unsigned ix) {
    return getIndex(ix);
}

// adding and removing items

template <class Item>
void List<Item>::append(Item it) {
    Node* newNode = new Node(it, nullptr);
    if (mySize == 0) {
        myFirst = newNode;
    } else {
        myLast->myNext = newNode;  // making last Node points to the new one
    }
    myLast = newNode;  // fixing myLast
    mySize++;
}

template <class Item>
void List<Item>::prepend(Item it) {
    Node* newNode = new Node(it, myFirst);
    myFirst = newNode;

    if (mySize == 0) {
        myLast = newNode;
    }
    mySize++;
}

template <class Item>
Item List<Item>::removeFirst() {
    if (mySize == 0) throw std::underflow_error("List is empty you fool!\n");
    Node* tmp = myFirst;
    myFirst = myFirst->myNext;
    tmp->myNext = nullptr;
    Item it = tmp->myItem;
    delete tmp;
    mySize--;
    return it;
}

template <class Item>
Item List<Item>::removeLast() {
    if (mySize == 0) throw std::underflow_error("List is empty you fool!\n");
    Item it = myLast->myItem;

    // only one node: there is no penultimate node, the list becomes empty
    if (mySize == 1) {
        delete myFirst;
        myFirst = myLast = nullptr;
        mySize = 0;
        return it;
    }

    // find the penultimate node
    Node* tmp;
    for (tmp = myFirst; tmp->myNext != myLast; tmp = tmp->myNext);

    // by the end of this for, tmp is going to be pointing to the penultimate
    // node
    delete myLast;
    myLast = tmp;
    myLast->myNext = nullptr;
    mySize--;
    return it;
}

#endif
