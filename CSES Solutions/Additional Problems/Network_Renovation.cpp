#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<int> T[maxn];
vector<int> leaf;

void dfs (int u, int p) {
    if (T[u].size() == 1) {
        leaf.push_back(u);
    }
    for (int v : T[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b; 
        T[a].push_back(b);
        T[b].push_back(a);
    }
    dfs(1, 0);
    if (leaf.size() & 1) {
        leaf.push_back(leaf[0]);
    }

    cout << leaf.size() / 2 << endl;
    for (int i = 0; i < leaf.size() / 2; i++) {
        cout << leaf[i] << " " << leaf[i + leaf.size() / 2] << endl;
    }
    return 0;
}