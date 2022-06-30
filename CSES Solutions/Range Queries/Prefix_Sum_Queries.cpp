#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int sval, pval;
    Node* lc;
    Node* rc;

    Node(): sval(0), pval(0) {}
    Node(int x, int y): sval(x), pval(y) {}
};

// void print (Node* ptr, int l, int r) {
//     if (r - l == 1) {
//         cout << ptr->sval << " ";
//         return;
//     }

//     int mid = (l + r) / 2;
//     print(ptr->lc, l, mid);
//     print(ptr->rc, mid, r);
//     return;
// }

pair<int, int> query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return {ptr->pval, ptr->sval};
    }
    if (r <= ql || l >= qr) {
        return {0, 0};
    }
    
    int mid = (l + r) / 2;
    pair<int, int> x1 = query(ptr->lc, ql, qr, l, mid);
    pair<int, int> x2 = query(ptr->rc, ql, qr, mid, r);
    return {max(x1.first, x1.second + x2.first), x1.second + x2.second};
}

void update (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->sval = ptr->pval = b;
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, a, b, l, mid);
    update(ptr->rc, a, b, mid, r);
    ptr->sval = (ptr->lc->sval + ptr->rc->sval);
    ptr->pval = max(ptr->lc->sval + ptr->rc->pval, ptr->lc->pval);
}

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l], a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->sval = (ptr->lc->sval + ptr->rc->sval);
    ptr->pval = max(ptr->lc->sval + ptr->rc->pval, ptr->lc->pval);
    return ptr;
}

int32_t main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 0, n);
    // print(tree, 0, n);
    // cout << endl;

    for (int i = 0; i < q; i++) {
        int t, k, u;
        cin >> t >> k >> u;
        k--;
        if (t == 1) {
            update(tree, k, u, 0, n);
        } else if (t == 2) {
            cout << max(0ll, query(tree, k, u, 0, n).first) << endl;
        }
    }
    return 0;
}