#include <bits/stdc++.h>
using namespace std;
#define matrix array<array<double, 601>, 101>

matrix dp;

int main () {
    int n, a, b; 
    cin >> n >> a >> b; 
    double all = 0, ans = 0;
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for(int j = i; j <= 6 * i; j++) {
            for (int k = 1; k <= 6; k++) {
                if (k > j) {
                    break;
                }
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    for (int i = 1; i <= 6 * n; i++) {
        all += dp[n][i];
        if (i >= a && i <= b) {
            ans += dp[n][i];
        }
    }
    cout << fixed << setprecision(6) << ans / all << endl;
    return 0;
}