#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 1;
int n, m, a, b;
int in[maxn];
vector <int> v[maxn], ans;
  
void dfs(int x){
    while (v[x].size()){
        int nxt = v[x].back();
        v[x].pop_back();
        dfs(nxt);
    }
    ans.push_back(x);
}
  
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }

    in[1]++;
    in[n]--;
    for (int i = 1; i <= n; i++){
        if (in[i] != v[i].size()){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    dfs(1);

    if (ans.size() != m+1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for (int i:ans){
        cout << i << " ";
    }
}