#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct BIT{
    vector<int> bit;
    void update(int p, int v){
        for(; p < bit.size(); p += p & -p) bit[p] += v;
    }
    int query(int p){
        int sum = 0;
        for(; p > 0; p -= p & -p) sum += bit[p];
        return sum;
    }
};

const int maxn = 2e5 + 1;
int cnt = 1;
int V[maxn], H[maxn], P[maxn], S[maxn], D[maxn], pre[maxn], C[maxn];
vector<int> adj[maxn];
BIT B[maxn];

int dfs (int u, int p, int dep) {
    int tmp, siz = 1, mx = 0;
    D[u] = dep;
    pre[u] = p;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        tmp = dfs(v, u, dep + 1);
        siz += tmp;
        if (tmp > mx) {
            mx = tmp;
            S[u] = v;
        }
    }
    return siz;
}

void hld (int u, int h, int c, int p) {
    H[u] = h;
    C[u] = c;
    P[u] = p;
    if (p == 1) {
        B[c].bit.push_back(0);
    }
    B[c].bit.push_back(0);
    for (int v : adj[u]) {
        if (v == pre[u]) {
            continue;
        }
        if (v == S[u]) {
            hld(v, h, c, p + 1);
        } else {
            hld(v, v, ++cnt, 1);
        }
    }
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 1);
    hld(1, 1, 1, 1);
    
    for (int i = 1; i <= n; i++) {
        B[C[i]].update(P[i], V[i]);
    }
    
    while (q--) {
        int t, s;
        cin >> t >> s;
        if (t == 1) {
            int x;
            cin >> x;
            B[C[s]].update(P[s], x - V[s]);
            V[s] = x;
        } else {
            int ans = 0;
            while (s) {
                ans += B[C[s]].query(P[s]);
                s = pre[H[s]];
            }
            cout << ans << endl;
        }
    }
    return 0;
}