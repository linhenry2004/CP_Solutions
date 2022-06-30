#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long int

const int INF = 1e17;
const int NINF = INF * (-1);

struct triplet {
    int first;
    int second;
    int third;
};

int n, m;
vector<triplet> g;
vector<int> dist;

void bellman_ford () {
    for (int i = 1; i < n; i++) {
        for (auto e : g) {
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if (dist[u] == INF) {
                continue;
            }

            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
            }

            if (NINF > dist[v]) {
                dist[v] = NINF;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto e : g) {
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if (dist[u] == INF) {
                continue;
            }

            if (NINF > dist[v]) {
                dist[v] = NINF;
            }

            if (dist[u] + d < dist[v]) {
                dist[v] = NINF;
            }
        }
    }
}

int32_t main () {
    cin >> n >> m;
    dist.resize(n + 1);
    g.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        d *= -1; // See reason for this line below
        g[i].first = u;
        g[i].second = v;
        g[i].third = d;
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }

    bellman_ford();

    if (dist[n] == NINF) {
        cout << "-1" << endl;
        return 0;
    }

    cout << dist[n] * (-1) << endl;
    // Times -1 b/c we want to convert
    // negative single source shortest path to single source longest path 
    return 0;
}