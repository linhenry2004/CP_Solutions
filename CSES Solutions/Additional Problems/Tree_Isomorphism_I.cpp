#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1000696969;
const int c = 41;
const int maxn = 1e5 + 1;
array<int, maxn> C, S1, S2;
array<vector<int>, maxn> T1, T2;

void build (int n) {
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i] = c * C[i - 1] % mod;
    }
}

int DFS (array<vector<int>, maxn> &T, array<int, maxn> &S, int u, int p) {
    int sum = 0; 
    vector<pair<int, int>> H;
    for (int v : T[u]) {
        if (v == p) {
            continue;
        }
        H.push_back({DFS(T, S, v, u), S[v]});
    }

    sort(H.begin(), H.end());
    for (auto [h, s] : H) {
        sum = (sum + h * C[S[u]]) % mod;
        S[u] += s;
    }
    S[u]++;
    sum = (sum + S[u] * C[S[u]]) % mod;
    return sum;
}

int32_t main () {
    int t, n, a, b;
    build(1e5);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            S1[i] = S2[i] = 0;
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
        if (DFS(T1, S1, 1, 0) == DFS(T2, S2, 1, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}