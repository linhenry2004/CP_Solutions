#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int W[maxn][24];

void build (int n) {
    for (int i = 1; i <= n; i++) {
        W[i][0] = max(W[i][0], W[i - 1][0]);
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            W[i][j] = W[W[i][j - 1]][j - 1];
        }
    }
}

int query (int l, int r) {
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
        if (W[r][i] >= l) {
            ans += 1 << i;
            r = W[r][i];
        }
    }
    return ans;
}

int main () {
    int n, q;
    cin >> n >> q;
    while (n--) {
        int l, r;
        cin >> l >> r;
        W[r][0] = max(l, W[r][0]);
    }
    build(1e6);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}