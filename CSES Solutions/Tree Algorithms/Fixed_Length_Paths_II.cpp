#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 + 1;
int n, k1, k2;
ll ans;
int root, rootpre, u[maxn], sz[maxn], cnt[maxn], dis[maxn];
vector <int> v[maxn], used;
  
void update (int x, int d) {
    x++;
    while (x <= n) {
        if (cnt[x] == 0) used.push_back(x);
        cnt[x] += d;
        x += x & (-x);
    }
}
int query (int x) {
    x++;
    if (x <= 0) return 0;
    if (x > n) x = n;
    int ret = 0;
    while (x) {
        ret += cnt[x];
        x -= x & (-x);
    }
    return ret;
}
  
void find_root (int x, int pre, int siz) {
    int mx = 0;
    sz[x] = 0;
    for (int i : v[x]) {
        if (u[i]) continue;
        if (i == pre) continue;
        find_root(i, x, siz);
        sz[x] += sz[i];
        mx = max(mx, sz[i]);
    }
    sz[x] += 1;
    mx = max(mx, siz - sz[x]);
    if (mx <= siz / 2) {
        root = x;
        rootpre = pre;
    }
}
  
void dfs (int x, int pre, int d) {
    used.push_back(x);
    ans += d * (query(k2-dis[x]) - query(k1-dis[x]-1));
    update(dis[x], 1);
    for (int i:v[x]) {
        if (u[i]) continue;
        if (i == pre) continue;
        dis[i] = dis[x]+1;
        dfs(i, x, d);
    }
}
  
void solve (int x, int siz) {
    if (siz < k1) return;
    find_root(x, -1, siz);
    if (rootpre != -1) sz[rootpre] = siz-sz[root];
    dis[root] = 0;
    u[root] = 1;
    dfs(root, -1, 1);
    while (used.size()) {
        cnt[used.back()] = 0;
        dis[used.back()] = 0;
        used.pop_back();
    }
    for (int i:v[root]) {
        if (u[i]) continue;
        dis[i] = 1;
        dfs(i, root, -1);
        while (used.size()) {
            cnt[used.back()] = 0;
            dis[used.back()] = 0;
            used.pop_back();
        }
    }
    for (int i:v[root]) {
        if (u[i]) continue;
        solve(i, sz[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
    cin >> n >> k1 >> k2;
    for (int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1, n);
    cout << ans << endl;
}