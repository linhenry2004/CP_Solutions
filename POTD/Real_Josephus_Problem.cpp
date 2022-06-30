#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n;
    cin >> n;

    int temp = n;
    int x = 0;
    while (temp > 1) {
        temp /= 2;
        x++;
    }
    int minus = pow(2, x);

    n = ((n ^ minus) << 1) | 1;
    cout << n << endl;
    return 0;
}