#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define cpx complex<double>
#define i imag
#define r real

const int maxn = 1 << 19;
const double pi = acos(-1);
array<cpx, 1 << 19> A, B, C, X;

cpx ei (double x) {
    return {cos(x), sin(x)};
}

void FFT (array<cpx, maxn> &F) {
    int n;
    cpx x;
    for (int i = 0, j = 0; i < maxn; i++) {
        if (i > j) {
            swap(F[i], F[j]);
        }
        for (int k = maxn >> 1; (j ^= k) < k; k >>= 1);
    }
    for (int k = 2; k <= maxn; k <<= 1) {
        n = k >> 1;
        for (int j = 0; j < maxn; j += k) {
            for (int i = j; i < j + n; i++) {
                x = X[(i - j) * maxn / k] * F[i + n];
                F[i + n] = F[i] - x;
                F[i] += x;
            }
        }
    }
}

int rnd (double x) {
    double z = (int) x;
    if (x - z >= 0.5) {
        return (int) z + 1;
    } else {
        return (int) z;
    }
}

int32_t main () {
    int n, pre = 0, zero = 0, cnt = 0;
    string S;
    cin >> S;
    n = S.size();
    B[n] = {1, 0};
    for (char s : S) {
        if (s == '1') {
            pre++; 
            zero += cnt * (cnt + 1) / 2;
            cnt = 0;
        } else {
            cnt++;
        }
        A[pre] += 1;
        B[n - pre] += 1;
    }
    zero += cnt * (cnt + 1) / 2;
    for (int i = 0; i < maxn; i++) {
        X[i] = ei(2.0 * pi * i / maxn);
    }
    FFT(A), FFT(B);
    for (int i = 0; i < maxn; i++) {
        C[i] = A[i] * B[i];
        X[i] = conj(X[i]);
    }
    FFT(C);
    cout << zero << " ";
    for (int i = n + 1; i <= 2 * n; i++) {
        cout << rnd(C[i].r() / (double) maxn) << " ";
    }
    cout << endl;
    return 0;
}