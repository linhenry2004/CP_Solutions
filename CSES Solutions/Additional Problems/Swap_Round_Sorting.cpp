#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
const int maxn = 2e5 + 1;
bitset<maxn> vis;
int G[maxn], R[maxn];
array<vector<pair<int, int>>, maxn> ans;

void cut (int u) {
    int l, r, nl, nr;
    if (G[u] == u || vis[u]) {
        return;
    }
    if (R[u] == G[u]) {
        if (vis[G[u]]) {
            return;
        }
        ans[cnt].push_back({u, G[u]});
        vis[u] = vis[G[u]] = 1;
        swap(G[u], G[G[u]]);
        swap(R[u], R[R[u]]);
    } else {
        while (true) {
            l = R[u], r = G[u];
            nl = R[l], nr = G[r];
            ans[cnt].push_back({l, r});
            vis[l] = vis[r] = 1;
            if (nr == l && nl == r) {
                R[l] = l;
                R[u] = r;
                swap(G[l], G[r]);
                return;
            } else {
                R[u] = r;
                R[nr] = l;
                swap(G[l], G[r]);
                u = l;
            }
            if (nl == nr) {
                return;
            }
            u = l;
        }
    }
}

void run (int n) {
    bool ok;
    while (true) {
        ok = 1;
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            ok &= G[i] == i;
        }
        if (ok) {
            return;
        }
        for (int i = 1; i <= n; i++) {
            cut(i);
        }
        cnt++;
    }
}

int main () {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        G[i] = x;
        R[x] = i;
    }
    run(n);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i].size() << endl;
        for (auto [u, v] : ans[i]) {
            cout << u << " " << v << endl;
        }
    }
    return 0;
}