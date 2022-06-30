#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct seg {
    int val;
    seg *lc, *rc;

    seg () {
        val = 0; lc = rc = nullptr;
    }

    void pull () {
        val = max(lc? lc->val : 0, rc? rc->val : 0);
    }

    void update (int x, int v, int l, int r) {
        if (l == r) {
            val = v;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            if(!lc) lc = new seg;
            lc->update(x, v, l, mid);
        } else {
            if(!rc) rc = new seg;
            rc->update(x, v, mid + 1, r);
        }
        pull();
    }

    int query (int ql, int qr, int l, int r) {
        if (ql > r || qr < l) {
            return 0;
        }
        if (ql <= l && qr >= r) {
            return val;
        }
        int mid = (l + r) / 2;
        return max(lc? lc->query(ql, qr, l, mid) : 0, rc? rc->query(ql, qr, mid + 1 ,r) : 0);
    }
};

const int maxn = 2e5 + 1;
int cnt = 1, n;
int P[maxn], C[maxn], D[maxn], pre[maxn], H[maxn], M[maxn], V[maxn], Z[maxn];
vector<int> adj[maxn];
seg* S[maxn];

int dfs (int u, int p, int dep) {
    int s = 1, tmp, mx = 0;
    D[u] = dep;
    pre[u] = p;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        tmp = dfs(v, u, dep + 1);
        s += tmp;
        if (tmp > mx) {
            mx = tmp;
            M[u] = v;
        }
    }
    return s;
}

void hld (int u, int h, int c, int p) {
    H[u] = h;
    C[u] = c;
    P[u] = p;
    Z[c] = p;
    for (int v : adj[u]) {
        if (v == pre[u]) {
            continue;
        }
        if (v == M[u]) {
            hld(v, h, c, p + 1);
        } else {
            hld(v, v, ++cnt, 1);
        }
    }
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
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
        if (!S[C[i]]) {
            S[C[i]] = new seg;
        }
        S[C[i]]->update(P[i], V[i], 1, Z[C[i]]);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            S[C[a]]->update(P[a], b, 1, Z[C[a]]);
        } else {
            int ans = 0;
            while (H[a] != H[b]) {
                if (D[H[a]] < D[H[b]]) swap(a, b);
                ans = max(ans, S[C[a]]->query(1, P[a], 1, Z[C[a]]));
                a = pre[H[a]];
            }
            if (D[a] < D[b]) swap(a, b);
            cout << max(ans, S[C[a]]->query(P[b], P[a], 1, Z[C[a]])) << " ";
        }
    }
    cout << endl;
    return 0;
}