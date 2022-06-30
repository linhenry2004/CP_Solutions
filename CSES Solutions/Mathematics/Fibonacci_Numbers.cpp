#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define matrix array<array<int, 2>, 2>

const int mod = 1e9 + 7;
matrix K;

matrix mul (matrix A, matrix B) {
    matrix C; 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            C[i][j] = 0;
            for(int k = 0; k < 2; k++){
                C[i][j] += (A[i][k] * B[k][j]) % mod;
            }
            C[i][j] %= mod;
        }
    }
    return C;
}

int fib (int n) {
    matrix F;
    K[0][0] = 1, K[0][1] = 1, K[1][0] = 1, K[1][1] = 0;
    F[0][0] = 1, F[0][1] = 0, F[1][0] = 0, F[1][1] = 1;
    for (int i = 1; i <= n; i <<= 1) {
        if (i & n) {
            F = mul(K, F);
        }
        K = mul(K, K);
    }
    return F[0][1];
}

int32_t main () {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}