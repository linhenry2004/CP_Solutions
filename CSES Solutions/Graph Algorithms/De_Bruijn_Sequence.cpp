#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v[1<<14];
vector <int> ans;
  
void dfs(int x){
    while (v[x].size()){
        int nxt = v[x].back();
        v[x].pop_back();
        dfs(nxt);
        ans.push_back(nxt&1);
    }
}
  
int main(){
    cin >> n;
    if (n == 1){
        cout << "01" << endl;
        return 0;
    }

    for (int i = 0; i < (1<<(n-1)); i++){
        v[i].push_back(((i<<1))&((1<<(n-1))-1));
        v[i].push_back(((i<<1)+1)&((1<<(n-1))-1));
    }

    dfs(0);
    
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n-1; i++){
        cout << 0;
    }

    for (int i:ans){
        cout << i;
    }
    cout << endl;
    return 0;
}