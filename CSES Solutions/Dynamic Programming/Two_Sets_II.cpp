#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int32_t main () {
    int n;
    cin >> n;
    int target = n * (n + 1) / 2;
    if (target % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    target /= 2;
    vector<vector<int>> dp(n, vector<int> (target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0) {
                (dp[i][j] += dp[i - 1][j - i]) %= mod;
            }
        }
    }
    cout << dp[n - 1][target] << endl;
    return 0;
}