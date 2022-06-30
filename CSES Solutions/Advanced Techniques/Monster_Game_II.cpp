#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)

struct line {
    int a, b;
    int operator + (int x) {
        return a * x + b;
    }
};

const int INF = 1e6;
const int maxn = 2e5 + 1;
const int maxm = 1e6 + 1;
int S[maxn], F[maxn], dp[maxn];
line seg[4 * maxm];

void update (int p, int l, int r, line s) {
    if (s + mid < seg[p] + mid) {
        swap(s, seg[p]);
    }
    if (l == r) {
        return;
    } 
    if (s.a > seg[p].a) {
        update(lc, l, mid, s);
    } else {
        update(rc, mid + 1, r, s);
    }
}

int query (int p, int l, int r, int x) {
    if (l == r) {
        return seg[p] + x;
    }
    if (x <= mid) {
        return min(seg[p] + x, query(lc, l, mid, x));
    } else {
        return min(seg[p] + x, query(rc, mid + 1, r, x));
    }
}

int DP (int n) {
    update(1, 1, INF, {F[0], 0});
    for (int i = 1; i <= n; i++) {
        dp[i] = query(1, 1, INF, S[i]);
        update(1, 1, INF, {F[i], dp[i]});
    }
    return dp[n];
}

int32_t main () {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i < 4 * maxm; i++) {
        seg[i] = {INF, INF};
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> F[i];
    }

    F[0] = x;
    cout << DP(n) << endl;
    return 0;
}