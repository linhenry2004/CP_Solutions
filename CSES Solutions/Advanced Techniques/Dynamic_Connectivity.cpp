#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define mid ((l + r) >> 1)

struct edge {
    int u, v, l, r;
};

const int maxn = 1e5 + 1;
const int maxm = 1e5 + 1;
int n, com;
int DSU[maxn];
vector<pair<int, int>> tmp;
stack<vector<pair<int, int>>> chg;

int ehash (int u, int v) {
    return u * maxm + v;
}

pair<int, int> dehash (int x) {
    return {x / maxm, x % maxn};
}

int find (int u) {
    tmp.push_back({u, DSU[u]});
    if (DSU[u] == u) {
        chg.push(tmp);
        tmp.clear();
        return u;
    }
    return DSU[u] = find(DSU[u]);
}

void onion (int u, int v) {
    int U = find(u), V = find(v);
    if (U == V) {
        return;
    }
    DSU[V] = U;
    com--;
}

void roll () {
    tmp = chg.top();
    chg.pop();
    for (auto [u, d] : tmp) {
        DSU[u] = d;
    }
    tmp.clear();
}

void run (int l, int r, vector<edge> &E) {
    int c = com;
    vector<edge> D;
    for (edge e: E) {
        if (e.l > r || e.r < l) {
            continue;
        }
        if (e.l <= l && e.r >= r) {
            onion(e.u, e.v);
        } else {
            D.push_back(e);
        }
    }

    if (l == r) {
        cout << com << " ";
    } else {
        run(l, mid, D);
        run(mid + 1, r, D);
    }

    for (edge e : E) {
        if (e.l <= l && e.r >= r) {
            roll(), roll();
        }
    }
    com = c;
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    int p = 0;
    cin >> n >> m >> q;
    vector<edge> E;
    map<int, int> M;
    com = n;
    for (int i = 1; i <= n; i++) {
        DSU[i] = i;
    }
    while (m--) {
        int a, b; 
        cin >> a >> b; 
        if (a > b) {
            swap(a, b);
        }
        M[ehash(a, b)] = 0;
    }
    while (q--) {
        int t, a, b; 
        cin >> t >> a >> b; 
        if (a > b) {
            swap(a, b);
        }
        p++;
        if (t == 1) {
            M[ehash(a, b)] = p;
        } else {
            E.push_back({a, b, M[ehash(a, b)], p - 1});
            M.erase(ehash(a, b));
        }
    }
    for (auto [e, s] : M) {
        auto [u, v] = dehash(e);
        E.push_back({u, v, s, p});
    }
    run(0, p, E);
    cout << endl;
    return 0;
}