#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int maxn = 1e5 + 1;
string S;
int p = 0;
int trie[10 * maxn][26];
int cnt[10 * maxn];
int dp[5001];

void update (string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!trie[u][s[i] - 'a']) {
            trie[u][s[i] - 'a'] = ++p;
        }
        u = trie[u][s[i] - 'a'];
    }
    cnt[u]++;
}

int query (int i) {
    int u = 0, ans = 0;
    for (; i < S.size(); i++) {
        if (!trie[u][S[i] - 'a']) {
            return ans;
        }
        u = trie[u][S[i] - 'a'];
        ans += (cnt[u] * dp[i + 1]) % mod;
        ans %= mod;
    }
    return ans;
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    string K;
    cin >> S >> k;
    while (k--) {
        cin >> K;
        update(K);
    }

    dp[S.size()] = 1;
    for (int i = S.size() - 1; i >= 0; i--) {
        dp[i] += query(i);
    }

    cout << dp[0] << endl;
    return 0;
}