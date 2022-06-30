#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n;
vector<int> adj[maxn];

pair<int, int> bfs (int u) {
    int d = 0;
    queue<pair<int, int>> q;
    q.push({u, 0});
    vector<bool> vis(maxn, false);
    pair<int, int> top;

    while (!q.empty()) {
        top = q.front();
        vis[top.first] = true;
        q.pop();
        for (int v : adj[top.first]) {
            if(!vis[v]) {
                q.push({v, top.second + 1});
            }
        }
    }

    return top;
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> end1 = bfs(1);
    pair<int, int> end2 = bfs(end1.first);
    cout << end2.second << endl;
    return 0;
}