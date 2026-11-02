#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class Item>
class Stack{
    public:
        Stack();
        ~Stack();

        Item pop();
        void push(Item it);
        Item peekTop() const;

        // getters
        bool isEmpty() const;
        unsigned getSize() const;

    private:
        List<Item> *l;
};


// default constructor
template <class Item>
Stack<Item>::Stack(){
    l = new List<Item>;
}

template <class Item>
Stack<Item>::~Stack(){
    delete l;
}

// pop
template <class Item>
Item Stack<Item>::pop(){
    return l->removeFirst();
}

// push
template <class Item>
void Stack<Item>::push(Item it){
    l->prepend(it);
}

// isEmpty
template <class Item>
bool Stack<Item>::isEmpty() const{
    return (l->getSize() == 0);
}

// getSize
template <class Item>
unsigned Stack<Item>::getSize() const{
    return l->getSize();
}

// peekTop
template <class Item>
Item Stack<Item>::peekTop() const{
    return l->getFirst();
}




#endif