#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e5;
int a[maxn][3], dp[maxn][3];

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
                }
            }
        }
    }

    cout << *max_element(dp[n - 1], dp[n - 1] + 3) << endl;
    return 0;
}