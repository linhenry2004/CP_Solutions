#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 1;
array<int, maxn> in;
array<bitset<maxn>, maxn> dp;
array<vector<int>, maxn> G;
stack<int> ord;

void topo (int n) {
    int u;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();
        ord.push(u);
        for (int v : G[u]) {
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }

    while (!ord.empty()) {
        u = ord.top();
        ord.pop();
        dp[u][u] = 1;
        for (int v : G[u]) {
            dp[u] |= dp[v];
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b; 
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }

    topo(n);

    for (int i = 1; i <= n; i++) {
        cout << dp[i].count() << " ";
    }
    cout << endl;
    return 0;
}