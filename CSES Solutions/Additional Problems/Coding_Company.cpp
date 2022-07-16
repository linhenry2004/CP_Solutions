#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 2e4 + 1;
array<int, 104> T;
array<array<array<int, maxn>, 104>, 2> dp;

int DP (int n, int x, int sum) {
    int p = 0, ans = 0;
    dp[0][0][sum] = 1;
    for (int i = 1; i <= n; i++) {
        p ^= 1;
        for (int j = 0; j <= i; j++) {
            for (int k = -sum; k <= sum; k++) {
                dp[p][j][k + sum] = 0;
                if (j && k + T[i] <= sum) {
                    dp[p][j][k + sum] += dp[p ^ 1][j - 1][k + T[i] + sum];
                }
                dp[p][j][k + sum] += (j + 1) * dp[p ^ 1][j][k + sum];
                if (k - T[i] >= -sum) {
                    dp[p][j][k + sum] += (j + 1) * dp[p ^ 1][j + 1][k - T[i] + sum];
                }
                dp[p][j][k + sum] %= mod;
            }
        }
    }
    for (int i = 0; i <= x; i++) {
        ans = (ans + dp[n & 1][0][i + sum]) % mod;
    }
    return ans;
}

int32_t main () {
    int n, x, sum = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        sum += T[i];
    }
    sort(T.begin() + 1, T.begin() + n + 1);
    cout << DP(n, x, sum)  << endl;
    return 0;
}