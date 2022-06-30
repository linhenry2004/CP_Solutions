#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 1;
const int maxm = 2e5 + 1;
int n, m, a, b;
int dfn[maxn], stk[maxn], low[maxn], pa[maxn], in[maxn], k[maxn];
int scc, idx;
ll coins[maxn], dp[maxn], ans;
vector <int> v[maxm];
vector <int> v2[maxm];
stack <int> st;
  
void tarjan (int x) {
    idx++;
    dfn[x] = low[x] = idx;
    st.push(x);
    stk[x] = 1;
    for (auto i:v[x]){
        if (!dfn[i]){
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if (stk[i]){
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (dfn[x] == low[x]){
        scc++;
        pa[x] = scc;
        int nxt = -1;
        while (nxt != x){
            nxt = st.top();
            st.pop();
            pa[nxt] = scc;
            stk[nxt] = 0;
        }
    }
}

void build () {
    for (int i = 1; i <= n; i++){
        coins[pa[i]] += k[i];
        for (int j:v[i]){
            if (pa[i] != pa[j]){
                v2[pa[i]].push_back(pa[j]);
                in[pa[j]]++;
            }
        }
    }
}

void topo () {
    queue <int> q;
    for (int i = 1; i <= scc; i++){
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int now = q.front();
        q.pop();
        dp[now] += coins[now];
        ans = max(ans, dp[now]);
        for (auto i:v2[now]){
            in[i]--;
            dp[i] = max(dp[i], dp[now]);
            if (!in[i]) q.push(i);
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> k[i];
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        if (!dfn[i]) tarjan(i);
    }
    build();
    topo();
    cout << ans << endl;
}