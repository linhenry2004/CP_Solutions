#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
const int INF = 1e9;
int cnt = 0;
int bit[maxn], V[maxn], L[maxn], P[maxn];
vector<int> adj[maxn];

void update (int p, int v) {
    for (; p < maxn; p += p & -p) {
        bit[p] += v;
    }
}

int query (int p) {
    int sum = 0;
    for (; p > 0; p -= p & -p) {
        sum += bit[p];
    }
    return sum;
}

int dfs (int u, int p) {
    L[u] = INF;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        L[u] = min(L[u], dfs(v, u));
    }
    P[u] = ++cnt;
    return L[u] = min(L[u], P[u]);
}

int32_t main () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    dfs (1, 0);

    for (int i = 1; i <= n; i++) {
        update(P[i], V[i]);
    }

    while (q--) {
        int t, s;
        cin >> t >> s;
        if (t == 1) {
            int x;
            cin >> x;
            update(P[s], x - V[s]);
            V[s] = x;
        } else if (t == 2) {
            cout << query(P[s]) - query(L[s] - 1) << endl;
        }
    }
    return 0;
}