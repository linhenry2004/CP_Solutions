#include <bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc ((p << 1) | 1)

const int maxn = 2e5 + 1;
int mix[4 * maxn], man[4 * maxn], tag[4 * maxn];

void pull (int p) {
    mix[p] = max(mix[lc], mix[rc]);
    man[p] = min(man[lc], man[rc]);
}

void push (int p) {
    mix[lc] += tag[p];
    mix[rc] += tag[p];
    man[lc] += tag[p];
    man[rc] += tag[p];
    tag[lc] += tag[p];
    tag[rc] += tag[p];
    tag[p] = 0;
}

void update (int p, int l, int r, int ql, int qr, int x) {
    if (ql > r || qr < l) {
        return;
    }
    if (ql <= l && qr >= r) {
        mix[p] += x;
        man[p] += x;
        tag[p] += x;
        return;
    }
    push(p);
    update(lc, l, mid, ql, qr, x);
    update(rc, mid + 1, r, ql, qr, x);
    pull(p);
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        update(1, 1, n, 1, c, 3 - 2 * s);
        if (mix[1] >= 0 && man[1] >= 0) {
            cout << ">" << endl;
        } else if (mix[1] <= 0 && man[1] <= 0) {
            cout << "<" << endl;
        } else {
            cout << "?" << endl;
        }
    }
    return 0;
}