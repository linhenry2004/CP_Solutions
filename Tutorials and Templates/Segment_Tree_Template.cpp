#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, tag;
    Node* lc;
    Node* rc;

    Node(): val(0), tag(0) {}
    Node(int x): val(x), tag(0) {}
};

void pull (Node* ptr) {
    ptr->val = ptr->lc->val + ptr->rc->val;
}

void push (Node* ptr, int l, int r) {
    if (!ptr->tag) {
        return;
    }
    ptr->lc->val = ptr->tag; 
    ptr->rc->val = ptr->tag;
    ptr->lc->tag = ptr->tag;
    ptr->rc->tag = ptr->tag;
    ptr->tag = 0;
}

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    pull(ptr);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->val;
    }
    if (r <= ql || l >= qr) {
        return 0;
    }

    push(ptr, l, r);

    int mid = (l + r) / 2;
    return query(ptr->lc, ql, qr, l, mid) + query(ptr->rc, ql, qr, mid, r);
}

void update (Node* ptr, int ql, int qr, int l, int r) {
    if (r <= ql || l > ql) {
        return;
    }
    if (r - l == 1 && l == ql) {
        ptr->val = qr;
        return;
    }
    push(ptr, l, r);
    
    int mid = (l + r) / 2;
    update(ptr->lc, ql, qr, l, mid);
    update(ptr->rc, ql, qr, mid, r);
    
    pull(ptr);
}