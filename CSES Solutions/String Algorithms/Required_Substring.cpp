#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
int F[101];
int dp[1001][101];

void KMP (string &S) {
    int p = 0;
    for (int i = 2; i < S.size(); i++) {
        while (p && S[i - 1] != S[p]) {
            p = F[p];
        }
        if (S[i - 1] == S[p]) {
            p++;
        }
        F[i] = p;
    }
}

int DP (string &S, int n, int m) {
    int p;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                p = j;
                while (p && S[p] != k) {
                    p = F[p];
                }
                if (S[p] == k) {
                    p++;
                }
                dp[i][p] += dp[i - 1][j];
                dp[i][p] %= mod;
            }
        }
        dp[i][n] += dp[i - 1][n] * 26;
        dp[i][n] %= mod;
    }
    return dp[m][n];
}

int32_t main () {
    int n, m;
    string S;
    cin >> m >> S;
    n = S.size();
    KMP(S);
    cout << DP(S, n, m) << endl;
    return 0;
}