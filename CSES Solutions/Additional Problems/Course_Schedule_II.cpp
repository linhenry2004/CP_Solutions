#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int in[maxn];
vector<int> G[maxn];
vector<int> ord;

void topu (int n) {
    int u;
    priority_queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        u = Q.top();
        Q.pop();
        ord.push_back(u);
        for (int v : G[u]) {
            if (!--in[v]) {
                Q.push(v);
            }
        }
    }
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        in[a]++;
        G[b].push_back(a);
    }
    topu(n);
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}