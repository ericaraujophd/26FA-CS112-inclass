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
int Pair::getFirst(){
    return first;
}

int Pair::getSecond(){
    return second;
}

// setters
void Pair::setFirst(int f){
    first = f;
}

void Pair::setSecond(int s){
    second = s;
}