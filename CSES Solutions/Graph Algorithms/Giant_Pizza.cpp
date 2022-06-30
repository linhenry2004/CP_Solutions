#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int n, m, a, b;
int dfn[maxn], stk[maxn], low[maxn], pa[maxn], opp[maxn], in[maxn], pick[maxn];
int scc, idx;
char c[2];
vector <int> v[maxn];
vector <int> v2[maxn];
stack <int> st;
  
void tarjan(int x){
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

int tr(int x){
    if (x <= m) return x + m;
    else return x - m;
}

bool check(){
    for (int i = 1; i <= m; i++){
        if (pa[i] == pa[i+m]) return 0;
        else{
            opp[pa[i]] = pa[i+m];
            opp[pa[i+m]] = pa[i];
        }
    }
    return 1;
}

void build(){
    for (int i = 1; i <= m * 2; i++){
        for (int j:v[i]){
            if (pa[i] != pa[j]){
                v2[pa[j]].push_back(pa[i]);
                in[pa[i]]++;
            }
        }
    }
}

void topo(){
    queue <int> q;
    for (int i = 1; i <= scc; i++){
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int now = q.front();
        q.pop();
        if (!pick[now]){
            pick[now] = 1;
            pick[opp[now]] = 2;
        }
        for (auto i:v2[now]){
            in[i]--;
            if (!in[i]) q.push(i);
        }
    }
    for (int i = 1; i <= m; i++){
        if (pick[pa[i]] == 1) cout << "+ ";
        else cout << "- ";
    }
}
  
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> c[0] >> a >> c[1] >> b;
        if (c[0] == '-') a += m;
        if (c[1] == '-') b += m;
        v[tr(a)].push_back(b);
        v[tr(b)].push_back(a);
    }

    for (int i = 1; i <= m*2; i++){
        if (!dfn[i]) tarjan(i);
    }

    if (check()){
        build();
        topo();
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}