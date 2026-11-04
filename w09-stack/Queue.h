#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class Item>
class Queue {
public:
    Queue();
    ~Queue();

    // queue
    void add(Item it);
    // dequeue
    Item remove();

    // getters
    unsigned getSize() const;
    Item peekFront() const;
    Item peekBack() const;
    bool isEmpty() const;

private:
    List<Item> myList;
};

template <class Item>
Queue<Item>::Queue(){
}

template <class Item>
Queue<Item>::~Queue(){
}

template <class Item>
void Queue<Item>::add(Item it){
    myList.append(it);
}

template <class Item>
Item Queue<Item>::remove(){
    return myList.removeFirst();
}


template <class Item>
unsigned Queue<Item>::getSize() const{
    return myList.getSize();
}

template <class Item>
Item Queue<Item>::peekFront() const{
    return myList.getFirst();
}

template <class Item>
Item Queue<Item>::peekBack() const{
    return myList.getLast();
}

template <class Item>
bool Queue<Item>::isEmpty() const{
    return myList.isEmpty();
}

#endif