#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define mid ((l + r) / 2)
#define lc (p << 1)
#define rc ((p << 1) | 1)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 1;
int H[maxn]; 
int F[4 * maxn], B[4 * maxn];

void hashing (int n) {
    H[0] = 1;
    for (int i = 1; i <= n; i++) {
        H[i] = (H[i - 1] * 29) % mod;
    }
}

void pull (int p, int l, int r) {
    F[p] = (F[lc] + H[mid - l + 1] * F[rc]) % mod;
    B[p] = (B[rc] + H[r - mid] * B[lc]) % mod;
}

void update (int p, int c, int x, int l, int r) {
    if (c < l || c > r) {
        return;
    }
    if (l == r) {
        F[p] = B[p] = x;
        return;
    }

    update(lc, c, x, l, mid);
    update(rc, c, x, mid + 1, r);
    pull(p, l, r);
}

int query (int p, int ql, int qr, int l, int r, bool t) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (t) {
        if (ql <= l && qr >= r) {
            return F[p];
        }
        return (query(lc, ql, qr, l, mid, t) + H[max(0ll, mid - max(l, ql) + 1)] * query(rc, ql, qr, mid + 1, r, t)) % mod;
    } else {
        if (ql <= l && qr >= r) {
            return B[p];
        }
        return (query(rc, ql, qr, mid + 1, r, t) + H[max(0ll, min(r, qr) - mid)] * query(lc, ql, qr, l, mid, t)) % mod;
    }
}

int32_t main () {
    int n, q; 
    char x;
    cin >> n >> q;
    hashing(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        update(1, i, x - 'a', 1, n);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            cin >> k >> x;
            update(1, k, x - 'a', 1, n);
        } else {
            int l, r;
            cin >> l >> r;
            cout << (query(1, l, r, 1, n, 1) == query(1, l, r, 1, n, 0) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}