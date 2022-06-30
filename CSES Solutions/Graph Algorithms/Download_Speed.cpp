#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 500;
const int maxm = 1e3;
int n, m;
int d[maxn], p[maxn];
vector<int> adj[maxn];

struct edge {
    int u, v, rev, cap;
} e[2 * maxm];

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c; 
        a--;
        b--;
        e[2 * i] = {a, b, 2 * i + 1, c};
        e[2 * i + 1] = {b, a, 2 * i, 0};
        adj[a].push_back(2 * i);
        adj[b].push_back(2 * i + 1);
    }

    ll f = 0;
    while (true) {
        memset(d, 0x3F, sizeof(d));
        d[0] = 0;
        queue<int> q;
        q.push(0);
        
        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int i : adj[u]) {
                if (e[i].cap && d[e[i].v] > 1e9) {
                    d[e[i].v] = d[u] + 1;
                    p[e[i].v] = i;
                    q.push(e[i].v);
                }
            }
        }
        if (d[n - 1] > 1e9) {
            break;
        }
        int mf = 1e9, u = n - 1;
        while (u) {
            mf = min(mf, e[p[u]].cap);
            u = e[p[u]].u;
        }
        
        f += mf;
        u = n - 1;
        while (u) {
            e[p[u]].cap -= mf;
            e[e[p[u]].rev].cap += mf;
            u = e[p[u]].u;
        }
    }
    cout << f << endl;
    return 0;
}