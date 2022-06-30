#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 5001;
int X[maxn];
int dp[maxn][maxn], turn[maxn][maxn];

int DP (int n) {
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        turn[i][i] = i;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1, j = i + k; j <= n; i++, j++) {
            dp[i][j] = 1e18;
            for (int t = turn[i][j - 1]; t <= turn[i + 1][j]; t++) {
                if (dp[i][t] + dp[t + 1][j] < dp[i][j]) {
                    turn[i][j] = t;
                    dp[i][j] = dp[i][t] + dp[t + 1][j];
                }
            }
            dp[i][j] += X[j] - X[i - 1];
        }
    }
    return dp[1][n];
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        X[i] += X[i - 1];
    }
    cout << DP(n) << endl;
    return 0;
}