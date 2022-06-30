#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
    int s;
    int m;
    int tag;
    Node* lc;
    Node* rc;

    Node(): x(0) {}
    Node(int x): x(x) {}
};

Node* build (vector<int> &a, int l, int r) {
    if (l == r) {
        return new Node(a[l]);
    }

    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid + 1, r);

    ptr->x = (ptr->lc->x + ptr->rc->x);
    return ptr;
}

void pull (Node* ptr) {
    ptr->s = ptr->lc->s + ptr->rc->s;
    ptr->m = max(ptr->lc->m, ptr->rc->m);
}

void push (Node* ptr, int l, int r) {
    if (!ptr->tag) {
        return;
    }

    int mid = (l + r) / 2;
    ptr->lc->s = (mid - l + 1) * ptr->tag;
    ptr->rc->s = (r - mid) * ptr->tag;
    ptr->lc->m = ptr->rc->m = ptr->tag;
    ptr->lc->tag = ptr->rc->tag = ptr->tag;
    ptr->tag = 0;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (l != r) {
        push(ptr, l, r);
    }
    if (ql <= l && qr >= r) {
        return ptr->s - ptr->x;
    }

    int mid = (l + r) / 2;
    return query(ptr->lc, ql, qr, l, mid) + query(ptr->rc, ql, qr, mid + 1, r);
}

void update(Node* ptr, int ql, int qr, int v, int l, int r) {
    if (ql > r || qr < l) {
        return;
    }
    if (l != r) {
        push(ptr, l, r);
    }
    if (ql <= l && qr >= r) {
        ptr->s = (r - l + 1) * v;
        ptr->m = v;
        ptr->tag = v;
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, ql, qr, v, l, mid);
    update(ptr->rc, ql, qr, v, mid + 1, r);
    
    pull(ptr);
}

int find (Node* ptr, int v, int l, int r) {
    if (l == r) {
        return l;
    }

    push(ptr, l, r);

    int mid = (l + r) / 2;
    if (ptr->lc->m >= v) {
        return find(ptr->lc, v, l, mid);
    } else if (ptr->rc->m >= v) {
        return find(ptr->rc, v, mid + 1, r);
    } else {
        return r + 1;
    }
}

int main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Node* tree = build(a, 1, n);

    vector<pair<pair<int, int>, int>> range;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        range.push_back({{l, r}, i});
    }
    sort(range.begin(), range.end());

    vector<int> ans(q);
    int p = 0;
    for (int i = n; i > 0; i--) {
        update(tree, i, find(tree, a[i], 1, n) - 1, a[i], 1, n);
        while (range[p].first.first == i) {
            ans[range[p].second] = query(tree, range[p].first.first, range[p].first.second, 1, n);
            p++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}