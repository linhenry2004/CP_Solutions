#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct treap {
    int val, man, siz, pri;
    bool rev;
    treap *lc, *rc;

    treap (int v) {
        val = man = v;
        siz = 1;
        pri = rand();
        rev = 0;
        lc = rc = nullptr;
    }

    void pull () {
        man = min(min(lc ? lc->man : inf, rc ? rc->man : inf), val);
        siz = (lc ? lc->siz : 0) + (rc ? rc->siz : 0) + 1;
    }

    void push () {
        if (!rev) {
            return;
        }
        swap(lc, rc);
        if (lc) {
            lc->rev ^= 1;
        }
        if (rc) {
            rc->rev ^= 1;
        }
        rev = 0;
    }

    int find (int k) {
        push();
        int ls = (lc ? lc->siz : 0) + 1;
        if (val == k) {
            return ls;
        }
        if (lc && lc->man == k) {
            return lc->find(k);
        } else {
            return rc->find(k) + ls;
        }
    }
};

vector<pair<int, int>> ans;

int size (treap *t) {
    return t ? t->siz : 0;
}

treap* merge (treap *a, treap *b) {
    if (!a || !b) {
        return a ? a : b;
    }
    if (a->pri > b->pri) {
        a->push();
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->lc = merge(a, b->lc);
        b->pull();
        return b;
    }
}

void split (treap *t, treap *&a, treap *&b, int k) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    t->push();
    if (k <= size(t->lc)) {
        b = t;
        split(t->lc, a, b->lc, k);
        b->pull();
    } else {
        a = t;
        split(t->rc, a->rc, b, k - size(t->lc) - 1);
        a->pull();
    }
}

int main () {
    srand(time(NULL));
    int n, x, p;
    treap *t = nullptr, *a = nullptr, *b = nullptr, *c = nullptr;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t = merge(t, new treap(x));
    }
    for (int i = 1; i <= n; i++) {
        split(t, a, b, i - 1);
        p = b->find(i);
        if (p == 1) {
            t = merge(a, b);
            continue;
        }
        ans.push_back({i, i + p - 1});
        split(b, b, c, p);
        b->rev ^= 1;
        t = merge(a, merge(b, c));
    }

    cout << ans.size() << endl;
    for (auto [l, r] : ans) {
        cout << l << " " << r << endl;
    }
    return 0;
}