#include <iostream>
using namespace std;

int rollDamage(int dice, int sides);

int main() {
    int hit = rollDamage(2, 6);
    cout << hit << endl;
}

int rollDamage(int dice, int sides) {
    int total = 0;
    for (int i = 0; i < dice; ++i) total += rand() % sides + 1;
    return total;
}