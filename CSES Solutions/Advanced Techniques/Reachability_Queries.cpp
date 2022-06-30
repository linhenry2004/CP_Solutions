#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 1;
int cnt = 0;
bitset<maxn> vis;
array<int, maxn> in, scc;
array<vector<int>, maxn> G, R, S;
array<bitset<maxn>, maxn> dp;
stack<int> out, ord;

void bfs (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    for (int v : R[u]) {
        bfs(v);
    }
    out.push(u);
}

void dfs (int u) {
    if (scc[u]) {
        return;
    }
    scc[u] = cnt;
    for (int v : G[u]) {
        dfs(v);
    }
}

void topo (int n) {
    int u;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();
        ord.push(u);
        for (int v : S[u]) {
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }

    while (!ord.empty()) {
        u = ord.top();
        ord.pop();
        dp[u][u] = 1;
        for (int v : S[u]) {
            dp[u] |= dp[v];
        }
    }
}

int main () {
    int n, m, q;
    cin >> n >> m >> q;
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    while (!out.empty()) {
        int u = out.top();
        out.pop();
        if (!scc[u]) {
            cnt++;
        }
        dfs(u);
    }

    for (int i = 1; i <= n; i++) {
        for (int v : G[i]) {
            if (scc[v] == scc[i]) {
                continue;
            }
            in[scc[v]]++;
            S[scc[i]].push_back(scc[v]);
        }
    }

    topo(cnt);
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[scc[a]][scc[b]] ? "YES" : "NO") << endl;
    }
    return 0;
}