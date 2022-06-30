#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, d;
};

const int maxn = 1e5 + 1;
int k = 0;
bitset<maxn> vis;
int dep[maxn], scc[maxn];
vector<edge> G[maxn];
stack<int> out;

void dfst (int u, int p, int d) {
    dep[u] = d;
    for (auto &[v, t] : G[u]) {
        if (v == p) {
            continue;
        }
        if (dep[v]) {
            if (dep[v] < d) {
                t = 1;
            }
        } else {
            dfst(v, u, d + 1);
            t = 1;
        }
    }
}

void bfs (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    for (auto [v, t] : G[u]) {
        if (!t) {
            bfs(v);
        }
    }
    out.push(u);
}

void dfs (int u) {
    if (scc[u]) {
        return;
    }
    scc[u] = k;
    for (auto [v, t] : G[u]) {
        if(t) {
            dfs(v);
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
        if (!dep[i]) {
            dfst(i, 0, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    while (!out.empty()) {
        int u = out.top();
        out.pop();
        if (!scc[u]) {
            k++;
        }
        dfs(u);
    }
    if (k > 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            for (auto [v, t] : G[i]) {
                if (t) {
                    cout << i << " " << v << endl;
                }
            }
        }
    }
    return 0;
}