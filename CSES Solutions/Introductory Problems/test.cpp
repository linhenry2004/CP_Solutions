#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<bool> A(4, -1);
    for (auto a : A) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}