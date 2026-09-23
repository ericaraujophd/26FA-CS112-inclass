#include "Pair.h"

// default constructor
Pair::Pair(){
    first = 0;
    second = 0;
}

// explicit-value constructor
Pair::Pair(int f, int s){
    first = f;
    second = s;
}

// getters
int Pair::getFirst() const {
    return first;
}

int Pair::getSecond() const {
    return second;
}

// setters
void Pair::setFirst(int f){
    first = f;
}

void Pair::setSecond(int s){
    second = s;
}

void Pair::add(Pair &p2){
    first += p2.getFirst();
    second += p2.getSecond();
}

const Pair& operator=(Pair &p, Pair &q){

}

// operator overload for << passing a Pair
ostream& operator<<(ostream &out, const Pair &p){
    out << "(" << p.getFirst() << ", " << p.getSecond() << ")" << endl;
    return out;
}