#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct trap {
    int x, y;
};

const int mod = 1e9 + 7;
const int maxn = 2e6 + 1;
int dp[1001];
int fac[maxn];
vector<trap> T;

bool cmp (trap a, trap b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

void build (int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i - 1] % mod;
    }
}

int exp (int x, int k) {
    int pro = 1;
    for (int i = 1; i <= k; i <<= 1) {
        if (i & k) {
            pro = pro * x % mod;
        }
        x = x * x % mod;
    }
    return pro;
}

int C (int n, int k) {
    return (fac[n] * exp(fac[n - k], mod - 2) % mod) * exp(fac[k], mod - 2) % mod;
}

int DP(int n){
    for (int i = 0; i <= n; i++) {
        auto [x, y] = T[i];
        dp[i] = C(x + y - 2, x - 1);
        for (int j = 0; j < i; j++) {
            auto [tx, ty] = T[j];
            if(y < ty) {
                continue;
            }
            dp[i] = (dp[i] - dp[j] * C(x - tx + y - ty, x - tx) % mod + mod) % mod;
        }
    }
    return dp[n];
}

int32_t main () {
    int n, m, x, y;
    cin >> n >> m;
    build (2 * n);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        T.push_back({x, y});
    }
    T.push_back({n, n});
    sort(T.begin(), T.end(), cmp);
    cout << DP(m) << endl;
    return 0;
}