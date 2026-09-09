#include <iostream>
#include "function.h"

using namespace std;


int main(){
    int var = 5;
    square_value(var);
    cout << "After calling square_value(): " << var << endl;
    
    square_reference(var);
    cout << "After calling square_reference(): " << var << endl;

    // square_ptr(&var);
    return 0;
}