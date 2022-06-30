#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define matrix array<array<int, 101>, 101>

const int mod = 1e9 + 7;
matrix G;

matrix mul (matrix A, matrix B, int n) {
    matrix C; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                C[i][j] += (A[i][k] * B[k][j]) % mod;
            }
            C[i][j] %= mod;
        }
    }
    return C;
}

int walk (int n, int k) {
    matrix W;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            W[i][j] = 0;
        }
        W[i][i] = 1;
    }

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
    while (m--) {
        int a, b; 
        cin >> a >> b; 
        G[b][a]++;
    }

    cout << walk(n, k) << endl;
    return 0;
}