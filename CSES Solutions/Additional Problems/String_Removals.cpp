#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 5e5 + 1;
int dp[maxn];

int DP (string &S) {
    int n = S.size(), ans = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = (dp[i] + dp[j]) % mod;
            if (!j || S[i - 1] == S[j - 1]) {
                break;
            }
        }
        ans = (ans + dp[i]) % mod;
    }
    return ans;
}

int32_t main () {
    string S;
    cin >> S;
    cout << DP(S) << endl;
    return 0;
}