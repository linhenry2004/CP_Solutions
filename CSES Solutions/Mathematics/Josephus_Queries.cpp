#include <bits/stdc++.h>
using namespace std;

int jos (int n, int k, int f) {
    if (n == 1) {
        return 1;
    }
    int kill = (n + f) / 2, nk;

    if (k <= kill) {
        return 2 * k - f;
    } else {
        nk = jos(n - kill, k - kill, (n ^ f) & 1);
        return 2 * nk - (1 ^ f);
    }
}

int main () {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << jos(n, k, 0) << endl;
    }
    return 0;
}