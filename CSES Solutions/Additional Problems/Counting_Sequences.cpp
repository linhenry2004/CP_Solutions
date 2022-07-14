#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 1e6 + 1;
int fac[maxn];

void build (int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i - 1] % mod;
    }
}

int exp (int x, int k) {
    int ans = 1;
    for (int i = 1; i <= k; i <<= 1) {
        if (i & k) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
    }
    return ans;
}

int C (int n, int k) {
    return (fac[n] * exp(fac[n - k], mod - 2) % mod) * exp(fac[k], mod - 2) % mod;
}

int math (int n, int k) {
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + ((exp(-1, k - i) * C(k, i) % mod) * exp(i, n) % mod)) % mod;
    }
    return ans;
}

int32_t main () {
    int n, k;
    cin >> n >> k;
    build (1e6);
    cout << math(n, k) << endl;
    return 0;
}