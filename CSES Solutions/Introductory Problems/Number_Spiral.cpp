#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long

int main () {
    int n;
    cin >> n;
    while (n > 0) {
        ll y, x;
        cin >> y >> x;
        ll z = max(x, y);
        ll z2 = (z - 1) * (z - 1);
        ll ans;
        if (z % 2) {
            if (y == z) {
                ans = z2 + x;
            } else {
                ans = z2 + 2 * z - y;
            }
        } else {
            if (x == z) {
                ans = z2 + y;
            } else {
                ans = z2 + 2 * z - x;
            }
        }
        cout << ans << endl;
        n--;
    }
    return 0;
}