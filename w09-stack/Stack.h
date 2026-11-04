#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class Item>
class Stack{
    public:
        Stack();
        ~Stack();

        // Stack(const Stack &orig);

        Item pop();
        void push(Item it);
        Item peekTop() const;

        // getters
        bool isEmpty() const;
        unsigned getSize() const;

    private:
        List<Item> myList;
};


// default constructor
template <class Item>
Stack<Item>::Stack(){
}

template <class Item>
Stack<Item>::~Stack(){
}

// template <class Item>
// Stack<Item>::Stack(const Stack<Item> &orig){

// }

// pop
template <class Item>
Item Stack<Item>::pop(){
    return myList.removeFirst();
}

// push
template <class Item>
void Stack<Item>::push(Item it){
    myList.prepend(it);
}

// isEmpty
template <class Item>
bool Stack<Item>::isEmpty() const{
    return (myList.getSize() == 0);
}

// getSize
template <class Item>
unsigned Stack<Item>::getSize() const{
    return myList.getSize();
}

// peekTop
template <class Item>
Item Stack<Item>::peekTop() const{
    return myList.getFirst();
}


#endif