#include <bits/stdc++.h>
using namespace std;

struct ver {
    int u, d;
};

struct cmp {
    bool operator () (ver a, ver b) {
        return a.d < b.d;
    }
};

const int maxn = 1e5 + 1;
int deg[maxn];
vector<int> G[maxn];

bool run (int n) {
    vector<ver> tmp;
    priority_queue<ver, vector<ver>, cmp> Q;
    for (int i = 1; i <= n; i++) {
        Q.push({i, deg[i]});
    }
    while (Q.top().d > 0) {
        auto [u, d] = Q.top();
        Q.pop();
        while (d--) {
            auto [v, t] = Q.top();
            Q.pop();
            if (!t) {
                return 0;
            }
            tmp.push_back({v, t - 1});
            G[u].push_back(v);
        }
        for (ver v : tmp) {
            Q.push(v);
        }
        tmp.clear();
        Q.push({u, 0});
    }
    return 1;
}

int main () {
    int n, e = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        e += deg[i];
    }
    if (!run(n)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << e / 2 << endl;
    for (int i = 1; i <= n; i++) {
        for (int v : G[i]) {
            cout << i << " " << v << endl;
        }
    }
    return 0;
}