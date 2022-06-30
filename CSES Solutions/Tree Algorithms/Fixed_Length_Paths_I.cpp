#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int n, k;
vector<int> adj[maxn], C[maxn];
int S[maxn], M[maxn], cnt[maxn];
bool vis[maxn];
vector<int> leaf;

int dfs (int u, int p, int s) {
    if (vis[u] || s > k) {
        return 0;
    }
    int sum = 0;
    sum += cnt[k - s];
    cnt[s]++;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        sum += dfs(v, u, s + 1);
    }
    return sum;
}

int dfs2 (int u) {
    if (vis[u]) {
        return 0;
    }
    int tmp;
    leaf.push_back(u);
    vis[u] = 1;
    S[u] = 1;
    M[u] = 0;
    for (int v : adj[u]) {
        tmp = dfs2(v);
        M[u] = max(M[u], tmp);
        S[u] += tmp;
    }
    return S[u];
}

int cut (int root) {
    leaf.clear();
    int cen, s;
    dfs2(root);
    s = leaf.size();
    for (int u : leaf) {
        if (max(M[u], s - S[u]) <= s / 2) {
            cen = u;
        }
        vis[u] = 0;
    }

    vis[cen] = 1;
    for (int v : adj[cen]) {
        if (!vis[v]) {
            C[cen].push_back(cut(v));
        }
    }
    return cen;
}

int path (int u) {
    int ans = 0, tmp;
    ans += dfs(u, u, 0);
    for (int i = 0; i <= k && cnt[i]; i++) {
        cnt[i] = 0;
    }
    vis[u] = 1;
    for (int v : adj[u]) {
        tmp = dfs(v, u, 1);
        ans -= tmp;
        for (int i = 1; i <= k && cnt[i]; i++) {
            cnt[i] = 0;
        }
    }
    for (int v : C[u]) {
        ans += path(v);
    }
    return ans;
}

int32_t main () {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int c;
    c = cut(1);
    for (bool &v : vis) {
        v = 0;
    }

    cout << path(c) << endl;
    return 0;
}