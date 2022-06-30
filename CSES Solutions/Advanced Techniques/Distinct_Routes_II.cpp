#include <bits/stdc++.h>
using namespace std;

struct pipe {
    int u, v, f, c;
};

const int maxn = 501;
int cnt = 0;
bitset<maxn> vis, in;
int cost[maxn], pre[maxn];
vector<int> G[maxn];
pipe E[4 * maxn];
vector<int> R;

void add (int u, int v, int f, int c) {
    G[u].push_back(cnt);
    E[cnt++] = {u, v, f, c};
    G[v].push_back(cnt);
    E[cnt++] = {v, u, 0, -c};
}

void run (int u) {
    if (u == 1) {
        return;
    }
    pipe &e = E[pre[u]], &b = E[pre[u] ^ 1];
    b.f--;
    e.f++;
    run(e.v);
}

void SPFA (int s) {
    int u, v;
    queue<int> q;
    cost[s] = 0;
    q.push(s);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = 1;
        in[u] = 0;
        for (int i : G[u]) {
            if (!E[i].f) {
                continue;
            }
            v = E[i].v;
            if (cost[u] + E[i].c < cost[v]) {
                cost[v] = cost[u] + E[i].c;
                pre[v] = i ^ 1;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int flow (int n, int k) {
    int ans = 0;
    while (k--) {
        for (int i = 1; i <= n; i++) {
            cost[i] = 1e9;
            vis[i] = 0;
        }
        SPFA(1);
        if (!vis[n]) {
            return -1;
        }
        run(n);
        ans += cost[n];
    }
    return ans;
}

void dfs (int u) {
    R.push_back(u);
    for (int i : G[u]) {
        if (i % 2 == 0 && !E[i].f) {
            dfs(E[i].v);
            E[i].f++;
            return;
        }
    }
}

int32_t main () {
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int a, b; 
        cin >> a >> b; 
        add(a, b, 1, 1);
    }

    cout << flow(n, k) << endl;
    while (k--) {
        R.clear();
        dfs(1);
        cout << R.size() << endl;
        for (int u : R) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}