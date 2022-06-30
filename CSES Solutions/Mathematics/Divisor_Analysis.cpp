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
    int n, num = 1, sum = 1, pro = 1, cnt = 1;
    cin >> n;
    while (n--) {
        int x, k;
        cin >> x >> k;
        num *= (k + 1);
        num %= mod;
        sum *= (((exp(x, k + 1) - 1 + mod) % mod) * exp(x - 1, mod - 2)) % mod; 
        sum %= mod;
        pro = (exp(pro, k + 1) * exp(exp(x, k * (k + 1) / 2), cnt)) % mod;
        cnt *= (k + 1);
        cnt %= (mod - 1);
    }
    cout << num << " " << sum << " " << pro << endl;
    return 0;
}