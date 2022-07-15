#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, f;
};

int inf = 1000696969, cnt = 0;
bitset<204> vis;
int lvl[204], P[204];
edge E[84004];
vector<int> G[204];

void add (int u, int v, int f) {
    E[cnt] = {u, v, 1};
    G[u].push_back(cnt++);
    E[cnt] = {v, u, 0};
    G[v].push_back(cnt++);
}

bool BFS (int s, int t) {
    int u;
    queue<int> Q;
    Q.push(s);
    lvl[s] = 1;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i : G[u]) {
            auto [o, v, f] = E[i];
            if (!f || lvl[v]) {
                continue;
            }
            lvl[v] = lvl[u] + 1;
            Q.push(v);
        }
    }
    return lvl[t];
}

int DFS (int u, int t, int f) {
    if (u == t || !f) {
        return f;
    }
    int wat = 0, tmp;
    for (int &i = P[u]; i < G[u].size(); i++) {
        auto &[eu, ev, ef] = E[G[u][i]];
        auto &[bu, bv, bf] = E[G[u][i] ^ 1];
        if(lvl[ev] != lvl[u] + 1) {
            continue;
        }
        tmp = DFS(ev, t, min(f, ef));
        ef -= tmp, bf += tmp;
        f -= tmp, wat += tmp;
    }
    return wat;
}

int flow (int s, int t) {
    int tmp, ans = 0;
    while (true) {
        for (int &l : lvl) {
            l = 0;
        }
        if (!BFS(s, t)) {
            break;
        }
        while (true) {
            for (int &p : P) {
                p = 0;
            }
            if (tmp = DFS(s, t, inf)) {
                ans += tmp;
            } else {
                break;
            }
        }
    }
    return ans;
}

void run (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    for (int i : G[u]) {
        auto [o, v, f] = E[i];
        if(!f) {
            continue;
        }
        run(v);
    }
}

int main () {
    int n;
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        add(0, i, 1);
        add(100 + i, 201, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '.') {
                continue;
            }
            add(i, 100 + j, 1);
        }
    }
    cout << flow(0, 201) << endl;
    run(0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "1 " << i << endl;
        }
        if (vis[100 + i]) {
            cout << "2 " << i << endl;
        }
    }
    return 0;
}