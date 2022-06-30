#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 +1;
int n, m;
vector<int> adj[maxn];
int dep[maxn], jump[21][maxn];
vector<int> prefix(maxn, 0);

void dfs (int u, int p, int l) {
    jump[0][u] = p;
    dep[u] = l;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, l + 1);
        }
    }
}

void dfs2 (int u, int p) {
    for (int v : adj[u]) {
        if (v - p) {
            dfs2(v, u);
            prefix[u] += prefix[v];
        }
    }
}

int LCA (int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
 
    int diff = dep[u] - dep[v];

    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            u = jump[i][u];
        }
    }
 
    if (u == v) {
        return u;
    }
 
    for (int j = 20; j >= 0; j--) {
        if (jump[j][u] != jump[j][v]) {
            u = jump[j][u];
            v = jump[j][v];
        }
    }
    return jump[0][u];
}

int main () {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    for (int i = 1; 1 << i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        prefix[u]++;
        prefix[v]++;
        int lca = LCA(u, v);
        prefix[lca]--;
        prefix[jump[0][lca]]--;
    }

    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << prefix[i] << " ";
    }
    cout << endl;
    return 0;
}