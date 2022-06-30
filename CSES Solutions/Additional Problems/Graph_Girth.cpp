#include <bits/stdc++.h>
using namespace std;

const int maxn = 2501;
int dis[maxn];
vector<int> G[maxn];

int BFS (int s) {
    int ans = 1e9;
    queue<pair<int, int>> Q;
    dis[s] = 1;
    Q.push({s, 0});
    while (!Q.empty()) {
        auto [u, p] = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (v == p) {
                continue;
            }
            if (dis[v]) {
                ans = min(ans, dis[u] + dis[v] - 1);
            } else {
                dis[v] = dis[u] + 1;
                Q.push({v, u});
            }
        }
    }
    return ans;
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
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int &d : dis) {
            d = 0;
        }
        ans = min(ans, BFS(i));
    }

    int tmp = -1;
    cout << ((ans >= 1e9) ? tmp : ans) << endl;
    return 0;
}