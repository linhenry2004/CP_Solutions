#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int INF  = 1e9;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int h[n];
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1] - h[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = INF;
        for (int j = 1; j <= k && i - j >= 0; j++) {
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
    }

    cout << dp[n - 1] << endl;
    return 0;
}