#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int exp (int x, int k) {
    int ans = 1;
    for (int i = 1; i <= k; i <<= 1) {
        if (i & k) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
    }
    return ans;
}

int32_t main () {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }

    int n0 = n * n, n1, n2, ans = 0;
    if (n & 1) {
        n1 = (n * n - 1) / 4 + 1;
        n2 = (n * n - 1) / 2 + 1;
    } else {
        n1 = (n * n) / 4;
        n2 = (n * n) / 2;
    }

    ans += exp(2, n0);
    ans += exp(2, n1 + 1);
    ans += exp(2, n2);
    ans %= mod;
    ans = (ans * exp(4, mod - 2)) % mod;
    cout << ans << endl;
    return 0;
}