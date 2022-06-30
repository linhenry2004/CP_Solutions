#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5 + 1;
int n, q;
int dep[maxn], par[maxn][21];
 
int LCA (int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
 
    int diff = dep[u] - dep[v];

    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
 
    if (u == v) {
        return u;
    }
 
    for (int j = 20; j >= 0; j--) {
        if (par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}
 
int main () {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        dep[i] = dep[u] + 1;
        par[i][0] = u;
    }

    for (int i = 1; 1<<i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
 
    return 0;
}