#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int val;
    Node *lc, *rc;

    Node () {
        lc = rc = nullptr;
    }

    void pull () {
        val = (lc? lc->val : 0) + (rc? rc->val : 0);
    }

    void build (int l, int r) {
        if (l == r) return;
        lc = new Node;
        rc = new Node;
        int mid = (l + r) / 2;
        lc->build(l, mid);
        rc->build(mid + 1, r);
    }

    Node* update (int c, int x, int l, int r) {
        Node *root = new Node;
        *root = *this;
        if (c < l || c > r) return root;
        if (l == r) {
            root->val = x;
            return root;
        }

        int mid = (l + r) / 2;
        root->lc = lc->update(c, x, l, mid);
        root->rc = rc->update(c, x, mid + 1, r);
        root->pull();
        return root;
    }

    int query (int ql, int qr, int l, int r) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return val;

        int mid = (l + r) / 2;
        return lc->query(ql, qr, l, mid) + rc->query(ql, qr, mid + 1, r);
    }
};

vector<Node*> S;
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, q; 
    cin >> n >> q;

    S.push_back(nullptr);
    S.push_back(new Node);
    S[1]->build(1, n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S[1] = S[1]->update(i, x, 1, n);
    }

    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            int l, x;
            cin >> l >> x;
            S[k] = S[k]->update(l, x, 1, n);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << S[k]->query(l, r, 1, n) << endl;
        } else {
            S.push_back(S[k]);
        }
    }
    return 0;
}