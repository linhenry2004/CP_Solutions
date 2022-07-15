#include <bits/stdc++.h>
using namespace std;

int p = 0;
const int maxn = 1e5 + 1;
int DSU[maxn], S[maxn], C[maxn];
int dp[2][maxn];

int find (int u) {
    if (DSU[u] == u) {
        return u;
    }
    return DSU[u] = find(DSU[u]);
}

void onion (int u, int v) {
    int U = find(u), V = find(v);
    if (U == V) {
        return;
    }
    if (S[u] < S[V]) {
        swap(U, V);
    }
    DSU[V] = U;
    S[U] += S[V];
}

void DP (int n) {
    int sum;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!C[i]) {
            continue;
        }
        p ^= 1;
        for (int j = 0; j < i; j++) {
            sum = 0;
            for (int k = j; k <= n; k += i) {
                if (k - j > i * C[i]) {
                    sum -= dp[p ^ 1][k - i * (C[i] + 1)];
                }
                sum += dp[p ^ 1][k];
                dp[p][k] = sum ? 1 : 0;
            }
        }
    }
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        DSU[i] = i;
        S[i] = 1;
    }
    while (m--) {
        cin >> a >> b;
        onion(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (DSU[i] != i) {
            continue;
        }
        C[S[i]]++;
    }
    DP(n);
    for (int i = 1; i <= n; i++) {
        cout << dp[p][i];
    }
    cout << endl;
    return 0;
}