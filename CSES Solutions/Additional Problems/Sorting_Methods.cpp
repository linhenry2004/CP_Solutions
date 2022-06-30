#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
bitset<maxn> vis;
int P[maxn], pre[maxn], mix[maxn];

void update (int t, int p, int x) {
    for (; p < maxn; p += p & -p) {
        if (t) {
            mix[p] = max(mix[p], x);
        } else {
            pre[p] += x;
        }
    }
}

int query (int t, int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        if (t) {
            ans = max(ans, mix[p]);
        } else {
            ans += pre[p];
        }
    }
    return ans;
}

void DFS (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    DFS(P[u]);
}

int32_t main () {
    int n, lis = 0, inv = 0, cyc = 0, dec = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        update(0, P[i], 1);
        inv += query(0, 2e5) - query(0, P[i]);
        lis = max(lis, query(1, P[i]) + 1);
        update(1, P[i], query(1, P[i]) + 1);
    }
    for (int i = n, p = n; i; i--) {
        if (!vis[i]) {
            DFS(i);
            cyc++;
        }
        if (P[i] == p) {
            p--;
            dec++;
        }
    }
    cout << inv << " " << n - cyc << " " << n - lis << " " << n - dec << endl;
    return 0;
}