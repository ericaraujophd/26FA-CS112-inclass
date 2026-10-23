#include "List.h"

#include <iostream>
#include <stdexcept>

using namespace std;

// Every method below is a stub that throws until we implement it in class.
// The project compiles from the start, and each test passes as we fill it in.

// Node constructor
List::Node::Node(Item it, Node* next) {
    myItem = it;
    myNext = next;
}

List::Node::~Node() {
    // cout << "My Node is dying. So sad! " << myItem << endl;
    delete myNext;
}

// default constructor
List::List() {
    myFirst = myLast = nullptr;
    mySize = 0;
}

// copy constructor
List::List(const List& orig) {
    if (orig.isEmpty()) {
        myFirst = myLast = nullptr;
        mySize = 0;
    } else {
        for (Node* ptr = orig.myFirst; ptr != nullptr; ptr = ptr->myNext) {
            this->append(ptr->myItem);
        }
        mySize = orig.getSize();
    }
}

// destructor
List::~List() {
    delete myFirst;
}

// assignment
List& List::operator=(const List& rhs) {
    // TODO
    throw logic_error("operator= not implemented yet");
}

// getters

unsigned List::getSize() const {
    return mySize;
}

bool List::isEmpty() const {
    return (mySize == 0);
}

Item List::getFirst() const {
    if (mySize == 0) {
        throw underflow_error("List is empty!");
    }
    return myFirst->myItem;
}

Item List::getLast() const {
    if (mySize == 0) {
        throw underflow_error("List is empty!");
    }
    return myLast->myItem;
}

Item& List::getIndex(unsigned ix) const {
    if (mySize == 0) {
        throw invalid_argument("List is empty, nothing to index into\n");
    }
    if(ix < 0 || ix > mySize-1){
        throw out_of_range("You are going out of limits!\n");
    }
    Node* tmp = myFirst;
    for (int i = 0; i < ix; i++) {
        tmp = tmp->myNext;
    }
    return tmp->myItem;
}

Item& List::operator[](unsigned ix) {
    return getIndex(ix);
}

// adding and removing items

void List::append(Item it) {
    Node* newNode = new Node(it, nullptr);
    if (mySize == 0) {
        myFirst = newNode;
    } else {
        myLast->myNext = newNode;  // making last Node points to the new one
    }
    myLast = newNode;  // fixing myLast
    mySize++;
}

void List::prepend(Item it) {
    Node* newNode = new Node(it, myFirst);
    myFirst = newNode;

    if (mySize == 0) {
        myLast = newNode;
    }
    mySize++;
}

Item List::removeFirst() {
    if (mySize == 0) throw underflow_error("List is empty you fool!\n");
    Node* tmp = myFirst;
    myFirst = myFirst->myNext;
    tmp->myNext = nullptr;
    Item it = tmp->myItem;
    delete tmp;
    mySize--;
    return it;
}

Item List::removeLast() {
    // find the penultimate node
    Node* tmp;
    for (tmp = myFirst; tmp->myNext->myNext == nullptr; tmp = tmp->myNext);

    // by the end of this for, tmp is going to be pointing to the penultimate
    // node
    delete myLast;
    myLast = tmp;
    myLast->myNext = nullptr;
    mySize--;
}