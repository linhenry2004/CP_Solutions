#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 20;
const int mod = 1e9 + 7;
int n, m;
ll dp[1<<maxn][maxn];
ll adj[maxn][maxn];

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b]++;
    }
    dp[1][0] = 1;
    for (int i = 2; i < 1 << n; i++) {
        if (i >> (n - 1) & 1 && i != (1 << n) - 1) {
            continue;
        }
        
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                int i2 = i ^ 1 << j;
                
                for (int k = 0; k < n; k++) {
                    if (i2 >> k & 1 && adj[k][j]) {
                        dp[i][j] += adj[k][j] * dp[i2][k];
                    }
                }

                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}