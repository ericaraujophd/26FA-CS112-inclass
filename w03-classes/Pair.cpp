#include "Pair.h"

// default constructor
Pair::Pair(){
    first = Item();
    second = Item();
}

// explicit-value constructor
Pair::Pair(Item f, Item s){
    first = f;
    second = s;
}

// getters
Item Pair::getFirst() const {
    return first;
}

Item Pair::getSecond() const {
    return second;
}

// setters
void Pair::setFirst(Item f){
    first = f;
}

void Pair::setSecond(Item s){
    second = s;
}

void Pair::add(Pair &p2){
    first += p2.getFirst();
    second += p2.getSecond();
}

Pair& Pair::operator=(const Pair &p){
    first = p.first;
    second = p.second;
    return *this;
}

// operator overload for << passing a Pair
ostream& operator<<(ostream &out, const Pair &p){
    out << "(" << p.getFirst() << ", " << p.getSecond() << ")" << endl;
    return out;
}