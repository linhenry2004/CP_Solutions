#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n;
vector<int> adj[maxn];
vector<int> ans(maxn, -1);

int bfs (int u) {
    int top;
    queue<int> q;
    vector<int> d(n + 1, -1);
    d[u] = 0;
    ans[u] = max(ans[u], d[u]);
    q.push(u);

    while (!q.empty()) {
        top = q.front();
        q.pop();

        for (int v : adj[top]) {
            if(d[v] == -1) {
                q.push(v);
                d[v] = d[top] + 1;
                ans[v] = max(ans[v], d[v]);
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

    int end1 = bfs(1);
    int end2 = bfs(end1);
    bfs(end2);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}