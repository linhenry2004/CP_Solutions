#include <bits/stdc++.h>
using namespace std;

struct treap {
    int pri, s;
    char x;
    treap *lc, *rc;

    treap (char c) {
        pri = rand();
        lc = rc = nullptr;
        x = c;
        s = 1;
    }

    void pull () {
        s = (lc ? lc->s : 0) + (rc ? rc->s : 0) + 1;
    }
};

int size (treap *t) {
    return t ? t->s : 0;
}

treap* merge (treap *a, treap *b) {
    if (!a || !b) {
        return (!a ? b : a);
    }

    if (a->pri > b->pri) {
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    } else {
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

    if (size(t->lc) + 1 <= k) {
        a = t;
        split(t->rc, a->rc, b, k - size(t->lc) - 1);
        a->pull();
    } else {
        b = t;
        split(t->lc, a, b->lc, k);
        b->pull();
    }
}

void print (treap *t) {
    if (!t) {
        return;
    }
    print(t->lc);
    cout << t->x;
    print(t->rc);
}

int main () {
    srand(time(NULL));
    int n, q;
    cin >> n >> q;

    treap *t = nullptr, *a = nullptr, *b = nullptr, *c = nullptr;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        t = merge(t, new treap(x));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        split(t, a, b, l - 1);
        split(b, b, c, r - l + 1);
        t = merge(merge(a, c), b);
    }
    
    print(t);
    cout << endl;
    return 0;
}