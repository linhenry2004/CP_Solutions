#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
char C[4] = {'A', 'C', 'G', 'T'};
int nxt[4][maxn];

void build (string &DNA) {
    int n = DNA.size();
    for (int i = 0; i < 4; i++) {
        nxt[i][n] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (DNA[i] == C[j]) {
                nxt[j][i] = i;
            } else {
                nxt[j][i] = nxt[j][i + 1];
            }
        }
    }
}

void print (string &DNA) {
    int n = DNA.size(), p, now = 0;
    char c;
    for (int i = 0; i < n; i++) {
        p = 0;
        for (int j = 0; j < 4; j++) {
            if (nxt[j][now] > p) {
                p = nxt[j][now];
                c = C[j];
            }
        }
        cout << c;
        now = p + 1;
        if (now > n) {
            return;
        }
    }
}

int main () {
    string DNA;
    cin >> DNA;
    build(DNA);
    print(DNA);
    cout << endl;
    return 0;
}