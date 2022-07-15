#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 504;
string S;
int vis[maxn][maxn], c[maxn][maxn], dp[maxn][maxn];

int C (int i, int j) {
    if (!j || i == j) {
        return 1;
    }
    if (c[i][j]) {
        return c[i][j];
    }
    return c[i][j] = (C(i - 1, j) + C(i - 1, j - 1)) % mod;
}

int DP (int i, int j) {
    if (i > j) {
        return 1;
    }
    if (j - i == 1) {
        return S[i] == S[j];
    }
    if ((j - i) % 2 == 0) {
        return 0;
    }
    if (vis[i][j]) {
        return dp[i][j];
    }
    vis[i][j] = 1;
    for (int k = i; k <= j; k++) {
        if (S[i] != S[k]) {
            continue;
        }
        dp[i][j] += (DP(i + 1, k - 1) * DP(k + 1, j) % mod) * C((j - i + 1) / 2, (k - i + 1) / 2) % mod;
        dp[i][j] %= mod;
    }
    return dp[i][j];
}

int32_t main () {
    cin >> S;
    cout << DP(0, S.size() - 1) << endl;
    return 0;
}