#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int p[k];
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    int dp[n +1] = {};
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - p[j] >= 0 && dp[i - p[j]] == 0) {
                dp[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ((dp[i] == 1) ? "W" : "L") << "";
    }
    cout << endl;
    return 0;
}