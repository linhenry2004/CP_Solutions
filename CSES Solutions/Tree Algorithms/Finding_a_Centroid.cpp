#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, ans; 
vector<int> adj[maxn];

int dfs (int u, int p) {
    int s = 1, mux = 0, tmp;
    for (int v : adj[u]) {
        if(v == p) {
            continue;
        }
        tmp = dfs(v, u);
        s += tmp;
        mux = max(mux, tmp);
    }
    if(max(mux, n - s) <= n / 2) {
        ans = u;
    }
    return s;
}

int main () {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    cout << ans << endl;
    return 0;
}