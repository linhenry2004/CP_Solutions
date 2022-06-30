#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

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
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ans = (ans + exp(m, gcd(n, i))) % mod;
    }
    cout << (ans * exp(n, mod - 2)) % mod << endl;
    return 0;
}