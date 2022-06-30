#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main () {
    int n;
    cin >> n;
    ll sum = 0;
    ll maximum = -1;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        maximum = max(maximum, x);
    }

    if (maximum > (sum - maximum)) {
        cout << 2 * maximum << endl;
    } else {
        cout << sum << endl;
    }
    return 0;
}