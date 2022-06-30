#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, d;
};

const int maxn = 1e5 + 1;
bitset<maxn> vis;
int dep[maxn];
vector<edge> G[maxn];

void dfs (int u, int pre, int d) {
    vis[u] = 1;
    dep[u] = d;
    for (auto &[v, t] : G[u]) {
        if (vis[v]) {
            if (dep[v] > d) {
                t = 1;
            }
        } else {
            dfs(v, u, d + 1);
            t  = 1;
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b; 
        cin >> a >> b; 
        G[a].push_back({b, 0});
        G[b].push_back({a, 0});
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [v, t] : G[i]) {
            if(t) {
                cout << i << " " << v << endl;
            }
        }
    }
    return 0;
}