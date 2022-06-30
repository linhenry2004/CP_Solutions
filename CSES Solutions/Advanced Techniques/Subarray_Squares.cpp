#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 3001;
int X[maxn];
int dp[maxn][maxn];

int cost (int l, int r) {
    return (X[r] - X[l]) * (X[r] - X[l]);
}

void div (int ql, int qr, int l, int r, int k) {
    int t, qm = (ql + qr) >> 1;
    dp[k][qm] = 1e18;
    for (int i = l; i < min(r + 1, qm); i++) {
        if (dp[k - 1][i] + cost(i, qm) < dp[k][qm]) {
            t = i;
            dp[k][qm] = dp[k - 1][i] + cost(i, qm);
        }
    }
    if (ql == qr) {
        return;
    }
    div(ql, qm, l, t, k);
    div(qm + 1, qr, t, r, k);
}

int DP (int n, int k) {
    for (int i = 1; i <= n; i++) {
        dp[1][i] = X[i] * X[i];
    }
    for (int i = 2; i <= k; i++) {
        div(i, n, i - 1, n, i);
    }
    return dp[k][n];
}

int32_t main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        X[i] += X[i - 1];
    }
    cout << DP(n, k) << endl;
    return 0;
}