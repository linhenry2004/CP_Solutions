#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

#define int long long int

int n, m;
vector<set<int>> g;
vector<bool> vis;
stack<int> stk;
vector<bool> flag;

bool dfs (int u) {
    vis[u] = true;
    stk.push(u);
    flag[u] = true;

    for (auto v : g[u]) {
        if(!vis[v]) {
            if (dfs(v)) {
                return true;
            }
        }

        if (flag[v]) {
            stk.push(v);
            return true;
        }
    }
    stk.pop();
    flag[u] = false;
    return false;
}


int32_t main () {
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    flag.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                break;
            }
        }
    }

    if (stk.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    int temp = stk.top();
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
        if (ans.back() == temp && ans.size() != 1) {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}