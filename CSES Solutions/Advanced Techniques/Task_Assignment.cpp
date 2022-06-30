#include <bits/stdc++.h>
using namespace std;

struct pipe {
    int u, v, f, c;
};

const int maxn = 412;
const int maxm = 81204;
int cnt = 0;
bitset<maxn> in;
int cost[maxn], pre[maxn];
vector<int> G[maxn];
pipe E[maxm];

void add (int u, int v, int f, int c) {
    G[u].push_back(cnt);
    E[cnt++] = {u, v, f, c};
    G[v].push_back(cnt);
    E[cnt++] = {v, u, 0, -c};
}

void run (int u) {
    if (!u) {
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
        for (int i = 0; i <= n; i++) {
            cost[i] = 1e9;
        }
        SPFA(0);
        run(n);
        ans += cost[n];
    }
    return ans;
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        add(0, i, 1, 0);
        add(200 + i, 404, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            add(i, 200 + j, 1, c);
        }
    }

    cout << flow(404, n) << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        for (int j : G[i]) {
            if (!E[j].f) {
                cout << E[j].v - 200 << endl;
            }
        }
    }
    return 0;
}