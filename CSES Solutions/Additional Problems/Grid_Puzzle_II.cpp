#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, f, c;
};

const int inf = 1000696969;
int cnt = 0;
bool in[104];
int dis[104], B[104];
edge E[10004];
char ans[104][104];
vector<int> G[104];

void add (int u, int v, int f, int c) {
    E[cnt] = {u, v, f, c};
    G[u].push_back(cnt++);
    E[cnt] = {v, u, 0, -c};
    G[v].push_back(cnt++);
}

int SPFA (int s, int t) {
    int u;
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        in[u] = 0;
        for (int i : G[u]) {
            auto &[o, v, f, c] = E[i];
            if (!f || dis[u] + c >= dis[v]) {
                continue;
            }
            dis[v] = dis[u] + c;
            B[v] = i;
            if (in[v]) {
                continue;
            }
            in[v] = 1;
            Q.push(v);
        }
    }
    return dis[t] == inf ? 0 : 1;
}

void back (int u) {
    if (!u) {
        return;
    }
    auto &[eu, ev, ef, ec] = E[B[u]];
    auto &[bu, bv, bf, bc] = E[B[u] ^ 1];
    ef--, bf++;
    back(eu);
}

int flow (int s, int t) {
    int tmp, ans = 0;
    while (true) {
        for (int &d : dis) {
            d = inf;
        }
        for (int &b : B) {
            b = 0;
        }
        for (bool &i : in) {
            i = 0;
        }
        if (tmp = SPFA(s, t)) {
            ans += tmp;
        } else {
            break;
        }
        back(t);
    }
    return ans;
}

int main () {
    int n, w, sum = 0, out = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        add(0, i, w, 0);
    }
    for (int i = 51; i <= 50 + n; i++) {
        cin >> w;
        out += w;
        add(i, 101, w, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 51; j <= 50  + n; j++) {
            cin >> w;
            add(i, j, 1, -w);
        }
    }
    if (flow(0, 101) != out) {
        cout << "-1" << endl;
        return 0;
    }
    for (int u = 1; u <= n; u++) {
        for (int i : G[u]) {
            auto [o, v, f, c] = E[i];
            if (v < 50) {
                continue;
            }
            if (f) {
                ans[u][v - 50] = '.';
            } else {
                ans[u][v - 50] = 'X';
                sum -= c;
            }
        }
    }
    
    cout << sum << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}