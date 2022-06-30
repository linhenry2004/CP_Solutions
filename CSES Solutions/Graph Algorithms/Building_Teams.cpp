#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxn 1e5 + 1

int n, m;
vector<vector<int>> g(maxn);
vector<bool> vis(maxn);
vector<bool> team(maxn);
bool possible;

void dfs (int u, int p = 0) {
    for (auto v : g[u]) {
        if (v != p) {
            if (!vis[v]) {
                team[v] = !team[u];
                vis[v] = true;
                dfs(v, u);
            } else {
                if (team[v] == team[u]) {
                    possible = false;
                }
            }
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    possible = true;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int temp = !team[i] ? 1 : 2;
        cout << temp << " ";
    }

    cout << endl;
    return 0;
}