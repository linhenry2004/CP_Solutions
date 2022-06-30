#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e6 + 1;
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

// int cal (int n, int k) {
//     return (((fac[n] * exp(fac[k], mod - 2)) % mod) * exp(fac[n - k], mod - 2)) % mod;
// }

int32_t main () {
    int n;
    string str;
    cin >> n >> str;
    fact(1e6);
    
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans, r = 0, l = 0;
    n /= 2;
    for (char s : str) {
        if (s == '(') {
            l++;
        }
        if (s == ')') {
            r++;
        }

        if (r > l) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (l > n) {
        cout << 0 << endl;
        return 0;
    }

    ans = (((fac[2 * n - l - r] * exp(fac[n - l], mod - 2)) % mod) * exp(fac[n - r], mod - 2)) % mod;
    cout << (ans - (((fac[2 * n - l - r] * exp(fac[n - r + 1], mod - 2)) % mod) * exp(fac[n - l - 1], mod - 2)) % mod + mod) % mod << endl;
    return 0;
}