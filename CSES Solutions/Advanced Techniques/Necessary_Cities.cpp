#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int cnt = 0;
int P[maxn], low[maxn];
vector<int> G[maxn];
vector<int> knee;

void dfs (int u, int p) {
    int c = 0;
    bool ok = 0;
    P[u] = low[u] = ++cnt;
    for (int v : G[u]) {
        if (v == p) {
            continue;
        }
        if (P[v]) {
            low[u] = min(low[u], P[v]);
        } else {
            c++;
            dfs(v, u);
            if (low[v] >= P[u]) {
                ok = 1;
            }
            low[u] = min(low[u], low[v]);
        }
    }
    if ((ok && u > 1) || (u == 1 && c > 1)) {
        knee.push_back(u);
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

    cout << knee.size() << endl;
    for (int k : knee) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}