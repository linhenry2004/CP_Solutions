#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, m;
int sv, ev;
vector<vector<int>> a(maxn);
vector<int> par(maxn);
vector<bool> vis(maxn);

bool dfs (int u, int p) {
    vis[u] = true;
    par[u] = p;

    for (auto v : a[u]) {
        if (v == p) {
            continue;
        }

        if (vis[v]) { 
            sv = v;
            ev = u;
            return true;
        }

        if (!vis[v] && dfs(v, u)) {
            return true;
        }
    }
    return false;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            break;
        }
    }

    int tv = ev;
    vector<int> ans;
    ans.push_back(tv);
    while (tv != sv) {
        ans.push_back(par[tv]);
        tv = par[tv];
    }
    ans.push_back(ev);

    if (ans.size() <= 2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.size() << endl;
        for (auto c : ans) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}