#include <iostream>
#include "function.h"

using namespace std;


int main(){
    int var = 5;
    square_value(var);
    cout << "After calling square_value(): " << var << endl;
    
    square_reference(var);
    cout << "After calling square_reference(): " << var << endl;
    
    square_ptr(&var);
    cout << "After calling square_ptr(): " << var << endl;

    int x = 4;
    test_noelle(x);
    test_caden(4);

    return 0;
}