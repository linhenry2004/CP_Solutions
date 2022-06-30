#include <bits/stdc++.h>
using namespace std;

struct E {
    int v, t;
};

const int maxn = 2e5 + 1;
int cnt = 0;
int in[maxn], out[maxn], dsu[maxn];
int A[maxn][20], T[maxn][20];
vector<E> G[maxn];

int find (int u) {
    if (dsu[u] == u) {
        return u;
    } 
    return dsu[u] = find(dsu[u]);
}

void onion (int a, int b) {
    int A = find(a), B = find(b);
    dsu[A] = B;
}

void dfs (int u) {
    in[u] = ++cnt;
    for (auto [v, t] : G[u]) {
        if (in[v]) {
            continue;
        }
        dfs(v);
        T[v][0] = t;
        A[v][0] = u;
    }
    out[u] = ++cnt;
}

void dabo (int n) {
    in[0] = 0, out[0] = 1e9;
    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= n; i++) {
            A[i][j] = A[A[i][j - 1]][j - 1];
            T[i][j] = max(T[i][j - 1], T[A[i][j - 1]][j - 1]);
        }
    }
}

int query (int a, int b) {
    if (find(a) != find(b)) {
        return -1;
    }
    int ans = 0;
    for (int i = 17; i >= 0; i--) {
        if (in[A[a][i]] > in[b] || out[A[a][i]] < out[b]) {
            ans = max(ans, T[a][i]);
            a = A[a][i];
        }
    }
    if (in[a] > in[b] || out[a] < out[b]) {
        ans = max(ans, T[a][0]);
        a = A[a][0];
    }
    for (int i = 17; i >= 0; i--) {
        if (in[A[b][i]] > in[a] || out[A[b][i]] < out[a]) {
            ans = max(ans, T[b][i]);
            b = A[b][i];
        }
    }
    if (in[b] > in[a] || out[b] < out[a]) {
        ans = max(ans, T[b][0]);
        b = A[b][0];
    }
    return ans;
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b; 
        cin >> a >> b;
        if(find(a) == find(b)) {
            continue;
        }
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        onion(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dfs(i);
        }
    }

    dabo(n);

    while (q--) {
        int a, b; 
        cin >> a >> b; 
        cout << query(a, b) << endl;
    }
    return 0;
}