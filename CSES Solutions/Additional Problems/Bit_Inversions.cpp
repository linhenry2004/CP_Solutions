#include <bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)

const int maxn = 2e5 + 1;
int seg[2][4 * maxn], pre[2][4 * maxn], suf[2][4 * maxn], all[2][4 * maxn];

void pull (int p, int l, int r) {
    for (int i : {0, 1}) {
        all[i][p] = all[i][lc] & all[i][rc];
        if (all[i][p]) {
            pre[i][p] = suf[i][p] = seg[i][p] = r - l + 1;
            continue;
        }
        if (all[i][lc]) {
            pre[i][p] = (mid - l + 1) + pre[i][rc];
        } else {
            pre[i][p] = pre[i][lc];
        }
        if (all[i][rc]) {
            suf[i][p] = (r - mid) + suf[i][lc];
        } else {
            suf[i][p] = suf[i][rc];
        }
        seg[i][p] = max({seg[i][lc], seg[i][rc], pre[i][p], suf[i][p], suf[i][lc] + pre[i][rc]});
    }
}

void update (int p, int l, int r, int c, int x) {
    if (c > r || c < l) {
        return;
    }
    if (l == r) {
        seg[x][p] = pre[x][p] = suf[x][p] = all[x][p] = 1;
        seg[x ^ 1][p] = pre[x ^ 1][p] = suf[x ^ 1][p] = all[x ^ 1][p] = 0;
        return;
    }
    update(lc, l, mid, c, x);
    update(rc, mid + 1, r, c, x);
    pull(p, l, r);
}

int main () {
    int n, q, p;
    string S;
    cin >> S;
    n = S.size();
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, i, S[i - 1] ^ 48);
    }

    cin >> q;
    while (q--) {
        cin >> p;
        update(1, 1, n, p, S[p - 1] ^ 49);
        cout << max(seg[0][1], seg[1][1]) << " ";
        S[p - 1] ^= 1;
    }
    cout << endl;
    return 0;
}