#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n, q, dt;
int t[maxn], d[maxn], rt[maxn], rp[maxn], cr[maxn], cs[maxn], ds[maxn], de[maxn];
vector<int> adj[maxn], cyc;
bool vis[maxn];

void dfs (int u) {
    ds[u] = dt++;
    for (int v : adj[u]) {
        if (rt[v] ^ v) {
            d[v] = d[u] + 1;
            rt[v] = rt[u];
            cr[v] = cr[u];
            dfs(v);
        }
    }
    de[u] = dt;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
        adj[t[i]].push_back(i);
    }

    memset(rt, -1, 4 * n);

    for (int i = 0; i < n; i++) {
        if (~rt[i]) {
            continue;
        }
        
        int u = i;
        while (!vis[u]) {
            vis[u] = 1;
            u = t[u];
        }

        while (!cyc.size() || u ^ cyc[0]) {
            rp[u] = cyc.size();
            cyc.push_back(u);
            rt[u] = u;
            cr[u] = i;
            u = t[u];
        }

        for (int ci : cyc) {
            dt = 0;
            dfs(ci);
            cs[ci] = cyc.size();
        }
        cyc.clear();
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] + cs[rt[i]] << " ";
    }

    // while (q--) {
    //     int a, b; 
    //     cin >> a >> b; 
    //     a--;
    //     b--;
    //     int ans = -1;
    //     if (cr[a] == cr[b]) {
    //         if (rt[b] == b) {
    //             ans = d[a];
    //             a = rt[a];
    //             ans += (rp[b] - rp[a] + cs[a]) % cs[a];
    //         } else {
    //             if (rt[a] == rt[b] && ds[b] <= ds[a] && ds[a] < de[b]) {
    //                 ans = d[a] - d[b];
    //             }
    //         }
    //     }
    //     cout << ans << endl;
    // }
    cout << endl;
    return 0;
}