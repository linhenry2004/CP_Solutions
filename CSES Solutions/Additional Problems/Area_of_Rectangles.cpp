#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)

struct ooo {
    int x, l, r, v;
};

const int inf = 1e6;
const int maxn = 8e6 + 1;
int man[maxn], tag[maxn], cnt[maxn];
vector<ooo> Q;

bool cmp (ooo a, ooo b) {
    return a.x < b.x;
}

void pull (int p) {
    man[p] = min(man[lc], man[rc]);
    if (man[lc] < man[rc]) {
        cnt[p] = cnt[lc];
    } else if (man[rc] < man[lc]) {
        cnt[p] = cnt[rc];
    } else {
        cnt[p] = cnt[lc] + cnt[rc];
    }
}

void push (int p) {
    man[lc] += tag[p];
    man[rc] += tag[p];
    tag[lc] += tag[p];
    tag[rc] += tag[p];
    tag[p] = 0;
}

void build (int p, int l, int r) {
    if (l == r) {
        cnt[p] = 1;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pull(p);
}

void update (int p, int l, int r, int ql, int qr, int x) {
    if (ql > r || qr < l) {
        return;
    }
    if (ql <= l && qr >= r) {
        man[p] += x;
        tag[p] += x;
        return;
    }
    push(p);
    update(lc, l, mid, ql, qr, x);
    update(rc, mid + 1, r, ql, qr, x);
    pull(p);
}

int32_t main () {
    int n, x1, y1, x2, y2, p = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        Q.push_back({x1, y1, y2 - 1, 1});
        Q.push_back({x2, y1, y2 - 1, -1});
    }
    sort(Q.begin(), Q.end(), cmp);
    build(1, -inf, inf);
    for (int i = -inf; i < inf; i++) {
        while (p < Q.size() && Q[p].x == i) {
            auto [x, l, r, v] = Q[p++];
            update(1, -inf, inf, l, r, v);
        }
        sum += 2 * inf + 1 - cnt[1];
    }
    cout << sum << endl;
    return 0;
}