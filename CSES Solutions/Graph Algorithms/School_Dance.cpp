#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
int n, m, k;
int mt[maxn];
vector<int> adj[maxn];
bool vis[maxn];

bool dfs (int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if(mt[v] < 0 || !vis[mt[v]] && dfs(mt[v])) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b; 
        cin >> a >> b; 
        a--; 
        b--; 
        adj[a].push_back(b);
    }

    int f = 0;
    memset(mt, -1, 4 * m);
    memset(vis, 0, n);
    for (int i = 0; i < n; i++) {
        memset(vis, 0, n);
        f += dfs(i);
    }

    cout << f << endl;
    for (int i = 0; i < m; i++) {
        if (~mt[i]) {
            cout << mt[i] + 1 << " " << i + 1 << endl;
        }
    }
    return 0;
}