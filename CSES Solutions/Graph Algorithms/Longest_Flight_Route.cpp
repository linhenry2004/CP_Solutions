#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long int 

const int mxn = 1e5 + 1;
int n, m;
vector<vector<int>> g(mxn);
vector<int> degree(mxn);
vector<int> dist(mxn, -1e9);
vector<int> par(mxn);

void top_sort () {
    queue<int> q;
    dist[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] < dist[u] + 1) {
                par[v] = u;
                dist[v] = dist[u] + 1;
            }
            degree[v]--;

            if (degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int32_t main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }

    top_sort();

    if (dist[n] < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(n);    
    while (ans.back() != 1) {
        ans.push_back(par[ans.back()]);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}