#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 14e4 + 1;
int dp[501][maxn];

int DP (int n, int k) {
    int p, sum;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        sum = p = 0;
        for (int j = 0; j <= k; j++) {
            if (j - p >= i) {
                sum -= dp[i - 1][p];
                p++;
            }
            sum += dp[i - 1][j];
            dp[i][j] = sum % mod;
        }
    }
    return dp[n][k];
}

int32_t main () {
    int n, k;
    cin >> n >> k;
    cout << DP(n, k) << endl;
    return 0;
}