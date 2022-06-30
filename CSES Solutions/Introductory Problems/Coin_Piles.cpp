#include <iostream>
using namespace std;

#define ll long long

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b; 

        if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}