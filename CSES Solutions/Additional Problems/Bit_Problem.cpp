#include <bits/stdc++.h>
using namespace std;

const int C = (1 << 20) - 1;
const int maxn = 2e5 + 1;
int X[maxn], O[maxn], A[maxn], R[maxn];
int dp[1 << 20];

void OR (int n) {
    for (int &d : dp) {
        d = 0;
    }
    for (int i = 1; i <= n; i++) {
        dp[X[i]]++;
    }
    for (int k = 1; k < 1 << 20; k <<= 1) {
        for (int i = 0; i < 1 << 20; i++) {
            if (i & k) {
                dp[i] += dp[i ^ k];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        O[i] = dp[X[i]];
        R[i] = n - dp[C ^ X[i]];
    }
}

void AND (int n) {
    for (int &d : dp) {
        d = 0;
    }
    for (int i = 1; i <= n; i++) {
        dp[X[i]]++;
    }
    for (int k = 1 << 19; k; k >>= 1) {
        for (int i = 0; i < 1 << 20; i++) {
            if (i & k) {
                continue;
            }
            dp[i] += dp[i ^ k];
        }
    }
    for (int i = 1; i <= n; i++) {
        A[i] = dp[X[i]];
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    OR(n);
    AND(n);
    for (int i = 1; i <= n; i++) {
        cout << O[i] << " " << A[i] << " " << R[i] << endl;
    }
    return 0;
}