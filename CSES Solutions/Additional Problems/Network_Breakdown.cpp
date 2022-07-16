#include <bits/stdc++.h>
using namespace std;

int com;
const int maxn = 1e5 + 1;
int DSU[maxn];
vector<int> ans;
vector<pair<int, int>> B;
set<pair<int, int>> E;

int find (int u) {
    if (DSU[u] == u) {
        return u;
    }
    return DSU[u] = find(DSU[u]);
}

void onion (int u, int v) {
    int U = find(u), V = find(v);
    if (U == V) {
        return;
    }
    DSU[V] = U;
    com--;
}

void run (int k) {
    for (auto[a, b] : E) {
        onion(a, b);
    }
    ans.push_back(com);
    for (auto [a, b] : B) {
        onion(a, b);
        ans.push_back(com);
    }
    ans.pop_back();
}

int main () {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    com = n;
    for (int i = 1; i <= n; i++) {
        DSU[i] = i;
    }
    while (m--) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        E.insert({a, b});
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        E.erase({a, b});
        B.push_back({a, b});
    }
    
    reverse(B.begin(), B.end());
    run(k);
    reverse(ans.begin(), ans.end());
    
    for (int c : ans) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}