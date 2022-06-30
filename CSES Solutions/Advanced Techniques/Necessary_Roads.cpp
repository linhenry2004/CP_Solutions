#include <bits/stdc++.h>
using namespace std;

struct E {
    int u, v;
};

const int maxn = 1e5 + 1;
int cnt = 0;
int low[maxn], P[maxn];
vector<int> G[maxn];
vector<E> B;

void dfs (int u, int p) {
    P[u] = low[u] = ++cnt;
    for (int v : G[u]) {
        if (v == p) {
            continue;
        }
        if (P[v]) {
            low[u] = min(low[u], P[v]);
        } else {
            dfs(v, u);
            if (low[v] > P[u]) {
                B.push_back({u, v});
            }
            low[u] = min(low[u], low[v]);
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b; 
        cin >> a >> b; 
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);

    cout << B.size() << endl;
    for (E e : B) {
        cout << e.u << " " << e.v << endl;
    }
    return 0;
}