#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e5 + 1;
int l, r;
int H[101], S[101], K[101];
int Q[maxn];
int dp[2][maxn];

int DP (int n, int x) {
    int p = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        p ^= 1;
        for (int j = 0; j < H[i]; j++) {
            l = 0, r = -1;
            for (int k = j; k <= x; k += H[i]) {
                if (l <= r && Q[l] + K[i] * H[i] < k) {
                    l++;
                }
                while (l <= r && dp[p ^ 1][k] >= dp[p ^ 1][Q[r]] + (k - Q[r]) / H[i] * S[i]) {
                    r--;
                }
                Q[++r] = k;
                dp[p][k] = dp[p ^ 1][Q[l]] + (k - Q[l]) / H[i] * S[i];
                ans = max(ans, dp[p][k]);
            }
        }
    }
    return ans;
}

int32_t main () {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> K[i];
    }
    cout << DP(n, x) << endl;
    return 0;
}