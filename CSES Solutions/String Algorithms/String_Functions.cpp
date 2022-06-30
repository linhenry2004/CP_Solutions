#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int Z[maxn], F[maxn];

void ZZZ (string &S) {
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < S.size(); i++) {
        if (i + Z[i - l] < r) {
            Z[i] = Z[i - l];
        } else {
            l = i;
            if (i > r) {
                r = i;
            }
            while (r < S.size() && S[r] == S[r - l]) {
                r++;
            }
            Z[i] = r - l;
        }
    }
}

void KMP (string &S) {
    int p;
    F[0] = -1;
    for (int i = 1; i < S.size(); i++) {
        p = F[i - 1];
        while (~p && S[p + 1] != S[i]) {
            p = F[p];
        }
        if (S[i] == S[p + 1]) {
            p++;
        }
        F[i] = p;
    }
}

int main () {
    string S;
    cin >> S;
    ZZZ(S);
    for (int i = 0; i < S.size(); i++) {
        cout << Z[i] << " ";
    }
    cout << endl;
    KMP(S);
    for (int i = 0; i < S.size(); i++) {
        cout << F[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}