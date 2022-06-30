#include <bits/stdc++.h>
using namespace std;
#define int long long int 

struct Node {
    int aval, pval, mval, sval;
    Node* lc;
    Node* rc;

    Node(): aval(0), pval(0), mval(0), sval(0) {}
    Node(int w, int x, int y, int z): aval(w), pval(x), mval(y), sval(z) {}
};

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l], a[l], a[l], a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->aval = ptr->lc->aval + ptr->rc->aval;
    ptr->pval = max(ptr->lc->pval, ptr->lc->aval + ptr->rc->pval);
    ptr->mval = max({ptr->lc->sval + ptr->rc->pval, ptr->lc->mval, ptr->rc->mval});
    ptr->sval = max(ptr->rc->sval, ptr->rc->aval + ptr->lc->sval);
    return ptr;
}

// int query (Node* ptr, int ql, int qr, int l, int r) {
//     if (l >= ql && r <= qr) {
//         return ptr->val;
//     }
//     if (r <= ql || l >= qr) {
//         return 0;
//     }
    
//     int mid = (l + r) / 2;
//     int x1 = query(ptr->lc, ql, qr, l, mid);
//     int x2 = query(ptr->rc, ql, qr, mid, r);
//     return max(x1, x2);
// }

void update (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->aval = ptr->pval = ptr->mval = ptr->sval = b;
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, a, b, l, mid);
    update(ptr->rc, a, b, mid, r);

    ptr->aval = ptr->lc->aval + ptr->rc->aval;
    ptr->pval = max(ptr->lc->pval, ptr->lc->aval + ptr->rc->pval);
    ptr->mval = max({ptr->lc->sval + ptr->rc->pval, ptr->lc->mval, ptr->rc->mval});
    ptr->sval = max(ptr->rc->sval, ptr->rc->aval + ptr->lc->sval);
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
        int k, x;
        cin >> k >> x;
        k--;
        update(tree, k, x, 0, n);
        cout << max(0ll, tree->mval) << endl;
    }
    return 0;
}