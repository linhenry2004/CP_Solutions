#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<int> adj[maxn];
int dep[maxn], jump[21][maxn];
int n, q;

void dfs(int u, int p, int l) {
    jump[0][u] = p;
    dep[u] = l;
	
	for (int v: adj[u]) {
		if(v != p) {
		    dfs(v, u, l + 1);
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
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
	for (int i = 1; 1<<i <= n ; i++) {
	    for (int j = 0; j <= n ; j++) {
	        jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    while (q--) {
        int a, b; 
        cin >> a >> b; 
        int lca = LCA(a, b);
        cout << dep[a] + dep[b] - 2 * dep[lca] << endl;
    }
}