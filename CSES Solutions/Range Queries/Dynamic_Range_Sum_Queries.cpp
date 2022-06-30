#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val;
    Node* lc;
    Node* rc;

    Node(): val(0) {}
    Node(int x): val(x) {}
};

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->val = (ptr->lc->val + ptr->rc->val);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->val;
    }
    if (r <= ql || l >= qr) {
        return 0;
    }
    
    int mid = (l + r) / 2;
    int x1 = query(ptr->lc, ql, qr, l, mid);
    int x2 = query(ptr->rc, ql, qr, mid, r);
    return (x1 + x2);
}

void update (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->val = b;
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, a, b, l, mid);
    update(ptr->rc, a, b, mid, r);
    ptr->val = (ptr->lc->val + ptr->rc->val);
}

int32_t main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 0, n);

    for (int i = 0; i < q; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        a--;
        if (x == 1) {
            update(tree, a, b, 0, n);
        }
        if (x == 2) {
            cout << query(tree, a, b, 0, n) << endl;
        }
    }
    return 0;
}