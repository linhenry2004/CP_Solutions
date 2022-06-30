#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int F[maxn];

void build (string T) {
    int p;
    F[0] = -1;
    for (int i = 1; i < T.size(); i++) {
        p = F[i - 1];
        while (~p && T[i] != T[p + 1]) {
            p = F[p];
        }
        if (T[i] == T[p + 1]) {
            p++;
        }
        F[i] = p;
    }
}

int match (string T, string S) {
    int p = -1, cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        while (~p && S[i] != T[p + 1]) {
            p = F[p];
        }
        if (S[i] == T[p + 1]) {
            p++;
        }
        if (p + 1 == T.size()) {
            cnt ++;
            p = F[p];
        }
    }
    return cnt;
}

int main () {
    string S, T;
    cin >> S >> T;
    build(T);
    cout << match(T, S) << endl;
    return 0;
}