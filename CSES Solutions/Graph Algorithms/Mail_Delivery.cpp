#include <bits/stdc++.h>
using namespace std;
  
const int maxn = 1e5 + 1;
int n, m, a, b;
set <int> st[maxn];
vector <int> ans;

void dfs(int x){
    while (st[x].size()){
        int now = *st[x].begin();
        st[now].erase(x);
        st[x].erase(now);
        dfs(now);
    }
    ans.push_back(x);
}
  
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        st[a].insert(b);
        st[b].insert(a);
    }
    for (int i = 1; i <= n; i++){
        if (st[i].size() % 2){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    dfs(1);
    if (ans.size() != m+1) cout << "IMPOSSIBLE" << endl;
    else{
        reverse(ans.begin(), ans.end());
        for (int i:ans){
            cout << i << " ";
        }
        cout << "endl";
    }
}