#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define maxn 1e5 + 1

vector<vector<int>> g(maxn);
vector<bool> vis(maxn);
vector<int> par(maxn, -1);

void bfs () {
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (true) {
        int node = q.front();
        q.pop();

        for (auto u : g[node]) {
            if (!vis[u]) {
                vis[u] = true;
                par[u] = node;
                q.push(u);
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

    bfs();

    if (par[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int curr = n;
    stack<int> stk;
    
    while (curr != -1) {
        stk.push(curr);
        curr = par[curr];
    }

    cout << stk.size() << endl;

    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    return 0;
}