#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define cmp complex<double>
#define r real
#define i imag

const int N = 1 << 19;
const double pi = 3.141592653589793238462643383279502884;
array<cmp, N> A, B, C, X;

cmp ei (double d) {
    return {cos(d), sin(d)};
}

void FFT (array<cmp, N> &F) {
    int n;
    cmp x;
    for (int i = 0, j = 0; i < N; i++) {
        if (i > j) {
            swap(F[i], F[j]);
        }
        for (int k = N >> 1; (j ^= k) < k; k >>= 1);
    }

    for (int k = 2; k <= N; k <<= 1) {
        n = k >> 1;
        for (int j = 0; j < N; j += k) {
            for (int i = j; i < j + n; i++) {
                x = X[(i - j) * N / k] * F[i + n];
                F[i + n] = F[i] - x;
                F[i] += x;
            }
        }
    }
}

int rnd (double x) {
    double z = (int)x;
    if (x - z >= 0.5) {
        return (int)z + 1;
    } else {
        return (int)z;
    }
}

int32_t main () {
    int n;
    string S;
    cin >> S;
    n = S.size();

    for (int i = 0; i < n; i++) {
        A[i] = S[i] ^ '0';
        B[n - i - 1] = A[i];
    }

    for (int i = 0; i < N; i++) {
        X[i] = ei(2 * pi * i / N);
    }

    FFT(A);
    FFT(B);

    for (int i = 0; i < N; i++) {
        C[i] = A[i] * B[i];
        X[i] = conj(X[i]);
    }

    FFT(C);

    for (int i = n; i < (n << 1) - 1; i++) {
        cout << rnd(C[i].r() / (double)N) << " ";
    }
    cout << endl;
    return 0;
}