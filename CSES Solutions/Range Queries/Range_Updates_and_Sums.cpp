#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val;
    int tag;
    int tag2;
    int size;
    Node* lc;
    Node* rc;

    Node(): val(0), tag(0), tag2(0) {}
    Node(int x, int y): val(x), tag(0), tag2(0), size(y) {}

    int getSum () {
        return val + (tag * size) + (tag2 * size);
    }
};

void pull (Node* ptr) {
    ptr->val = (ptr->lc->getSum() + ptr->rc->getSum());
}

void push(Node* ptr) {
    if (ptr->tag2) {
        ptr->lc->val = 0;
        ptr->rc->val = 0;
        ptr->lc->tag = 0;
        ptr->rc->tag = 0;
        ptr->lc->tag2 = ptr->tag2;
        ptr->rc->tag2 = ptr->tag2;
        ptr->tag2 = 0;
    }
    ptr->lc->tag += ptr->tag;
    ptr->rc->tag += ptr->tag;
    ptr->tag = 0;
}

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l], 1);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->size = r - l;
    ptr->val = (ptr->lc->val + ptr->rc->val);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->getSum();
    }
    if (r <= ql || l >= qr) {
        return 0;
    }
    
    push(ptr);

    int mid = (l + r) / 2;
    int x1 = query(ptr->lc, ql, qr, l, mid);
    int x2 = query(ptr->rc, ql, qr, mid, r);
    
    pull(ptr);
    return (x1 + x2);
}

void update (Node* ptr, int a, int b, int x, int l, int r) {
    if (l >= a && r <= b) {
        ptr->tag += x;
        return;
    }
    if (r <= a || l >= b) {
        return;
    }

    push(ptr);
    
    int mid = (l + r) / 2;
    update(ptr->lc, a, b, x, l, mid);
    update(ptr->rc, a, b, x, mid, r);
    
    pull(ptr);
}

void change (Node* ptr, int a, int b, int x, int l, int r) {
    if (l >= a && r <= b) {
        ptr->val = 0;
        ptr->tag = 0;
        ptr->tag2 = x;
        return;
    }
    if (r <= a || l >= b) {
        return;
    }

    push(ptr);

    int mid = (l + r) / 2;
    change(ptr->lc, a, b, x, l, mid);
    change(ptr->rc, a, b, x, mid, r);

    pull(ptr);
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 0, n);

    for (int i = 0; i < q; i++) {
        int u, a, b;
        cin >> u >> a >> b;
        a--;
        if (u == 1) {
            int x;
            cin >> x;
            update(tree, a, b, x, 0, n);
        } else if (u == 2) {
            int x;
            cin >> x;
            change(tree, a, b, x, 0, n);
        } else if (u == 3) {
            cout << query(tree, a, b, 0, n) << endl;
        }
    }
    return 0;
}