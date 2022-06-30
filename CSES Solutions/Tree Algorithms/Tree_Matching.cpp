#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<int> adj[maxn];
int in[maxn];

int dfs (int u, int p) {
    int cnt = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        cnt += dfs(v, u);
        if (!in[v] && !in[u]) {
            cnt++;
            in[u] = 1;
        }
    }
    return cnt;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(1, 0) << endl;
    return 0;
}