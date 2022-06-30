#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int val;
    int tag1, tag2;
    Node* lc;
    Node* rc;

    Node(): val(0), tag1(0), tag2(0) {}
    Node(int x, int y, int z): val(x), tag1(y), tag2(z) {}
};

void pull (Node* ptr) {
    ptr->val = (ptr->lc->val + ptr->rc->val);
}

void push(Node* ptr, int l, int r) {
    int mid = (l + r) / 2;
    ptr->lc->val += (mid - l + 1) * (ptr->tag1 + (ptr->tag1 + ptr->tag2 * (mid - l))) / 2;
    ptr->rc->val += (r - mid) * ((ptr->tag1 + ptr->tag2 * (mid + 1 - l)) + (ptr->tag1 + ptr->tag2 * (r - l))) / 2;
    ptr->lc->tag1 += ptr->tag1;
    ptr->rc->tag1 += ptr->tag1 + ptr->tag2 * (mid + 1 - l);
    ptr->lc->tag2 += ptr->tag2;
    ptr->rc->tag2 += ptr->tag2;
    ptr->tag1 = ptr->tag2 = 0;
}

Node* build (vector<int> &a, int l, int r) {
    if (r == l) {
        return new Node(a[l], 0, 0);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid + 1, r);

    pull(ptr);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (r < ql || l > qr) {
        return 0;
    }
    if (l != r) {
        push(ptr, l, r);
    }
    if (l >= ql && r <= qr) {
        return ptr->val;
    }

    int mid = (l + r) / 2;
    int x1 = query(ptr->lc, ql, qr, l, mid);
    int x2 = query(ptr->rc, ql, qr, mid + 1, r);
    return (x1 + x2);
}

void update (Node* ptr, int ql, int qr, int v, int l, int r) {
    if (r < ql || l > qr) {
        return;
    }
    if (r != l) {
        push(ptr, l, r);
    }
    if (l >= ql && r <= qr) {
        ptr->val += (r - l + 1) * (v + (v + (r - l))) / 2;
        ptr->tag1 = v;
        ptr->tag2 = 1;
        return;
    }
    
    int mid = (l + r) / 2;
    update(ptr->lc, ql, qr, v, l, mid);
    update(ptr->rc, ql, qr, v + max(0ll, (mid + 1 - max(ql, l))), mid + 1, r);

    pull(ptr);
}

// void printList (Node *head) {
//     if (head == nullptr) return;
//     cout << head->val << ":";
//     cout << (head->tag.empty() ? 0 : head->tag.front()) << ":";
//     cout << head->left << "-" << head->right << " ";
//     printList(head->lc);
//     printList(head->rc);
// }

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 1, n);

    // printList(tree);
    // cout << endl;

    for (int i = 0; i < q; i++) {
        int u, a, b;
        cin >> u >> a >> b;
        if (u == 1) {
            update(tree, a, b, 1, 1, n);
        } 
        if (u == 2) {
            cout << query(tree, a, b, 1, n) << endl;
        }
    }
    // printList(tree);
    // cout << endl;
    return 0;
}