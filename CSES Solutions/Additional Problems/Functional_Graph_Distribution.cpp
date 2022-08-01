#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod  = 1e9 + 7;
const int maxn = 5001;
int N[maxn];
int C[maxn][maxn], S[maxn][maxn];

void build (int n) {
    N[0] = S[0][0] = C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        N[i] = n * N[i - 1] % mod;
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            S[i][j] = ((i - 1) * S[i - 1][j] + S[i - 1][j - 1]) % mod;
        }
    }
}

int32_t main () {
    int n, sum = 0;
    cin >> n;
    build(n);
    for (int i = 1; i <= n; i++, sum = 0) {
        for (int j = 1; j < n; j++) {
            sum = (sum + ((C[n][j] * S[j][i]) % mod) * ((j * N[n - j - 1]) % mod)) % mod;
        }
        sum = (sum + S[n][i]) % mod;
        cout << sum << endl;
    }
    return 0;
}