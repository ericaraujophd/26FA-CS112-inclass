#include <iostream>
#include <string>

using namespace std;

void registration(string name, int yob, string high_school="Grand Rapids Christian High School");

int main(){
    string n;
    int y; 
    string h;

    cout << "Your name, please: ";
    cin >> n;
    cout << "Your year of birth, monsieur: ";
    cin >> y;
    cout << "Where did you study for HS last year? ";
    cin >> h;
    if(h == "") registration(n, y);
    else registration(n, y, h);
    
    return 0;
}