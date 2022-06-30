#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e6 + 1;
const int mod = 1e9 + 7;
int fac[maxn];

void fact (int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
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

int cal (int n, int k) {
    return (((fac[n] * exp(fac[k], mod - 2)) % mod) * exp(fac[n - k], mod - 2)) % mod;
}

int32_t main () {
    int n, m;
    cin >> n >> m;
    fact(2e6);

    cout << cal(m + n - 1, n - 1) << endl;
    return 0;
}