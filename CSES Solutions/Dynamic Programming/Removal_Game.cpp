#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> x(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    vector<vector<int>> dp(n,vector<int>(n));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = x[l];
            } else {
                dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;
}