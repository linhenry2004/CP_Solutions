#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int32_t main () {
    int n;
    cin >> n;
    int max_sum = n * 1005;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool> (max_sum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_sum; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - a[i - 1];
            if (left >= 0 && dp[i - 1][left]) {
                dp[i][j] = true;
            }
        }
    }

    vector<int> ans;
    for (int j = 1; j < max_sum; j++) {
        if (dp[n][j]) {
            ans.push_back(j);
        }
    }

    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}