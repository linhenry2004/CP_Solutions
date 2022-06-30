#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 3001;
int C[maxn];
int dis[maxn][maxn], cst[maxn][maxn], turn[maxn][maxn], dp[maxn][maxn];

void DIS (int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            dis[i][j] = (i - j) * C[j] + dis[i][j + 1];
        }
        for (int j = i + 1; j <= n; j++) {
            dis[i][j] = (j - i) * C[j] + dis[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        cst[i][i] = 0;
        turn[i][i] = i;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1, j = i + k; j <= n; i++, j++) {
            cst[i][j] = 1e18;
            for (int t = turn[i][j - 1]; t <= turn[i + 1][j]; t++) {
                if (dis[t][i] + dis[t][j] < cst[i][j]) {
                    cst[i][j] = dis[t][i] + dis[t][j];
                    turn[i][j] = t;
                }
            }
        }
    }
}

void div (int ql, int qr, int l, int r, int k) {
    int t, qm = (ql + qr) >> 1;
    dp[k][qm] = 1e18;
    for (int i = l; i < min(r + 1, qm); i++) {
        if (dp[k][qm] > dp[k - 1][i] + cst[i + 1][qm]) {
            dp[k][qm] = dp[k - 1][i] + cst[i + 1][qm];
            t = i;
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
        dp[1][i] = cst[1][i];
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
        cin >> C[i];
    }
    DIS(n);
    cout << DP(n, k) << endl;
    return 0;
}