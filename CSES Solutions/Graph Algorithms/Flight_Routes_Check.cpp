#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m;
vector<int> adj[maxn], adj2[maxn], st, co;
bool vis[maxn];
int p[maxn];

void dfs (int u) {
    vis[u] = true;
    for (int v : adj2[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    st.push_back(u);
}

void dfs2(int u, int rt) {
    vis[u] = 0;
    p[u] = rt;
    for (int v : adj[u]) {
        if (vis[v]) {
            dfs2(v, rt);
        }
    }
    co.push_back(u);
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        a--;
        b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        } 
    }

    vector<int> ans;
    for (int i = n - 1; ~i; i--) {
        if (vis[st[i]]) {
            dfs2(st[i], st[i]);
            if (co.size() == n) {
                cout << "YES" << endl;
                return 0;
            } else {
                ans.push_back(st[i]);
            }
            co.clear();
        }
    }
    cout << "NO" << endl;
    cout << ans[0] + 1 << " " << ans[1] + 1 << endl;
}