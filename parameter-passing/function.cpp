#include "function.h"
#include <iostream>
using namespace std;

// passing by value -> x is a copy of whatever is passed in
void square_value(int x){
    x = x * x;
}

// passing by reference -> x is a pointer to whatever is passed in
void square_reference(int &x){
    x = x * x;
}

// passing by reference -> x is a REAL pointer
void square_ptr(int *x){
    *x = *x * *x;
}

void square_const_reference(const int &x){
    int y = x * x;
    // x = x * x;
}

void test_noelle(const int x){
    cout << "Noelle was right!" << endl;
    cout << "And x = " << x << " btw!" << endl;
    
}

void test_caden(int &x){
    cout << "Caden without Y: " << endl;
    x = x +10;
}

// void function1(char ch){
//     cout << "First letter please: ";
//     cin >> ch;
//     switch (ch){
//         case 'a':
//             cout << "Arnold" << endl;
//             break;
//         case 'b':
//             cout << "Boo" << endl;
//             break;
//         case 'c':
//             cout << "Caden, Cayden, or Kaden" << endl;
//             break;
//         case 'd':
//             cout << "Daniel" << endl;
//             break;
//         case 'e':
//             cout << "Eric The Great" << endl;
//             break;
//         default:
//             cout << "All the other students are awesome!" << endl;
//     }
            
// }

// void function2(char &ch){
//     cout << "First letter please: ";
//     cin >> ch;
//     switch (ch){
//         case 'a':
//             cout << "Arnold" << endl;
//             break;
//         case 'b':
//             cout << "Boo" << endl;
//             break;
//         case 'c':
//             cout << "Caden, Cayden, or Kaden" << endl;
//             break;
//         case 'd':
//             cout << "Daniel" << endl;
//             break;
//         case 'e':
//             cout << "Eric The Great" << endl;
//             break;
//         default:
//             cout << "All the other students are awesome!" << endl;
//     }
            
// }

// void function3(const char &ch){
//     switch (ch){
//         case 'a':
//         cout << "Arnold" << endl;
//         break;
//         case 'b':
//         cout << "Boo" << endl;
//         break;
//         case 'c':
//         cout << "Caden, Cayden, or Kaden" << endl;
//         break;
//         case 'd':
//         cout << "Daniel" << endl;
//         break;
//         case 'e':
//         cout << "Eric The Great" << endl;
//         break;
//         default:
//         cout << "All the other students are awesome!" << endl;
//     }
    
// }

// void function4(char &ch){
//     // cout << "First letter please: ";
//     // cin >> ch;
//     switch (ch){
//         case 'a':
//             cout << "Arnold" << endl;
//             break;
//         case 'b':
//             cout << "Boo" << endl;
//             break;
//         case 'c':
//             cout << "Caden, Cayden, or Kaden" << endl;
//             break;
//         case 'd':
//             cout << "Daniel" << endl;
//             break;
//         case 'e':
//             cout << "Eric The Great" << endl;
//             break;
//         default:
//             cout << "All the other students are awesome!" << endl;
//     }
            
// }

// void function5(char &ch){
//     switch(ch){
//         case 'a':
//             ch = 'A';
//             break;
//         case 'e':
//             ch = 'E';
//             break;
//         case 'i':
//             ch = 'I';
//             break;
//         case 'o':
//             ch = 'O';
//             break;
//         case 'u':
//             ch = 'U';
//             break;
//         default:
//             cout << "A vowel you dumstick!" << endl;
//     }
// }