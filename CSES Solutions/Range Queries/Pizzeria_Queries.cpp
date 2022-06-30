#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

struct Node {
    int lval, rval;
    Node* lc;
    Node* rc;

    Node(): lval(INF), rval(INF) {}
    Node(int x, int y): lval(x), rval(y) {}
};

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l], a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->lval = min(ptr->lc->lval, ptr->rc->lval);
    ptr->rval = min(ptr->lc->rval, ptr->rc->rval);
    return ptr;
}

int Lquery (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->lval;
    }
    if (r <= ql || l >= qr) {
        return INF;
    }
    
    int mid = (l + r) / 2;
    int x1 = Lquery(ptr->lc, ql, qr, l, mid);
    int x2 = Lquery(ptr->rc, ql, qr, mid, r);
    return min(x1, x2);
}

int Rquery (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->rval;
    }
    if (r <= ql || l >= qr) {
        return INF;
    }
    
    int mid = (l + r) / 2;
    int x1 = Rquery(ptr->lc, ql, qr, l, mid);
    int x2 = Rquery(ptr->rc, ql, qr, mid, r);
    return min(x1, x2);
}

void Lupdate (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->lval += b;
        return;
    }

    int mid = (l + r) / 2;
    Lupdate(ptr->lc, a, b, l, mid);
    Lupdate(ptr->rc, a, b, mid, r);
    ptr->lval = min(ptr->lc->lval, ptr->rc->lval);
    ptr->rval = min(ptr->lc->rval, ptr->rc->rval);
}

void Rupdate (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->rval += b;
        return;
    }

    int mid = (l + r) / 2;
    Rupdate(ptr->lc, a, b, l, mid);
    Rupdate(ptr->rc, a, b, mid, r);
    ptr->lval = min(ptr->lc->lval, ptr->rc->lval);
    ptr->rval = min(ptr->lc->rval, ptr->rc->rval);
}

int main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 0, n);
    for (int i = 0; i < n; i++) {
        Lupdate(tree, i, i, 0, n);
        Rupdate(tree, i, n - i + 1, 0, n);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            Lupdate(tree, k, x - a[k], 0, n);
            Rupdate(tree, k, x - a[k], 0, n);
            a[k] = x;
        }
        if (t == 2) {
            int k;
            cin >> k;
            k--;
            cout << min(Lquery(tree, k, n, 0, n) - (k), Rquery(tree, 0, k, 0, n) - (n - k + 1)) << endl;
        }
    }
    return 0;
}