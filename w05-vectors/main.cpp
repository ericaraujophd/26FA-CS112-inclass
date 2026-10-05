#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

int main(){
    vector<string> stds;
    stds.push_back("Micaiah");
    stds.push_back("Cayden");
    stds.push_back("Ana Clara");
    stds.push_back("Diego");
    assert(stds[3] == "Diego");
    assert(stds.size() == 4);
    cout << "All good.\n";
    return 0;
}