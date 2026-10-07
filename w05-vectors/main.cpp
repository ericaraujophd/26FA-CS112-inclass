#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

int main(){
    vector<string> names;
    names.push_back("Micaiah");
    names.push_back("Cayden");
    names.push_back("Ana Clara");
    names.push_back("Diego");
    assert(names[3] == "Diego");
    assert(names.size() == 4);
    cout << "All good.\n";

    for (vector<string>::iterator it = names.begin(); it != names.end(); it++){
        cout << *it << endl;
    }
    
    cout << "====================" << endl;
    
    names.push_back("Marshall");
    names.push_back("Isaiah");
    for (vector<string>::iterator it = names.begin() + names.size()/2; it != names.end(); it++){
        cout << *it << endl;
    }
    return 0;
}