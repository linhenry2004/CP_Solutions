#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int ans[maxn], C[maxn];
vector<int> adj[maxn];

set<int> dfs (int u, int p) {
    set<int> s, tmp;
    s.insert(C[u]);
    for (int v : adj[u]) {
        if (v == p) { continue; }
        tmp = dfs(v, u);
        if (tmp.size() > s.size()) { swap(s, tmp); }
        for (int it : tmp) {
            s.insert(it);
        }
    }
    ans[u] = s.size();
    return s;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}