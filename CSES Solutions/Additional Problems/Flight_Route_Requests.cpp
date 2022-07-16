#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
bitset<maxn> vis;
int in[maxn];
vector<pair<int, int>> G[maxn];
vector<int> V;

void DFS (int u) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    V.push_back(u);
    
}