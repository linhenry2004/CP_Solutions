#include <bits/stdc++.h>
using namespace std;

int SG[2001];

int mex (set<int> &S) {
    for (int i = 0; i <= 2000; i++) {
        if (S.find(i) == S.end()) {
            return i;
        }
    }
}

void build (int n) {
    set<int> S;
    for (int i = 1; i <= n; i++) {
        S.clear();
        for (int j = 1; j < i; j++) {
            if (j != i - j) {
                S.insert(SG[i - j] ^ SG[j]);
            }
        }
        SG[i] = mex(S);
    }
}

int main () {
    int t;
    cin >> t;
    build(2000);
    while (t--) {
        int n;
        cin >> n;
        if (n > 2000) {
            cout << "first" << endl;
        } else {
            cout << (SG[n] ? "first" : "second") << endl;
        }
    }
    return 0;
}