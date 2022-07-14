#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1000696969;
const int k = 41;
const int maxn = 1e5 + 1;
int n;
array<int, maxn> H, S1, S2;
array<vector<int>, maxn> T1, T2;
vector<int> C1, C2;

void build () {
    H[0] = 1;
    for (int i = 1; i < maxn; i++) {
        H[i] = k * H[i - 1] % mod;
    }
}

int DFS (array<vector<int>, maxn> &T, vector<int> &C, int u, int p) {
    int tmp, s = 1;
    bool cen = 1;
    for (int v : T[u]) {
        if (v == p) {
            continue;
        }
        tmp = DFS(T, C, v, u);
        if (2 * tmp > n) {
            cen = 0;
        }
        s += tmp;
    }
    if (2 * s < n) {
        cen = 0;
    }
    if (cen) {
        C.push_back(u);
    }
    return s;
}

int HAS (array<vector<int>, maxn> &T, array<int, maxn> &S, int u, int p) {
    int sum = 0;
    S[u] = 0;
    vector<pair<int, int>> has;
    for (int v : T[u]) {
        if (v == p) {
            continue;
        }
        has.push_back({HAS(T, S, v, u), S[v]});
    }
    sort(has.begin(), has.end());
    for (auto [h, s] : has) {
        sum = (sum + H[S[u]] * h) % mod;
        S[u] += s;
    }
    sum = (sum + H[S[u]] * (S[u] + 1)) % mod;
    S[u]++;
    return sum;
}

int32_t main () {
    int t, a, b;
    bool ok;
    cin >> t;
    build();
    while (t--) {
        cin >> n;
        ok = 0;
        C1.clear(), C2.clear();
        for (int i = 1; i <= n; i++) {
            T1[i].clear();
            T2[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            T1[a].push_back(b);
            T1[b].push_back(a);
        }
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            T2[a].push_back(b);
            T2[b].push_back(a);
        }
        DFS(T1, C1, 1, 0);
        DFS(T2, C2, 1, 0);
        for (int c1 : C1) {
            for (int c2 : C2) {
                if (HAS(T1, S1, c1, 0) == HAS(T2, S2, c2, 0)) {
                    ok = 1;
                }
            }
        }
        if (C1.size() != C2.size()) {
            ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}