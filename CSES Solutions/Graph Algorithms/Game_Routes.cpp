#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define int long long int 

int n, m;
vector<vector<int>> g;
vector<int> cnt; 
vector<int> degree;
const int modb = 1e9 + 7;

void top_sort () {
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            degree[v]--;
            if (degree[v] == 0 && v != 1) {
                q.push(v);
            }
        }
    }

    q.push(1);
    cnt[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            degree[v]--;
            cnt[v] += cnt[u];
            cnt[v] %= modb;
            if (!degree[v]) {
                q.push(v);
            }
        }
    }
}

int32_t main () {
    cin >> n >> m;
    g.resize(n + 1);
    cnt.resize(n + 1);
    degree.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        degree[v]++;
    }

    top_sort();

    cout << cnt[n] << endl;
    return 0;
}