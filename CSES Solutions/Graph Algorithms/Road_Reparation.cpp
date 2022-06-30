#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int maxn = 1e5;
const int maxm = 2e5;
int n, m;
int p[maxn];
array<int, 3> e[maxm];
ll ans;
 
int find (int x) {
    return x ^ p[x] ? p[x] = find(p[x]) : x;
}
 
bool join (int x, int y) {
    if ((x = find(x)) == (y = find(y))) {
        return false;
    }
    p[x] = y;
    return true;
}
 
int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        e[i][1]--;
        e[i][2]--;
    }
 
    sort(e, e + m);
    iota(p, p + n, 0);
    int a1 = 0;
    ll a2 = 0;
 
    for (int i = 0; i < m; i++) {
        if(join(e[i][1], e[i][2])) {
            a1++;
            a2 += e[i][0];
        }
    }
 
    if (a1 < n - 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << a2 << endl;
    }
}