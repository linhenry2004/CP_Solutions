#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, f;
};

const int inf = 1000696969;
int cnt = 0;
int lvl[104], P[104];
edge E[10004];
char ans[54][54];
vector<int> G[104];

void add (int u, int v, int f) {
    E[cnt] = {u, v, f};
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

int main () {
    int n, w, in = 0, out = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        in += w;
        add(0, i, w);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w;
        out += w;
        add(50 + i, 101, w);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 51; j <= 50 + n; j++){
            add(i, j, 1);
        }
    }
    if (flow(0, 101) != in || in != out) {
        cout << "-1" << endl;
        return 0;
    }
    for (int u = 1; u <= n; u++) {
        for (int i : G[u]) {
            auto [o, v, f] = E[i];
            if(v < 50) {
                continue;
            }
            if(f) ans[u][v - 50] = '.';
            else ans[u][v - 50] = 'X';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}