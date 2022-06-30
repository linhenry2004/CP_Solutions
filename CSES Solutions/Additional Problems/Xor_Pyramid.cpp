#include <bits/stdc++.h>
using namespace std;

int C (int n, int k) {
    if (n == k || !k) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    return C(n >> 1, k >> 1) & C(n & 1, k & 1);
}

int main () {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; 
        if (C(n - 1, i)) {
            sum ^= x;
        }
    }
    cout << sum << endl;
    return 0;
}