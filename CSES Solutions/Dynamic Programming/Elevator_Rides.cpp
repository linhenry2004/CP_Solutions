#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int limit = 1 << n;
    vector<vector<int>> dp(n + 1, vector<int> (limit, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if (dp[i - 1][j] >= 0) {
                dp[i][j] = x;
            } else {
                for (int k = 0; k < n; k++) {
                    if (j >> k & 1) {
                        dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << k)] - a[k]);
                    }
                }
            }
        }

        if (dp[i][limit - 1] >= 0) {
            cout << i << endl;
            return 0;
        }
    }
}