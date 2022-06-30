#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 1;
int ans = 1;
int vis[maxn];
vector<int> G[maxn];

void dfs (int u, int p) {
    vis[u]++;
    for (int v : G[u]) {
        if (v == p || vis[v] > 1) {
            continue;
        }
        if (vis[v] == 1) {
            ans = ans * 2 % mod;
        } else {
            dfs(v, u);
        }
    }
    vis[u]++;
}

int main () {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    cout << ans << endl;
    return 0;
}