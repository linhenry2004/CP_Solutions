#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
vector<int> g;

struct Node {
    int val;
    Node* lc;
    Node* rc;

    Node(): val(INF) {}
    Node(int x): val(x) {}
};

Node* build (vector<int> &g, int l, int r) {
    if (r - l == 1) {
        return new Node(g[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(g, l, mid);
    ptr->rc = build(g, mid, r);

    ptr->val = max(ptr->lc->val, ptr->rc->val);
    return ptr;
}

int query (Node* ptr, int q, int l, int r) {
    if (r - l == 1) {
        return l;
    }
    
    int mid = (l + r) / 2;
    if (ptr->lc->val >= q) {
        return query(ptr->lc, q, l, mid);
    } else {
        return query(ptr->rc, q, mid, r);
    }
}

void update (Node* ptr, int a, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->val = g[a];
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, a, l, mid);
    update(ptr->rc, a, mid, r);
    ptr->val = max(ptr->lc->val, ptr->rc->val);
}

int main () {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    Node* tree = build(g, 0, n);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x > tree->val) {
            cout << 0 << " ";
        } else {
            int index = query(tree, x, 0, n);
            g[index] -= x;
            update(tree, index, 0, n);
            cout << index + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}