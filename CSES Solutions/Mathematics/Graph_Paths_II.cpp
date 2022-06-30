#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define matrix array<array<int, 101>, 101>

const int mod = 1e9 + 7;
matrix G, W;

int min (int a, int b) {
    if (a < 0) {
        return b;
    }
    if (b < 0) {
        return a;
    }
    return a < b ? a : b;
}

matrix mul (matrix A, matrix B, int n) {
    matrix C; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = -1;
            for (int k = 1; k <= n; k++) {
                if (A[i][k] < 0 || B[k][j] < 0) {
                    continue;
                }
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

int walk (int n, int k) {
    k--;
    for (int i = 1; i <= k; i <<= 1) {
        if (i & k) {
            W = mul(G, W, n);
        }
        G = mul(G, G, n);
    }
    return W[n][1];
}

int32_t main () {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = -1;
            W[i][j] = -1;
        }
    }

    while (m--) {
        int a, b, c; 
        cin >> a >> b >> c; 
        G[b][a] = min(G[b][a], c);
        W[b][a] = min(W[b][a], c);
    }
    cout << walk(n, k) << endl;
    return 0;
}