#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
const int maxn = 1e5 + 1;
int P[maxn], rev[maxn], L[maxn], DSU[maxn], pre[maxn], sdom[maxn], idom[maxn];
vector<int> G[maxn], R[maxn], buk[maxn];
vector<int> ans;

int find (int u, int x = 0) {
    if (DSU[u] == u) {
        return x ? -1 : u;
    }
    int v = find(DSU[u], x + 1);
    if (v < 0) {
        return u;
    }
    if (sdom[L[DSU[u]]] < sdom[L[u]]) {
        L[u] = L[DSU[u]];
    }
    DSU[u] = v;
    return x ? v : L[u];
}

void onion (int u, int v) {
    DSU[v] = u;
}

void DFS (int u) {
    P[u] = ++cnt, rev[cnt] = u, L[cnt] = cnt, DSU[cnt] = cnt, sdom[cnt] = cnt;
    for (int v : G[u]) {
        if (!P[v]) {
            DFS(v);
            pre[P[v]] = P[u];
        }
        R[P[v]].push_back(P[u]);
    }
}

void run (int u) {
    ans.push_back(rev[u]);
    if (u == 1) {
        return;
    }
    run(idom[u]);
}

int main () {
    int n, m, a, b, w;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        G[a].push_back(b);
    }

    DFS(1);

    for (int u = n; u; u--) {
        for (int v : R[u]) {
            sdom[u] = min(sdom[u], sdom[find(v)]);
        }
        if (u > 1) {
            buk[sdom[u]].push_back(u);
        }
        for (int v : buk[u]) {
            w = find(v);
            if (sdom[v] == sdom[w]) {
                idom[v] = sdom[v];
            } else {
                idom[v] = w;
            }
        }
        onion(pre[u], u);
    }
    for (int u = 2; u <= n; u++) {
        if(idom[u] != sdom[u]) {
            idom[u] = idom[idom[u]];
        }
    }

    run(P[n]);
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (int u : ans) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}