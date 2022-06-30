#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n;
vector<vector<int>> g(maxn);
vector<int> dp(maxn);

void dfs (int u, int l, int p) {
    dp[u] = 1;

    for (int v : g[u]) {
        if (v != p) {
            dfs(v, l + 1, u);
            dp[u] += dp[v];
        }
    }
}

int main () {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] - 1 << " ";
    }
    return 0;
}