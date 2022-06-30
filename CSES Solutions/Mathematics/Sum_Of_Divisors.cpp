#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int m = 5e8 + 4;

int32_t main () {
    int n, ans = 0;
    cin >> n;
    int gh = sqrt(n);
    for (int i = 1; i <= gh; i++) {
        int l = n / i;
        int r = n / (i + 1) + 1;
        ans += (((((((l - r + 1) % mod) * ((l + r) % mod)) % mod) * m) % mod) * i) % mod;
        ans %= mod;
    }

    for (int i = 1; i <= n / (gh + 1); i++) {
        ans += (n / i) * i;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}