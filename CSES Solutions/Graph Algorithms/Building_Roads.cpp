#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxn 2e5 + 1

vector<vector<int>> g(maxn);
vector<bool> vis(maxn);
vector<int> lead;

void bfs (int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while(true) {
        int v = q.front();
        q.pop();
        for (auto t : g[v]) {
            if (!vis[t]) {
                q.push(t);
                vis[t] = true;
            }
        }
        
        if (q.empty()) {
            break;
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            lead.push_back(i);
            bfs(i);
        }
    }
    cout << lead.size() - 1 << endl;
    for (int i = 0; i < lead.size() - 1; i++) {
        cout << lead[i] << " " << lead[i + 1] << endl;
    }
    return 0;
}