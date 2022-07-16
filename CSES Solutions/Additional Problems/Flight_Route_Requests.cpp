#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
bitset<maxn> vis;
int in[maxn];
vector<pair<int, int>> G[maxn];
vector<int> V;

void DFS (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    V.push_back(u);
    for (auto [v, d] : G[u]) {
        if (d) {
            in[v]++;
        }
        DFS(v);
    }
}

int topu (int u) {
    if (vis[u]) {
        return 0;
    }
    int nc = 0;
    V.clear();
    DFS(u);
    queue<int> Q;
    for (int v : V) {
        if (!in[v]) {
            Q.push(v);
        }
    }
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        nc++;
        for (auto [v, d] : G[u]) {
            if (!d) {
                continue;
            }
            in[v]--;
            if (!in[v]) {
                Q.push(v);
            }
        }
    }
    return nc == V.size() ? V.size() - 1 : V.size();
}

int main () {
    int n, m, a, b, edge = 0;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        G[a].push_back({b, 1});
        G[b].push_back({a, 0});
    }
    for (int i = 1; i <= n; i++) {
        edge += topu(i);
    }
    cout << edge << endl;
    return 0;
}