#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define vec pair<int, int>
#define x first
#define y second

const int maxn = 2e5 + 1;
vector<vec> V(maxn);

int sq (int x) {
    return ceil(sqrt(x));
}

int dis (vec a, vec b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int mindis (int n) {
    int p = 0, d = 8e18;
    set<vec> S;
    for (int i = 0; i < n; i++) {
        while (V[p].x <= V[i].x - d) {
            S.erase({V[p].y, V[p].x});
            p++;
        }
        for (auto it = S.upper_bound({V[i].y - sq(d), V[i].x}); it->x < V[i].y + sq(d); it++) {
            if(it == S.end()) break;
            d = min(d, dis(*it, {V[i].y, V[i].x}));
        }
        S.insert({V[i].y, V[i].x});
    }
    return d;
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V[i] = {x, y};
    }
    sort(V.begin(), V.begin() + n);
    cout << mindis(n) << endl;
    return 0;
}