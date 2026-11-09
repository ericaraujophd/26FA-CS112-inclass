#include <iostream>

using namespace std;

unsigned factorial(unsigned n){
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int main(){
    cout << factorial(4) << endl;

    return 0;
}