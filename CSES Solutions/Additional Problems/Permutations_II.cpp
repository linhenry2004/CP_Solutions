#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
array<array<array<int, 2>, 1004>, 1004> dp;

int DP(int n){
    dp[1][0][0] = 1;
    dp[2][1][1] = 2;
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j][0] += (i - j - 2) * dp[i - 1][j][0];
            dp[i][j][0] += (i - j - 1) * dp[i - 1][j][1];
            dp[i][j][0] += (j + 1) * dp[i - 1][j + 1][0];
            dp[i][j][0] += j * dp[i - 1][j + 1][1];
            if (j) dp[i][j][1] += 2 * dp[i - 1][j - 1][0];
            dp[i][j][1] += dp[i - 1][j][1];
            if (j) dp[i][j][1] += dp[i - 1][j - 1][1];
            dp[i][j][0] %= mod, dp[i][j][1] %= mod;
        }
    }
    return dp[n][0][0];
}

signed main () {
    int n;
    cin >> n;
    cout << DP(n) << endl;
    return 0;
}