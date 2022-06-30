#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    bool notExp = false;
    int x = 0;
    while (n > 1) {
        if (n % 2 == 1) {
            notExp = true;
        }
        n /= 2;
        x++;
    }

    if (notExp) {
        x++;
    }

    cout << x << endl;
    return 0;
}