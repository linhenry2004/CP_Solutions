#include <bits/stdc++.h>
using namespace std;
#define int long long int

int BIS (int n) {
    int l = 0, r = n * n, m = n * n / 2 + (n & 1), mid, s;
    while (l != r) {
        s = 0;
        mid = (l + r) / 2;
        for (int i = 1; i <= n; i++) {
            s += min(n, mid / i);
        }
        if (s < m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int32_t main () {
    int n;
    cin >> n;
    cout << BIS(n) << endl;
    return 0;
}