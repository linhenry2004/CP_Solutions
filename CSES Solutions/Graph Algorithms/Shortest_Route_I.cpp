#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define int long long int
#define maxn 2e5 + 1
#define maxd 1e17

int n, m;
vector<vector<pair<int,int>>> g(maxn);
vector<int> dist(maxn, maxd);

void dijkstra () {
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // {Distance, Vertex}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < d) {
            continue;
        }

        for (auto e : g[u]) {
            int v = e.first;
            int c = e.second;
            if (dist[v] <= c + d) {
                continue;
            } else {
                dist[v] = c + d;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main () {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    cout << endl;
    return 0;
}