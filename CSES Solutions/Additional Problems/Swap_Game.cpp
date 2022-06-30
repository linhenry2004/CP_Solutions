#include <bits/stdc++.h>
using namespace std;

struct pos {
    int u, s;
};

int T = 0;
int P[10];
bitset<387420489> vis;

int swap (int u, int i, int j) {
    int a = (u / P[i]) % 9;
    int b = (u / P[j]) % 9;
    u += (b - a) * P[i];
    u += (a - b) * P[j];
    return u;
}

int bfs (int S) {
    int v;
    queue<pos> q;
    q.push({S, 0});
    vis[S] = 1;
    while (true) {
        auto [u, s] = q.front();
        q.pop();
        if (u == T) {
            return s;
        }
        for (int i = 0; i < 9; i++) {
            if (i % 3 < 2) {
                v = swap(u, i, i + 1);
                if (!vis[v]) {
                    q.push({v, s + 1});
                    vis[v] = 1;
                }
            }
            if (i + 3 < 9) {
                v = swap(u, i, i + 3);
                if (!vis[v]) {
                    q.push({v, s + 1});
                    vis[v] = 1;
                }
            }
        }
    }
}

int32_t main () {
    int x, G = 0;
    P[0] = 1;
    for (int i = 1; i < 10; i++) {
        P[i] = 9 * P[i - 1];
    }
    for (int i = 0; i < 9; i++) {
        T += i * P[i];
    }
    for (int i = 0; i < 9; i++) {
        cin >> x;
        G += (x - 1) * P[i];
    }
    cout << bfs(G) << endl;
    return 0;
}