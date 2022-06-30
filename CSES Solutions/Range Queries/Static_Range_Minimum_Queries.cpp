#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

struct Node {
    int val;
    Node* lc;
    Node* rc;

    Node(): val(INF) {}
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

    ptr->val = min(ptr->lc->val, ptr->rc->val);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->val;
    }
    if (r <= ql || l >= qr) {
        return INF;
    }
    
    int mid = (l + r) / 2;
    int x1 = query(ptr->lc, ql, qr, l, mid);
    int x2 = query(ptr->rc, ql, qr, mid, r);
    return min(x1, x2);
}

int main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 0, n);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << query(tree, l, r, 0, n) << endl;
    }
    return 0;
}