#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, d;
};

const int maxn = 1e5 + 1;
int cnt = 0;
bool odd[maxn];
int dep[maxn];
edge E[4 * maxn];
vector<int> G[maxn];

void add (int a, int b) {
    G[a].push_back(cnt);
    E[cnt++] = {b, 0};
    G[b].push_back(cnt);
    E[cnt++] = {a, 0};
}

void dfs (int u, int p, int d) {
    dep[u] = d;
    for (int i : G[u]) {
        auto &[v, t] = E[i];
        if (v == p) {
            continue;
        }
        if (dep[v]) {
            if (dep[v] < d) {
                t = 1;
                odd[u] ^= 1;
            }
        } else {
            dfs(v, u, d + 1);
            if (!E[i ^ 1].d) {
                t = 1;
                odd[u] ^= 1;
            }
        }
    }

    if (odd[u]) {
        for (int i : G[u]) {
            auto &[v, t] = E[i];
            if (v == p) {
                t = 1;
                odd[u] ^= 1;
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dep[i]) {
            dfs(i, 0, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (odd[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            auto [v, t] = E[j];
            if (t) {
                cout << i << " " << v << endl;
            }
        }
    }
    return 0;
}