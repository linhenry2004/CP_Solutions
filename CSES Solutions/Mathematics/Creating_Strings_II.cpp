#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
int cnt[26], fac[maxn];

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

int32_t main () {
    string str;
    cin >> str;
    fact(1e6);
    for (char s : str) {
        cnt[s - 'a']++;
    }

    int ans = fac[str.size()];
    for (int i = 0; i < 26; i++) {
        ans = (ans * exp(fac[cnt[i]], mod - 2)) % mod;
    }
    cout << ans << endl;
    return 0;
}