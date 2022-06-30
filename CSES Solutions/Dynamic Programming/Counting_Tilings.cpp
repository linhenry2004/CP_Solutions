#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, m;
int dp[1001][11][1 << 11];

int main () {
    cin >> m >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][m][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            dp[i][0][j << 1] = dp[i - 1][m][j];
        }

        for (int j = 1; j <= m; j++) {
            int x = (1 << (j - 1));
            int y = (1 << j);
            for (int s = 0; s < (1 << (m + 1)); s++){
                dp[i][j - 1][s] %= mod;
                if ((s & x) && (s & y)) {
                    continue;
                }
                if (s & x) {
                    dp[i][j][s^x] += dp[i][j-1][s];
                } else if (s & y) {
                    dp[i][j][s^y] += dp[i][j-1][s];
                } else {
                    dp[i][j][s ^ x] += dp[i][j - 1][s];
                    dp[i][j][s ^ y] += dp[i][j - 1][s];
                }
            }
        }
    }
    dp[n][m][0] %= mod;
    cout << dp[n][m][0] << endl;
    return 0;
}