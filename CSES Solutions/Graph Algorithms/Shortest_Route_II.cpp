#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long int
#define maxn 501
#define INF 1e15

int n, m, q;
vector<vector<int>> g;

void floyd_warshalls () {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) { continue; }
            for (int j = i + 1; j <= n; j++) {
                if (j == k) { continue; }
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int32_t main () {
    cin >> n >> m >> q;
    g.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        g[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c; 
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];
    }

    floyd_warshalls();

    for (int i = 0; i < q; i++) {
        int a, b; 
        cin >> a >> b; 
        if (g[a][b] == INF) {
            g[a][b] = -1;
        }
        cout << g[a][b] << endl;
    }
    return 0;
}